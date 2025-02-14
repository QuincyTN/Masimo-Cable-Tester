/*
 * req_res_prototype.c
 *
 * Purpose: Develop request and response protocols for the MCU (AVR128DB48) and HMI (NX4827P043-011C)
 */ 

#define F_CPU 24000000UL
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//HMI Objects
/*
The HMI and GUI is structured by pages and the attributes on it. These range from text fields, numbers, buttons, sliders, and other interactive elements.
The MCU can be used to access values and change them by sending "commands" through the USART. Use the NEXTION Instruction set to find the appropriate
commands.
The definitions below will be used to access relevant attributes and their values from the HMI.
The attribute is in the form of "[page].[ID].[field]" (eg "mcu.n0.val")
*/
#define VAL "val"	//used to get the value attribute of a number
#define TXT "txt"	//used to get the text attribute of a text field

//mcu page and attributes
#define PAGE_MCU "mcu"
#define N0 "n0"
#define N1 "n1"
#define T2 "t2"
#define T3 "t3"

//hmi page and attributes
#define PAGE_HMI "hmi"

//Constant Values
#define BAUDr 9600
#define BUFFER_SIZE 50
#define PRESCALER 1024

//HMI starting return message
#define STRING_MESSAGE 0x70		//message has a string
#define NUM_MESSAGE 0x71		//message is an integer 


//USART2 transmitter and receiver buffer 
char transmitData[BUFFER_SIZE];
uint8_t dataIndexTx = 0;
char receiveData[BUFFER_SIZE];
uint8_t dataIndexRx = 0;

uint8_t hmiReceiving = 0;			//flag for HMI
uint8_t terminalReceiving = 0;		//flag for terminal

//Flags for USART 
uint8_t enable = 0;
uint8_t newHmiMessage = 0;
uint8_t newTerminalMessage = 0;
uint8_t receiveFlag = 0;
uint8_t timerFlag = 0;

//USART3 transmitter and receiver buffer 
char transmitData3[BUFFER_SIZE];
uint8_t dataIndexTx3 = 0;
char receiveData3[BUFFER_SIZE];
uint8_t dataIndexRx3 = 0;

//Buffers for the receiver of the terminal and HMI
char terminalBuffer[BUFFER_SIZE];
char hmiBuffer[BUFFER_SIZE];

void portInit(){
	/*
	Purpose: initialize port and pin directions (as input/output)
	PORTx.DIRSET is the register to set port x's pin directions
	x can be A,B,C,D,E,F with register sizes PA[7:0], PB[5:0], PC[7:0], PD[7:0], PE[3:0], PF[6:0]
	*/
	PORTB.DIRSET = (1<<3);		//set 3rd pin of PORTB to output, LED on board
	PORTB.OUT |= (1<<3);		//turn LED off
}

void initUSART3(){
	//Initialize USART3 in ASynchronous mode with baudrate 9600 
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	PORTMUX.USARTROUTEA &= 0;	//USART3 using PB0 as TxD and PB1 as RxD
	PORTB.DIRSET = (1 << 0);    //Set PB0 as output (TxD)
	PORTB.DIRCLR = (1 << 1);	//Set PB1 as input (RxD)

	USART3.BAUD = BAUDRATE;
	
	//USART3.CTRLC |= (1<<6);		//USART is synchronous, no parity bit, 1 stop bit, 8 char data size
	USART3.CTRLB = (USART_RXEN_bm) | (USART_TXEN_bm); //enable receiver and transmitter
	
	USART3.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt
}

void transmitTerminal(char* str){
	for(int i = 0; i < strlen(str); i++){
		while(!(USART3.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART3.TXDATAL = (char)str[i];		//send new char
	}
	
	while(!(USART3.STATUS & (1<<5)));		//wait until all data in buffer is sent
	USART3.TXDATAL = '\r';
}

void initUSART2(){
	//Initialize USART2 in ASynchronous mode with baudrate 9600
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	PORTMUX.USARTROUTEA = PORTMUX_USART2_ALT1_gc;	//USART2 using PF4 as TxD and PF5 as RxD
	PORTF.DIRSET = (1 << 4);    //Set PF4 as output (TxD)
	PORTF.DIRCLR = (1 << 5);	//Set PF5 as input (RxD)

	USART2.BAUD = BAUDRATE;

	USART2.CTRLB = (USART_RXEN_bm) | (USART_TXEN_bm);	//enable receiver and transmitter

	USART2.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt
}

void transmitHmi(char* page, char* ID, char* field, char* value, uint8_t request){
	/*
	This function will send commands to the HMI. page
	*/
	char command[50];
	int len = 0;

	if(request){	//if the MCU needs a value from HMI (request is 1)
		len = sprintf(command, "get %s.%s.%s%c%c%c", page, ID, field, 0xFF, 0xFF, 0xFF);
	}
	else {		//MCU update text box in HMI
		len = sprintf(command, "%s.%s.txt=\"%s\"%c%c%c", page, ID, value, 0xFF, 0xFF, 0xFF);
	}
	for(int i = 0; i < len; i++){
		while(!(USART2.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART2.TXDATAL = (char)command[i];	//send new char
	}
		
}

void initTimer1s() {
	//Set the period for 1 second
	TCA0.SINGLE.PER = (F_CPU / PRESCALER) - 1; // 23437 for 1s

	//Enable overflow interrupt
	TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;

	//Set prescaler to 1024 and enable timer
	TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1024_gc | TCA_SINGLE_ENABLE_bm;
}

ISR(TCA0_OVF_vect) {
	//get a value every second
	switch((timerFlag++)%4){
		case 0: transmitHmi(PAGE_MCU,N0,VAL,NULL, 1); break;
		case 1: transmitHmi(PAGE_MCU,N1,VAL,NULL, 1); break;
		case 2: transmitHmi(PAGE_MCU,T2,TXT,NULL, 1); break;
		case 3: transmitHmi(PAGE_MCU,T3,TXT,NULL, 1); break;
		default: transmitHmi(PAGE_MCU,N0,VAL,NULL, 1); break;
	}
		
	TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;	//reset overflow flag
}

ISR(USART3_RXC_vect){
	uint8_t data = USART3.RXDATAL;

	if ((data != NULL) && !terminalReceiving) {
		dataIndexRx3 = 0;   //Reset index
		terminalReceiving = 1;      //Start recording message
		memset(receiveData3, 0, sizeof(receiveData3));	//clear buffer before new message
	}

	if (terminalReceiving) {
		receiveData3[dataIndexRx3++] = data;
		if (data == '\r') {
			USART3.CTRLB &= ~USART_RXEN_bm;	//turn off the receiver
			USART3.CTRLA &= ~USART_RXCIE_bm;	//turn off the receive interrupt
			
			receiveData3[dataIndexRx3-1] = '\0';
			terminalReceiving = 0;  //Stop receiving
			dataIndexRx3 = 0;  //Reset buffer index
			newTerminalMessage = 1;
			
			strcpy(terminalBuffer, receiveData3);
			//PORTB.OUTTGL = 1<<3;	//toggle LED
			USART3.CTRLB = USART_RXEN_bm;	//turn off the receiver
			USART3.CTRLA = USART_RXCIE_bm;	//turn off the receive interrupt
		}
	
		//Prevent buffer overflow
		if (dataIndexRx3 >= BUFFER_SIZE) {
			dataIndexRx3 = 0;
			terminalReceiving = 0;
		}
	}
	
}

ISR(USART2_RXC_vect){
	/*
	Interrupt occurs when HMI receives data (a command or action) from USART2 receiver
	*/
	
	uint8_t data = USART2.RXDATAL;

	//Check for start identifiers (0x70 or 0x71)
	if ((data != NULL) && !hmiReceiving) {
		dataIndexRx = 0;   //Reset index
		hmiReceiving = 1;      //Start recording message
		memset(receiveData, 0, sizeof(receiveData));	//clear buffer before new message
	}

	if (hmiReceiving) {
		receiveData[dataIndexRx++] = data;
		if (dataIndexRx >= 3 &&
		receiveData[dataIndexRx - 1] == 0xFF &&
		receiveData[dataIndexRx - 2] == 0xFF &&
		receiveData[dataIndexRx - 3] == 0xFF) {
			
			USART2.CTRLB &= ~USART_RXEN_bm;	//turn off the receiver
			USART2.CTRLA &= ~USART_RXCIE_bm;	//turn off the receive interrupt
			
			
			strcpy(hmiBuffer, receiveData);
			
			hmiReceiving = 0;  //Stop receiving
			dataIndexRx = 0;  //Reset buffer index
			newHmiMessage = 1;
			//PORTB.OUTTGL = 1<<3;	//toggle LED
			USART2.CTRLB = USART_RXEN_bm;	//turn off the receiver
			USART2.CTRLA = USART_RXCIE_bm;	//turn off the receive interrupt
		}
		
		//Prevent buffer overflow
		if (dataIndexRx >= BUFFER_SIZE) {
			dataIndexRx = 0;
			hmiReceiving = 0;
		}
	}
}

void parseHmiData(char* strData){
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
	//uint8_t dataLength = strlen(strData);		//get length of data
	int dataLength = strlen(strData);
	if(strData[0] == STRING_MESSAGE){
		char string[dataLength];
		//for(int i = 1; i <= dataLength-4; i++)
			//hmiBuffer[i-1] = strData[i];	//extract string between 1 and ending 0xFF
		strncpy(string, strData+1, dataLength+1);
			//strcat(string, "\r");
		string[dataLength-4] = "\0";
		transmitTerminal(string);
			//transmitTerminal(strData[i]);
	}
	else if(strData[0] == NUM_MESSAGE){
		char number[BUFFER_SIZE];
		//test
		uint32_t intValue = ((uint32_t)strData[1]) + ((uint32_t)strData[2]*256) + ((uint32_t)strData[3]*65536) + ((uint32_t)strData[4]*16777216);
		sprintf(number, "%lu", intValue);	//convert the integer to a string of characters
		//sprintf("911", %lu, intValue)
		//transmitTerminal(911);
		transmitTerminal(number);
	}
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
}

void parseTerminalData(char* strData){
	//memset(terminalBuffer, 0, sizeof(terminalBuffer));	//clear the terminalBuffer
	//strcpy(terminalBuffer, strData);	//copy data to new buffer
	
	if(strcmp(terminalBuffer, "led on") == 0) {
		PORTB.OUTCLR = PIN3_bm;	//turn on led
	}
	else if(strcmp(terminalBuffer, "led off") == 0) {
		PORTB.OUTSET = PIN3_bm;	//turn off led
	}
}

int main(void)
{
    ccp_write_io(&(CLKCTRL.OSCHFCTRLA),CLKCTRL_FRQSEL_24M_gc);	//set main clock to 24MHz
	portInit();
    initUSART3();	//initialize USART3 to display information received from HMI
    initUSART2();	//initialize USART2 to transmit and receive from HMI
	//initTimer1s();	//initialize 1s timer
    sei();			//turn on global interrupts
	
    while (1) 
    {
		//Display the message on the terminal using USART3
		if(newHmiMessage){
			//parseHmiData(receiveData);	//parse data and store in hmiBuffer
			parseHmiData(hmiBuffer);
			//transmitTerminal(hmiBuffer);	//display data on the terminal
			newHmiMessage = 0;	//reset flag
		}

		if(newTerminalMessage){
			//parseTerminalData(receiveData3);	//parse data
			parseTerminalData(terminalBuffer);
			newTerminalMessage = 0;	//reset flag
		}
    }
}

