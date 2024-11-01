/*
 * MCU_GUI_com.c
 *
 * Created: 10/31/2024 1:32:13 PM
 * Purpose: USART communication between MCU (AVR128DB48) and HMI (NX4827P043-011C)
 */ 

#define F_CPU 4000000UL
#include <avr/io.h>
//#include <avr/ioavr128db48.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

#define BAUDr 9600 

void port_init(){
	/*
	Purpose: initialize port and pin directions (as input/output)
	PORTx.DIRSET is the register to set port x's pin directions
	x can be A,B,C,D,E,F with register sizes PA[7:0], PB[5:0], PC[7:0], PD[7:0], PE[3:0], PF[6:0]
	*/
	PORTB.DIRSET |= (1<<3);		//set 3rd pin of PORTB to output, LED on board
}


void initUSART0(){
	
	//Section 27.3.1 in datasheet gives how to setup USART
	//		17.3.3 in datasheet gives how to enable USART pins
	//USART in Synchronous Host mode with baudrate 9600 
	
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr) - 1;	//calculate baudrate
	PORTMUX.USARTROUTEA |= 1<<4;	//USART0 using PF4 as TxD and PF5 as RxD
	
	//not sure if I set the baud rate correctly
	USART2.BAUD = BAUDRATE;
	//USART0_BAUDH = (BAUDRATE & 0b111111111100);	//get upper 8 bits of BAUDRATE	
	//USART0_BAUDL = (BAUDRATE & 0b11) << 6;	//get lower 2 bits of BAUDRATE
	
	//USART2_CTRLC |= (1<<6);		//USART is synchronous, no parity bit, 1 stop bit, 8 char data size
	USART2.CTRLB |= (1<<7) | (1<<6);	//enable receiver and transmitter
	
	USART2.CTRLA |= (1<<7) | (1<<6);	//enable receive complete interrupt and transmit complete interrupt 
}



void transmit0(char* ID, char* str){
	char command[50];
	int len = sprintf(command, "%s.txt=\"%s\"", ID, str);
			PORTB.OUT |= (1<<3);	//turn LED on
			_delay_ms(500);
			
	for(int i = 0; i < len; i++){
		while(!(USART2.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART2.TXDATAL = command[i];	//send new char
	}
	
	for(int i = 0; i < 3; i++){
		while(!(USART2.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART2.TXDATAL = 0xFF;	//send terminating string
	}
	
PORTB.OUT &= ~(1<<3);	//turn LED off
_delay_ms(500);
}

/*
ISR (){
	//TODO
	//event when USART0 transmit finishes
}
*/

int main(void)
{
	port_init();
	initUSART0();
	
	char data[50];
	
	uint8_t counter = 0;
    while (1) 
    {

		sprintf(data, "%d", counter);
		
		transmit0("t0", data);
		
		counter = (counter+1)%100;

    }
}

