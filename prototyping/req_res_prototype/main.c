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
#define PAGE_MCU "mcu"
#define PAGE_HMI "hmi"

#define BAUDr 9600
#define BUFFER_SIZE 50

//USART2 transmitter and receiver buffer 
char transmitData[BUFFER_SIZE];
uint8_t dataIndexTx = 0;
char receiveData[BUFFER_SIZE];
uint8_t dataIndexRx = 0;

uint8_t receiving = 0;		//flag for strings
uint8_t messageType = 0;	//0x71 for strings, 0x70 for ints

//Flags for USART 
uint8_t enable = 0;
uint8_t sendMessage = 0;
uint8_t receiveFlag = 0;

//USART3 transmitter and receiver buffer 
char transmitData3[BUFFER_SIZE];
uint8_t dataIndexTx3 = 0;
char receiveData3[4];
uint8_t dataIndexRx3 = 0;

void port_init(){
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
	//USART3.CTRLB = (USART_RXEN_bm);	//enable receiver
	USART3.CTRLB = (USART_TXEN_bm); //enable transmitter
	
	USART3.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt and transmit complete interrupt, and data register empty interrupt
}

void transmit3(char* ID, char* str){
	char command[50];
	int len = sprintf(command, "%s.txt=\"%s\"%c%c%c\n", ID, str, 0xFF, 0xFF, 0xFF);
			
	for(int i = 0; i < len; i++){
		while(!(USART3.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART3.TXDATAL = (char)command[i];	//send new char
	}
	
	//while(!(USART3.STATUS & (1<<5)));		//wait until all data in buffer is sent
	//USART3.TXDATAL = "\n";
}

void initUSART2(){
	//Initialize USART2 in ASynchronous mode with baudrate 9600
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	PORTMUX.USARTROUTEA = PORTMUX_USART2_ALT1_gc;	//USART2 using PF4 as TxD and PF5 as RxD
	PORTF.DIRSET = (1 << 4);    //Set PF4 as output (TxD)
	PORTF.DIRCLR = (1 << 5);	//Set PF5 as input (RxD)

	USART2.BAUD = BAUDRATE;

	USART2.CTRLB = (USART_RXEN_bm) | (USART_TXEN_bm);	//enable receiver and transmitter

	USART2.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt and transmit complete interrupt, and data register empty interrupt
}

void transmit2(char* page, char* ID, char* str, uint8_t request){
	char command[50];
	int len = 0;

	if(request){	//if the MCU needs a value from HMI
		len = sprintf(command, "get %s.%%c%c%c", page, ID, str, 0xFF, 0xFF, 0xFF);
	}
	else {		//MCU update text box in HMI
		len = sprintf(command, "%s.%s.txt=\"%s\"%c%c%c", page, ID, str, 0xFF, 0xFF, 0xFF);
	}
	for(int i = 0; i < len; i++){
		while(!(USART2.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART2.TXDATAL = (char)command[i];	//send new char
	}
		
}

ISR(USART3_RXC_vect){
	receiveData3[dataIndexRx3] = USART3.RXDATAL;
	dataIndexRx3++;
	
	if(dataIndexRx3 >= 4){
		dataIndexRx3 = 0;
		
		
		if(receiveData3[0] == '1')	//check first byte of message
			enable = 1;
		else
			enable = 0;
		
		PORTB.OUTTGL = 1<<3;
		//transmit3("test", receiveData3);
		//memset(receiveData3, 0, sizeof(receiveData3));
	}
	
	
}

ISR(USART2_RXC_vect){
	/*
	Interrupt occurs when HMI receives data (a command or action)
	*/
	
	uint8_t data = USART2.RXDATAL;

	//Check for start identifiers (0x70 or 0x71)
	if ((data == 0x70 || data == 0x71) && !receiving) {
		dataIndexRx = 0;   //Reset index
		receiving = 1;      //Start recording message
		messageType = data; //Store message type
		memset(receiveData, 0, sizeof(receiveData));	//clear buffer before new message
	}

	if (receiving) {
		receiveData[dataIndexRx++] = data;
		if (dataIndexRx >= 3 &&
		receiveData[dataIndexRx - 1] == 0xFF &&
		receiveData[dataIndexRx - 2] == 0xFF &&
		receiveData[dataIndexRx - 3] == 0xFF) {
			
			receiving = 0;  //Stop receiving
			dataIndexRx = 0;  //Reset buffer index
			sendMessage = 1;	//transmit data received to terminal
			//PORTB.OUTTGL = 1<<3;	//toggle LED
		}
		
		//Prevent buffer overflow
		if (dataIndexRx >= BUFFER_SIZE) {
			dataIndexRx = 0;
			receiving = 0;
		}
	}
}

char* parseUsartStr(char* strData){
	uint8_t newLen = strlen(strData) - 4;	//length of string does not include first or last 3 chars
	char* parsedData = (char*)malloc(newLen + 1);	//allocate space for string
	
	for(int i = 1; i < newLen+1; i++)
		parsedData[i-1] = strData[i];	//extract string between 1 and ending 0xFF
	
	parsedData[newLen] = '\0';	//terminate string
	
	return parsedData;
}

uint32_t convertUsartInt(char* strData){
	uint32_t intValue = ((uint32_t)strData[1]) + ((uint32_t)strData[2]*256) + ((uint32_t)strData[3]*65536) + ((uint32_t)strData[4]*16777216);
	return intValue;
}

int main(void)
{
    ccp_write_io(&(CLKCTRL.OSCHFCTRLA),CLKCTRL_FRQSEL_24M_gc);	//set main clock to 24MHz
	port_init();
    initUSART3();	//initialize USART3 to display information received from HMI
    initUSART2();	//initialize USART2 to transmit and receive from HMI
    sei();			//turn on global interrupts
    
    while (1) 
    {
		if(sendMessage){
			if(messageType == 0x70)
				transmit3("new", parseUsartStr(receiveData));
			else{
				char send[BUFFER_SIZE];
				sprintf(send, "%lu", convertUsartInt(receiveData));
				transmit3("new", send);
			}
			sendMessage = 0;
		}
    }
}

