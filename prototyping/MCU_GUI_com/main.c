/*
 * MCU_GUI_com.c
 *
 * Created: 10/31/2024 1:32:13 PM
 * Purpose: USART communication between MCU (AVR128DB48) and HMI (NX4827P043-011C)
 */ 

#define F_CPU 24000000UL
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#define BAUDr 9600 

volatile char transmitData[50];
volatile uint8_t dataIndexTx = 0;
volatile char receiveData[4];
volatile uint8_t dataIndexRx = 0;

volatile uint8_t enable = 0;

volatile char test[1];

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
	
	//Section 27.3.1 in datasheet gives how to setup USART
	//		  17.3.3 in datasheet gives how to enable USART pins
	//USART in ASynchronous mode with baudrate 9600 
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate baudrate
	//uint16_t BAUDRATE = F_CPU / (2UL * BAUDr);	//synchronous baudrate calc
	PORTMUX.USARTROUTEA &= 0;	//USART3 using PB0 as TxD and PB1 as RxD
	PORTB.DIRSET = (1 << 0);    //Set PB0 as output (TxD)
	//PORTB.DIRCLR = (1 << 1);	//Set PB1 as input (RxD)

	//not sure if I set the baud rate correctly
	USART3.BAUD = BAUDRATE;
	//USART0.BAUDH = (BAUDRATE & 0b111111111100);	//get upper 8 bits of BAUDRATE	
	//USART0.BAUDL = (BAUDRATE & 0b11) << 6;	//get lower 2 bits of BAUDRATE
	
	//USART3.CTRLC |= (1<<6);		//USART is synchronous, no parity bit, 1 stop bit, 8 char data size
	USART3.CTRLB |= (1<<7) | (1<<6);	//enable receiver and transmitter
	
	//USART3.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt and transmit complete interrupt, and data register empty interrupt

}

void transmit3(char* ID, char* str){
	
	sprintf(transmitData, "%s.txt=\"%s\"%c%c%c", ID, str, 0xFF, 0xFF, 0xFF);
	USART3.CTRLA = (1 << USART_DREIE_bp);	//turn on the data empty register interrupt
	
	
	/*
	char command[50];
	int len = sprintf(command, "%s.txt=\"%s\"", ID, str);
	
	//PORTB.OUT |= (1<<3);	//turn LED off
	//_delay_ms(500);
			
	for(int i = 0; i < len; i++){
		while(!(USART3.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART3.TXDATAL = (char)command[i];	//send new char
	}
	
	for(int i = 0; i < 3; i++){
		while(!(USART3.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART3.TXDATAL = (char)0xFF;	//send terminating string
	}
	*/
	//while(!(USART3.STATUS & (1<<5)));	//wait until all data in buffer is sent
	//USART3.TXDATAL = "\n";
	
	//PORTB.OUT &= ~(1<<3);	//turn LED on
	//_delay_ms(500);
}


ISR(USART3_DRE_vect) {
	/*
	Send data to the HMI via USART3
	The interrupt is enable only after the transmit3() function
	*/	
	if (transmitData[dataIndexTx] != NULL) {         //Check if more data to send
		USART3.TXDATAL = transmitData[dataIndexTx];  //Send next character
		dataIndexTx++;                               //Move to next character
	} 
	else {
		USART3.CTRLA &= ~(1 << USART_DREIE_bp);      //Disable DRE interrupt when done
		dataIndexTx = 0;                             //Reset index for next transmission
	}
}

ISR(USART3_RXC_vect){
	/*
	Interrupt occurs when HMI receives data (a command or action)
	*/
	
	/*
	test[0] = USART3.RXDATAL;
	transmit3("hi", test);
	*/
	
	receiveData[dataIndexRx] = USART3.RXDATAL;
	
	dataIndexRx++;
	if(dataIndexRx >= 4){
		dataIndexRx = 0;
		
		if(receiveData[0] == '1')	//check first byte of message
			enable = 1;
		else
			enable = 0;
	}
}

char receiver3(){
	while(!(USART3.STATUS & USART_RXCIF_bm));
	char a = USART3.RXDATAL;
	return a;
}

int main(void)
{
	ccp_write_io(&(CLKCTRL.OSCHFCTRLA),CLKCTRL_FRQSEL_24M_gc);	//set main clock to 24MHz
	port_init();	//initialize ports
	initUSART3();	//initialize USART3
	sei();	//turn on global interrupts
	char data[50];
	
	uint8_t counter = 0;
	char receivedByte = '1';
	enable = 1;
    while (1) 
    {
		if(enable){
			sprintf(data, "%d", counter);
			
			transmit3("t0", data);
			//transmit3("hi", &receivedByte);
			counter = (counter+1)%100;
			_delay_ms(1000);
		}
		//receivedByte = receiver3();

    }
}

