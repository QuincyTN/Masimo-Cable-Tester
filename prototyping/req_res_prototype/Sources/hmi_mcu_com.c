#include "../Headers/hmi_mcu_com.h"

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
		//len = sprintf(command, "%s.%s.txt=\"%s\"%c%c%c", page, ID, value, 0xFF, 0xFF, 0xFF);
		int my_int = atoi(value);
		len = sprintf(command, "%s.%s.val=%d%c%c%c", page, ID, my_int, 0xFF, 0xFF, 0xFF);
	}
	for(int i = 0; i < len; i++){
		while(!(USART2.STATUS & (USART_DREIF_bm)));	//wait until all data in buffer is sent
		USART2.TXDATAL = (char)command[i];	//send new char
	}
}
char* parseHmiString(char* string){
	//Return a string in the format of STRING_MESSAGE
	int dataLength = strlen(string);
	char* parsedStr = (char*)malloc(dataLength - 3);
	strncpy(parsedStr, string+1, dataLength+1);
	parsedStr[dataLength-4] = '\0';
	
	return parsedStr;	
}
uint32_t parseHmiInt(char* string){
	//Return a 32 integer number in the format of NUM_MESSAGE
	return ((uint32_t)string[1]) | ((uint32_t)string[2]<<8) | ((uint32_t)string[3]<<16) | ((uint32_t)string[4]<<24);
}
void parseHmiData(char* strData){
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
	//uint8_t dataLength = strlen(strData);		//get length of data
	//int dataLength = strlen(strData);
	if(strData[0] == STRING_MESSAGE){
		//char string[dataLength];
		//strncpy(string, strData+1, dataLength+1);
		//string[dataLength-4] = "\0";

		transmitTerminal(parseHmiString(strData));
	}
	else if(strData[0] == NUM_MESSAGE){
		char number[BUFFER_SIZE];
		//uint32_t intValue = ((uint32_t)strData[1]) | ((uint32_t)strData[2]<<8) | ((uint32_t)strData[3]<<16) | ((uint32_t)strData[4]<<24);
		sprintf(number, "%lu", parseHmiInt(strData));	//convert the integer to a string of characters
		transmitTerminal(number);
	}
	else if(strData[0] == START_CHAR){
		//TODO: add characterization function
		//TODO: after characterization, change page to char_success 
	}
	else if(strData[0] == START_TEST){
		testingStart = 1;
	}
	else if(strData[0] == STOP_TEST){
		testingStart = 0;
	}
	else if(strData[0] == PAUSE_TEST){
		testingStart = 0;
		
	}
	else if(strData[0] == UPDATE_RATE){
		rate = parseHmiInt(strData);
	}
	else if(strData[0] == UPDATE_RATE_UNIT){
		strcpy(rate_unit, parseHmiString(strData));
	}
	else if(strData[0] == UPDATE_MODE){
		mode = parseHmiInt(strData);
	}
	
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
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
			
			memset(hmiBuffer, 0, sizeof(hmiBuffer));	//reset buffer
			strcpy(hmiBuffer, receiveData);			//copy data into buffer
			
			hmiReceiving = 0;  //Stop receiving
			dataIndexRx = 0;  //Reset buffer index
			newHmiMessage = 1;	//set flag in main

			USART2.CTRLB |= USART_RXEN_bm;	//turn on the receiver
			USART2.CTRLA |= USART_RXCIE_bm;	//turn on the receive interrupt
		}
		
		//Prevent buffer overflow
		if (dataIndexRx >= BUFFER_SIZE) {
			dataIndexRx = 0;
			hmiReceiving = 0;
			newHmiMessage = 1;
		}
	}
}