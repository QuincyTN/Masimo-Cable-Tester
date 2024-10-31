/*
 * MCU_GUI_com.c
 *
 * Created: 10/31/2024 1:32:13 PM
 * Purpose: USART communication between MCU (AVR128DB48) and HMI (NX4827P043-011C)
 */ 

#define F_CPU 24000000UL
#include <avr/io.h>
//#include <avr/ioavr128db48.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <string.h>

#define BAUD 9600 

void initUSART0(){
	/*
	Section 27.3.1 in datasheet gives how to setup USART
			17.3.3 in datasheet gives how to enable USART pins
	USART in Synchronous Host mode with baudrate 9600
	*/
	
	uint32_t BAUDRATE = F_CPU / (2 * BAUD);	//calculate baudrate
	PORTMUX.USARTROUTEA &= 0;	//USART0 using PA0 as TxD and PA1 as RxD
	
	//not sure if I set the baud rate correctly
	USART0_BAUDH = (BAUDRATE & 0b111111111100);	//get upper 8 bits of BAUDRATE	
	USART0_BAUDL = (BAUDRATE & 0b11) << 6;	//get lower 2 bits of BAUDRATE
	
	USART0_CTRLC |= (1<<6);		//USART is synchronous, no parity bit, 1 stop bit, 8 char data size
	USART0_CTRLB |= (1<<7) | (1<<6);	//enable receiver and transmitter
	
	USART0_CTRLA |= (1<<7) | (1<<6);	//enable receive complete interrupt and transmit complete interrupt 
}

void transmit0(){
	//TODO
}

ISR (){
	//TODO
	//event when USART0 transmit finishes
}


int main(void)
{
	initUSART0();
	
	
    while (1) 
    {
    }
}

