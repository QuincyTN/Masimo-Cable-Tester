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

char transmitData[50];
uint8_t dataIndexTx = 0;
char receiveData[4];
uint8_t dataIndexRx = 0;

uint8_t enable = 0;

char transmitData3[50];
uint8_t dataIndexTx3 = 0;
char receiveData3[4];
uint8_t dataIndexRx3 = 0;

uint8_t receiveFlag = 0;

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
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	//uint16_t BAUDRATE = F_CPU / (2UL * BAUDr);	//synchronous baudrate calc
	PORTMUX.USARTROUTEA &= 0;	//USART3 using PB0 as TxD and PB1 as RxD
	PORTB.DIRSET = (1 << 0);    //Set PB0 as output (TxD)
	PORTB.DIRCLR = (1 << 1);	//Set PB1 as input (RxD)

	//not sure if I set the baud rate correctly
	USART3.BAUD = BAUDRATE;
	//USART0.BAUDH = (BAUDRATE & 0b111111111100);	//get upper 8 bits of BAUDRATE	
	//USART0.BAUDL = (BAUDRATE & 0b11) << 6;	//get lower 2 bits of BAUDRATE
	
	//USART3.CTRLC |= (1<<6);		//USART is synchronous, no parity bit, 1 stop bit, 8 char data size
	USART3.CTRLB = (USART_RXEN_bm) | (USART_TXEN_bm);	//enable receiver and transmitter
	//USART3.CTRLB = (USART_TXEN_bm);
	
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
	
	//Section 27.3.1 in datasheet gives how to setup USART
	//		  17.3.3 in datasheet gives how to enable USART pins
	//USART in ASynchronous mode with baudrate 9600
	
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	//uint16_t BAUDRATE = F_CPU / (2UL * BAUDr);	//synchronous baudrate calc
	PORTMUX.USARTROUTEA = PORTMUX_USART2_ALT1_gc;	//USART2 using PF4 as TxD and PF5 as RxD
	PORTF.DIRSET = (1 << 4);    //Set PF4 as output (TxD)
	PORTF.DIRCLR = (1 << 5);	//Set PF5 as input (RxD)

	USART2.BAUD = BAUDRATE;

	USART2.CTRLB = (USART_RXEN_bm) | (USART_TXEN_bm);	//enable receiver and transmitter
	//USART2.CTRLB = (USART_RXEN_bm);
	USART2.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt and transmit complete interrupt, and data register empty interrupt

}

void transmit2(char* ID, char* str){
	char command[50];
	int len = sprintf(command, "%s.txt=\"%s\"%c%c%c", ID, str, 0xFF, 0xFF, 0xFF);
		
	for(int i = 0; i < len; i++){
		while(!(USART2.STATUS & (1<<5)));	//wait until all data in buffer is sent
		USART2.TXDATAL = (char)command[i];	//send new char
	}
}

ISR(USART3_DRE_vect) {
	/*
	Send data using USART3
	The interrupt is enable only after the transmit3() function
	*/	
	if (transmitData3[dataIndexTx3] != NULL) {         //Check if more data to send
		USART3.TXDATAL = transmitData3[dataIndexTx3];  //Send next character
		dataIndexTx3++;                               //Move to next character
	} 
	else {
		USART3.CTRLA &= ~(1 << USART_DREIE_bp);      //Disable DRE interrupt when done
		dataIndexTx3 = 0;                             //Reset index for next transmission
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
	
	/*
	char bufData = USART3.RXDATAL;
	receiveData[0] = bufData;
	if(receiveData[0] == '1')
		enable = 1;
	else
		enable = 0;

	PORTB.OUTTGL = 1<<3;
	*/
	
	
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

ISR(USART2_DRE_vect) {
	/*
	Send data to the HMI using USART2
	The interrupt is enable only after the transmit2() function
	*/	
	if (transmitData[dataIndexTx] != NULL) {         //Check if more data to send
		USART2.TXDATAL = transmitData[dataIndexTx];  //Send next character
		dataIndexTx++;                               //Move to next character
	} 
	else {
		USART2.CTRLA &= ~(1 << USART_DREIE_bp);      //Disable DRE interrupt when done
		dataIndexTx = 0;                             //Reset index for next transmission
	}
}

ISR(USART2_RXC_vect){
	/*
	Interrupt occurs when HMI receives data (a command or action)
	*/
	
	//char test[10];
	//char data = USART2.RXDATAL;
	//sprintf(test, "%c", data);
	//transmit2("t1", test);
	
	//PORTB.OUT |= (1<<3);	//turn LED off

	/*
	char bufData = USART2.RXDATAL;
	receiveData[0] = bufData;
	if(receiveData[0] == '1')
		enable = 1;
	else
		enable = 0;
	*/
	//char buffer[10];
	//sprintf(buffer, "%c", bufData);
	//transmit3("test", buffer);
	//PORTB.OUT |= (1<<3);	//turn LED off
	
	receiveData[dataIndexRx] = USART2.RXDATAL;
	dataIndexRx++;

	if(dataIndexRx >= 4){
		PORTB.OUTTGL = 1<<3;
		dataIndexRx = 0;
		
		if(receiveData[0] == '1')	//check first byte of message
			enable = 1;
		else
			enable = 0;
			
		
		receiveFlag = 1;
		
		//sprintf(data, "%c", test);
		//transmit3("test", receiveData);
		//memset(receiveData, 0, sizeof(receiveData));
	}


	/*
	    // Store received data
	    receiveData[dataIndexRx] = USART2.RXDATAL;
	    dataIndexRx++;

	    // Check for end of message (three consecutive 0xFF bytes)
	    if (dataIndexRx >= 4 &&
	    receiveData[dataIndexRx - 1] == 0xFF &&
	    receiveData[dataIndexRx - 2] == 0xFF &&
	    receiveData[dataIndexRx - 3] == 0xFF) {
		    
		    // Process the message (e.g., check command byte)
		    if (receiveData[0] == '1') {
			    enable = 1;
			    } else {
			    enable = 0;
		    }

		    // Debug: Toggle LED and transmit received data
		    //PORTB.OUTCLR = PIN3_bm; // Toggle LED
			PORTB.OUTSET = PIN3_bm;
		    //transmit3("test", receiveData3); // Debug transmit

		    // Reset buffer and index
		    memset(receiveData, 0, sizeof(receiveData));
		    dataIndexRx = 0;
	    }
		*/
}

char receiver3(){
	while(!(USART3.STATUS & USART_RXCIF_bm));
	char a = USART3.RXDATAL;
	
	if(a == '1')
		enable = 1;
	else
		enable = 0;
	
	return a;
}

void receiver2(){
	for(int i = 0; i < 4; i++){
		while(!(USART2.STATUS & USART_RXCIF_bm));
		receiveData[i] = USART2.RXDATAL;
	}

	
	/*
	if(a == '1')
		enable = 1;
	else
		enable = 0;
	*/
	

}

int main(void)
{
	ccp_write_io(&(CLKCTRL.OSCHFCTRLA),CLKCTRL_FRQSEL_24M_gc);	//set main clock to 24MHz
	port_init();	//initialize ports
	initUSART3();	//initialize USART3
	initUSART2();	//initialize USART2
	sei();			//turn on global interrupts
	char data[50];
	
	//PORTB.OUT &= ~(1<<3);	//turn LED on
	PORTB.OUTCLR = PIN3_bm;
	//PORTB.OUTSET = PIN3_bm;
	
	uint8_t counter = 0;
	enable = 1;
    while (1) 
    {
		if(enable){
			sprintf(data, "%d", counter);
			
			transmit3("t0", data);
			//transmit3("test", receiveData);
			
			//transmit3("test", receiveData);
			counter = (counter+1)%100;
			//_delay_ms(1000);
		}
		
		if(receiveFlag == 1){
			//	transmit3("success", "11");
			receiveFlag = 0;
		}
		//receiver3();
		//char test = receiver2();
		//sprintf(data, "%c", test);
		//receiver2();
		//char nice[4];
		//strcpy(nice, receiveData);
		//transmit3("test", receiveData);
    }
}

