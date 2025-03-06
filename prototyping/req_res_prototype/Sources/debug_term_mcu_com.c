#include "../Headers/debug_term_mcu_com.h"

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
		while(!(USART3.STATUS & (USART_DREIF_bm)));	//wait until all data in buffer is sent
		USART3.TXDATAL = (char)str[i];		//send new char
	}
	
	while(!(USART3.STATUS & (USART_DREIF_bm)));		//wait until all data in buffer is sent
	USART3.TXDATAL = '\r';
}
void parseTerminalData(char* strData){
	if(strcmp(terminalBuffer, "led on") == 0) {
		PORTB.OUTCLR = PIN3_bm;	//turn on led
	}
	else if(strcmp(terminalBuffer, "led off") == 0) {
		PORTB.OUTSET = PIN3_bm;	//turn off led
	}
	else if(strcmp(terminalBuffer, "help") == 0) {
		transmitTerminal(helpMenu);	//display help menu
	}
	else if(strcmp(terminalBuffer, "settings") == 0) {
		char settings[100];
		sprintf(settings, "Recording Rate: %lu %s\nMode: %lu", rate, rate_unit, mode);
		transmitTerminal(settings);	//display test settings
	}
	else if(strcmp(terminalBuffer, "get time") == 0) {
		//TODO: display local time
	}
	else if(strcmp(terminalBuffer, "char done") == 0) {
		//Simulate a successful characterization
		transmitHmi(PAGE_CHAR_FAIL, NULL, NULL, NULL, 4);
	}
	
	//TODO: add more commands to test MCU functions
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
			newTerminalMessage = 1;	//set flag in main
			
			memset(terminalBuffer, 0, sizeof(terminalBuffer));	//reset buffer
			strcpy(terminalBuffer, receiveData3);	//copy data into buffer

			USART3.CTRLB |= USART_RXEN_bm;	//turn on the receiver
			USART3.CTRLA |= USART_RXCIE_bm;	//turn on the receive interrupt
		}
		
		//Prevent buffer overflow
		if (dataIndexRx3 >= BUFFER_SIZE) {
			dataIndexRx3 = 0;
			terminalReceiving = 0;
			newTerminalMessage = 1;
		}
	}
	
}