





/* ****************************  UART defines & declarations ********************** */
// defines for the UART
//#define BAUDRATE 115200 								// define baud
#define BAUDRATE 9600    								// define baud
#define BAUD_PRESCALE (F_CPU*64)/(BAUDRATE*16UL)		// set baud rate prescaler; F_CPU must be defined first
#define RX_BUF_MAX 32									// max size for serial receive buffer
#define MAX_HEX	4										// max hex digits to convert to string


/*  defines for the CDC debug port on an AVR128DA48 Curiosity Nano
 * note that you cannot use this port as an external serial port if using the on-board
 * debugger.  If you move debugging to an external debugger (e.g., Atmel ICE) and don't
 * power up the Curiosity Nano through the debug USB connector, then this port can be used
 * as an external serial port (the on-board debugger is tri-stated.)
#define DB_USART	USART1		// debugger UART for an AVR128DA48 Curiosity Nano 
#define DB_PORT		PORTC		// debugger UART port for an AVR128DA48 Curiosity Nano
#define TX_PIN		PIN0_bm		// TX pin for the AVR128DAxx USART1
#define TX_PIN		PIN1_bm		// TX pin for the AVR128DAxx USART1
#define DB_USART_RXC_vect	USART1_RXC_vect	// RX interrupt vector for an AVR128DAxx USART1
*/

/* defines for CDC debug port on an AVR128DB48 Curiosity Nano 
 * note that you cannot use this port as an external serial port if using the on-board
 * debugger.  If you move debugging to an external debugger (e.g., Atmel ICE) and don't
 * power up the Curiosity Nano through the debug USB connector, then this port can be used 
 * as an external serial port (the on-board debugger is tri-stated.) 
 */
#define DB_USART	USART3		// debugger UART for an AVR128DB48 Curiosity Nano 
#define DB_PORT		PORTB		// debugger UART port for an AVR128DB48 Curiosity Nano
#define TX_PIN		PIN0_bm		// TX pin for the AVR128DBxx USART3
#define RX_PIN		PIN1_bm		// RX pin for the AVR128DAxx USART3
#define DB_USART_RXC_vect	USART3_RXC_vect	// RX interrupt vector for an AVR128DBxx USART3


/* defines for USART2 on an AVR128DB48 Curiosity Nano   
// USART2 for the short-break detector will be used for the HMI. 
// It is also used to emulate stand-alone terminal debug instead of the CDC port for the proof-of-concept board 
#define DB_USART	USART2		// USART2 for an AVR128DB48 Curiosity Nano 
#define DB_PORT		PORTF		// USART2 port for an AVR128DB48 Curiosity Nano
#define TX_PIN		PIN4_bm		// TX pin for the AVR128DBxx USART2
#define RX_PIN		PIN5_bm		// RX pin for the AVR128DBxx USART2
#define DB_USART_RXC_vect	USART2_RXC_vect	// RX interrupt vector for an AVR128DBxx USART2
*/

/* defines for the HMI USART   */
#define HMI_USART		USART2		// map USART to to alternate pin locations 
#define HMI_USART_PINS	0x01<<4		// default is TX on PF0, RX on PF1; move to TX on PF4, RX on PF5
									
#include "utils.h"

// UART global declarations; the functions appear after main()
void uart_init(void);		// default is 9600 baud, 8 bits, 1 stop bit, no parity, no handshake protocol
char uart_receive(void);
ISR(USART0_RX_vect);
void uart_transmit (char data);
void enable_rx1(void);
void uart_send(char data[]);
void UART_sendString(char data[]);
void UART_sendStringn(char data[]);
void STRING_hextoa(uint16_t hex_num, char s[]);
void UART_sendString(char s[]);
void UART_sendHex8(uint8_t hex_num);
void UART_sendHex16(uint16_t hex_num);
void UART_sendInt(INT_SIZE number);
/* ********************** end of UART defines & declarations ********************** */