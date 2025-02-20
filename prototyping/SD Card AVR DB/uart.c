/* ***********************************************************************
 * Simplified UART functions to support SD card usage
 * Author:  Glenn Pohly
 * Date:	6/1/2024 
 * this is a vastly simplified version of the UART functions distributed by Liviu Istrate
 * with his excellent SD Card utilities.  See "fat.c" for his contact info and info on 
 * the SD card utility and the public license.
 *  This software is freely distributed for use as you may see fit.
 */

#include <stdio.h>		
#include <avr/io.h>		// pin defs for the MCU
#include <avr/interrupt.h>

#include "uart.h"		// defines for the UART functions
#include "utils.h"		// string conversion functions


/* variable & constants */
char USART_ReceiveBuffer[RX_BUF_MAX+1];				// Global Buffer, add 1 for null character
char hex_data[MAX_HEX+3];							// max hex digits to convert to string + 3 for '0x" and NULL
bool new_data = false;								// flag set by RX ISR to tell system new data is available
													// must declare hex_data[] and new_data as EXTERN in main
const char hex_array[] = "0123456789ABCDEFx";		// used to convert hex numbers to a string


/* ******************************************************************************
   ********************  start of UART functions  *******************************
   ******************************************************************************/

//function to initialize UART
void uart_init (void)
{
	// USART1 on an AVR128DA48.  TX is pin PC0, RX PC1 
	// USART3 on an AVR128DB48.  TX is pin PB0, RX is PB1
	// USART2 on an AVR128DB48 Curiosity Nano needs to be moved to an alternate pin config
	DB_USART.BAUD = BAUD_PRESCALE;				// set baud rate
	DB_USART.CTRLC |= USART_CHSIZE_8BIT_gc;		// 8bit data format
	DB_PORT.DIR	 |= TX_PIN;						// set TX pin as output
	DB_USART.CTRLB |= USART_TXEN_bm;			// enable transmitter
	DB_USART.CTRLA |= USART_RXCIE_bm;			// enable receiver interrupt
	DB_USART.CTRLB |= USART_RXEN_bm;			// enable receiver
	sei();										// enable global interrupts
}

/*  Function to receive a character from UART */
char uart_receive ()
{
	while ( !( DB_USART.STATUS & USART_RXCIF_bm) );		// wait for data in the receive buffer
	return DB_USART.RXDATAL;							// return received data
}

// RX ISR to receive a line of data
ISR(DB_USART_RXC_vect)
{
	uint8_t i = 0;
	char new_char;
	
	// can only get here if a char was received in the RX buffer
	do{
		new_char = uart_receive();
		USART_ReceiveBuffer[i++] = new_char;
	  }  while(new_char != '\r' && i < RX_BUF_MAX);
	USART_ReceiveBuffer[--i] = '\0';			// replace \r with null
	// if(i == RX_BUF_MAX)
	//	USART_ReceiveBuffer[--i] = '\r';		// received data too long for buffer, force a newline
	DB_USART.CTRLB &= ~USART_RXEN_bm;				// disable receiver (prevents buffer overrun)
	DB_USART.CTRLA &= ~USART_RXCIE_bm;			// disable receiver interrupt
	DB_USART.RXDATAL = 0;                         // clear RX data register in case of overrun
	// no new data can be received until buffer is read and RX and RX INT are re-enabled.
	
	new_data = true;							// Tell system data is available
}


/*  Function to send one char of a string char out UART  */
void uart_transmit (char data) {
	while (!( DB_USART.STATUS & USART_DREIF_bm));     // busy loop; until register is free
	DB_USART.TXDATAL = data;							// load data in the register
}

/* Function to transmit a string of data.  String MUST end in a NULL  */
void uart_send(char data[]){
	int i = 0;
	do {
		uart_transmit(data[i]);
	} while(data[i++] != '\0');
}

/* Function to transmit a string of data.  String MUST end in a NULL  */
void UART_sendString(char s[]){
	int i = 0;
	do {
		uart_transmit(s[i]);
	} while(s[i++] != '\0');
}

/* Function to transmit a string of data.  String MUST end in a NULL.  Adds a newline char at end  */
void UART_sendStringn(char s[]){
	int i = 0;
	do {
		uart_transmit(s[i]);
	} while(s[i++] != '\0');
	uart_transmit('\n');
}

/* function to re-enable RX after a received buffer has been read  */
void enable_rx1(void) {
	/* prepare the receive buffer to get more data. 
	* **** DO NOT RE-ENABLE RX *** until you have saved the recieved data if needed!
	* re-enabling will allow the RX to immediately over-write the receive data buffer. */
	new_data = false;	// clear new data flag
	DB_USART.CTRLA |= USART_RXCIE_bm;			// enable receiver interrupt
	DB_USART.CTRLB |= USART_RXEN_bm;			// enable receiver
} 
				
/* function to format an 8-bit number into ASCII hex format string and send */
void UART_sendHex8(uint8_t hex_num){
	uint8_t temp_num;
	
	hex_data[0] = hex_array[0];
	hex_data[1] = hex_array[16];
	temp_num = hex_num >> 4;
	hex_data[2] = hex_array[temp_num];
	temp_num = hex_num & 0x0F;
	hex_data[3] = hex_array[temp_num];
	hex_data[4] = '\0';
	UART_sendString(hex_data);
}

/* function to format a 16-bit number into ASCII hex format string and send */
void UART_sendHex16(uint16_t hex_num){
	uint16_t temp_num;
	
	hex_data[0] = hex_array[0];
	hex_data[1] = hex_array[16];
	temp_num = hex_num >> 12;
	hex_data[2] = hex_array[temp_num];
	temp_num = hex_num >> 8 & 0x000F;
	hex_data[3] = hex_array[temp_num];
	temp_num = hex_num >> 4 & 0x000F;
	hex_data[4] = hex_array[temp_num];
	temp_num = hex_num & 0x0F;
	hex_data[5] = hex_array[temp_num];
	hex_data[6] = '\0';
	UART_sendString(hex_data);
}


void STRING_hextoa(uint16_t hex_num, char s[]){
	// assumes an int size hex num.
	uint16_t	temp_num;
	
	s[0] = hex_array[0];
	s[1] = hex_array[16];
	temp_num = hex_num >> 12;
	s[2] = hex_array[temp_num];
	temp_num = hex_num >> 8 & 0x000F;
	s[3] = hex_array[temp_num];
	temp_num = hex_num >> 4 & 0x000F;
	s[4] = hex_array[temp_num];
	temp_num = hex_num & 0x000F; 
	s[5] = hex_array[temp_num];
	s[6] = '\0';
	}  // end STRING_hextoa

void UART_sendInt(INT_SIZE number){
	char string[MAX_NR_OF_DIGITS + 1] = {0};
	
	STRING_itoa(number, string, 0);
	UART_sendString(string);
}

/* ********************  end of UART functions  ********************************* */
