#include "hmi_mcu_com.h"

void initUSART1(){
	//Initialize USART1 in ASynchronous mode with baudrate 9600
		
	uint16_t BAUDRATE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	//PORTMUX.USARTROUTEA = PORTMUX_USART2_ALT1_gc;	//USART2 using PF4 as TxD and PF5 as RxD
	PORTMUX.USARTROUTEA = PORTMUX_USART1_DEFAULT_gc;
	
	//PORTF.DIRSET = (1 << 4);    //Set PF4 as output (TxD)
	//PORTF.DIRCLR = (1 << 5);	//Set PF5 as input (RxD)
	
	PORTC.DIRSET = PIN0_bm;		//SET PC0 as output (Tx1)
	PORTC.DIRCLR = PIN1_bm;		//set PC1 as input (Rx1)

	USART1.BAUD = BAUDRATE;

	USART1.CTRLB = (USART_RXEN_bm) | (USART_TXEN_bm);	//enable receiver and transmitter

	USART1.CTRLA = (USART_RXCIE_bm);	//enable receive complete interrupt
}
void transmitHmi(char* page, char* ID, char* field, char* value, uint8_t action){
	/*
	This function will send commands to the HMI. page
	*/
	char command[BUFFER_SIZE*3];
	int len = 0;
	/*
	if(request){	//if the MCU needs a value from HMI (request is 1)
		len = sprintf(command, "get %s.%s.%s%c%c%c", page, ID, field, 0xFF, 0xFF, 0xFF);
	}
	else {		//MCU update text box in HMI
		//len = sprintf(command, "%s.%s.txt=\"%s\"%c%c%c", page, ID, value, 0xFF, 0xFF, 0xFF);
		int my_int = atoi(value);
		len = sprintf(command, "%s.%s.val=%d%c%c%c", page, ID, my_int, 0xFF, 0xFF, 0xFF);
	}
	*/

	
	if(action == 1){//if the MCU needs a value from HMI (request is 1)
		len = sprintf(command, "get %s.%s.%s%c%c%c", page, ID, field, 0xFF, 0xFF, 0xFF);
	}
	else if(action == 2){//if the MCU update text box in HMI
		len = sprintf(command, "%s.%s.txt=\"%s\"%c%c%c", page, ID, value, 0xFF, 0xFF, 0xFF);
	}
	else if(action == 3){ //if the MCU update number value in HMI
		int my_int = atoi(value);
		len = sprintf(command, "%s.%s.val=%d%c%c%c", page, ID, my_int, 0xFF, 0xFF, 0xFF);
	}
	else if(action == 4){//if the MCU needs to go to another page
		len = sprintf(command, "page %s%c%c%c", page, 0xFF, 0xFF, 0xFF);
	}
	else if(action == 5){//if the MCU needs a value from a HMI variable
		len = sprintf(command, "get %s%c%c%c", ID, 0xFF, 0xFF, 0xFF);
	}
	
	for(int i = 0; i < len; i++){
		while(!(USART1.STATUS & (USART_DREIF_bm)));	//wait until all data in buffer is sent
		USART1.TXDATAL = (char)command[i];	//send new char
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

	if(strData[0] == STRING_MESSAGE){
		//char string[dataLength];
		//strncpy(string, strData+1, dataLength+1);
		//string[dataLength-4] = "\0";

		//transmitTerminal(parseHmiString(strData));
	}
	else if(strData[0] == NUM_MESSAGE){
		char number[BUFFER_SIZE];
		//uint32_t intValue = ((uint32_t)strData[1]) | ((uint32_t)strData[2]<<8) | ((uint32_t)strData[3]<<16) | ((uint32_t)strData[4]<<24);
		
		uint32_t intValue = parseHmiInt(strData);


		sprintf(number, "%lu", intValue);	//convert the integer to a string of characters
		//transmitTerminal(number);
		
	}
	else if(strData[0] == START_CHAR){
		//TODO: add characterization function
		//TODO: after characterization, change page to char_success 
		/*
		//Sets ADC to inputs
		for (int i = 0; i < NUM_PINS; i++) {
			setADCInput(i);
		}
			
		for (int i = 0; i < NUM_PINS; i++) {
			setInput(i);
		}

		//Characterizes all pin pairs
		//ADC0.CTRLB = 0x1; //Gets 8 samples
		for (int i = 0; i < NUM_PINS; i++) {
			for (int j = 0; j < NUM_PINS; j++) {
				if(i!=j){
					characterize(i, j);
				}
			}
		}
		
		//SD_characterization();
		
		transmitHmi(PAGE_CHAR_SUCCESS, NULL, NULL, NULL, 4);	// display characterization success screen
		transmitHmi(PAGE_HOME, "t7", NULL, "OK", 2);	// characterization available, set requirement on HMI 
		*/
		newCharacterization = 1;
		
	}
	else if(strData[0] == START_TEST){
		newCharacterization = 0;
		testingPause = 0;
		lastSdWrite = 0;
		faultDetected = 0;
		
		char temp[100];
		sprintf(temp, "%0.2lu/%0.2lu/%0.4lu %0.2lu:%0.2lu:%0.2lu", month, day, year, hour, minute, second);
		transmitHmi(PAGE_TESTING, START_TIME_TXT, NULL, temp, 2);
		testingStart = 1;
// 		sprintf(temp, "%lu, %s", rate, rate_unit);
// 		transmitHmi(PAGE_TESTING, "t4", NULL, temp, 2);
	}
	else if(strData[0] == STOP_TEST){
		testingStart = 0;
		testingPause = 0;
		lastSdWrite = 0;	// reset last written values
		faultDetected = 0;	// reset flag, no fault is detected
	}
	else if(strData[0] == PAUSE_TEST){
		//testingStart = 1;
		testingPause = 1;
	}
	else if(strData[0] == UNPAUSE_TEST){
		testingPause = 0;
	}
	else if(strData[0] == UPDATE_RATE){
		rate = parseHmiInt(strData);
		convertRate(); //update the rate in seconds
	}
	else if(strData[0] == UPDATE_RATE_UNIT){
		strcpy(rate_unit, parseHmiString(strData));
		convertRate(); //update the rate in seconds
	}
	else if(strData[0] == UPDATE_MODE){
		// 0 = Normal mode
		// 1 = Bypass mode
		mode = parseHmiInt(strData);
	}
	
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
}

void getTime(){
	// update local MCU time with RTC from HMI
	updateTime = 1;
	uint32_t var = updateTime;
	for(int i = 0; i < 6; i++){
		
		char rtcID[BUFFER_SIZE]; 
		//sprintf(rtcID, "func: %lu", updateTime);	//convert the integer to a string of characters
		//transmitTerminal(rtcID);
		
		sprintf(rtcID, "rtc%d", i);	
		transmitHmi(NULL, rtcID, NULL, NULL, 5);	//request rtc values from HMI
		
		while (!newHmiMessage);  // wait until flag is set by ISR

		if(hmiBuffer[0] == NUM_MESSAGE){
			uint32_t val = parseHmiInt(hmiBuffer);  // get value from buffer

			switch(updateTime){
				case 1: year = val; break;
				case 2: month = val; break;
				case 3: day = val; break;
				case 4: hour = val; break;
				case 5: minute = val; break;
				case 6: second = val; break;
				default: break;
			}
		}
		newHmiMessage = 0;
		updateTime++;
	}
	updateTime = 0;
}

void convertRate(){
	// Convert rate and rate units into total number of seconds (minimum of 1 second)
	
	if(strcmp(rate_unit, "/sec") == 0){
		updateRateInS = (uint32_t)ceil(1.0f / rate);	
	}
	else if(strcmp(rate_unit, "/min") == 0){
		updateRateInS = (uint32_t)ceil(60.0f / rate);	
	}
	else{
		updateRateInS = (uint32_t)ceil(3600.0f / rate);
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

ISR(USART1_RXC_vect){
	/*
	Interrupt occurs when HMI receives data (a command or action) from USART1 receiver
	*/
	
	uint8_t data = USART1.RXDATAL;

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
			
			USART1.CTRLB &= ~USART_RXEN_bm;	//turn off the receiver
			USART1.CTRLA &= ~USART_RXCIE_bm;	//turn off the receive interrupt
			
			memset(hmiBuffer, 0, sizeof(hmiBuffer));	//reset buffer
			strcpy(hmiBuffer, receiveData);			//copy data into buffer
			
			hmiReceiving = 0;  //Stop receiving
			dataIndexRx = 0;  //Reset buffer index
			newHmiMessage = 1;	//set flag in main

			USART1.CTRLB |= USART_RXEN_bm;	//turn on the receiver
			USART1.CTRLA |= USART_RXCIE_bm;	//turn on the receive interrupt
		}
		
		//Prevent buffer overflow
		if (dataIndexRx >= BUFFER_SIZE) {
			dataIndexRx = 0;
			hmiReceiving = 0;
			newHmiMessage = 1;
		}
	}
}

ISR(TCA0_OVF_vect) {
	// Update time
	//Leap year logic
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	else
		daysInMonth[2] = 28;
	
	second++;	//increment seconds
	
	if(second >= 60){
		minute++;
		second = 0;
	}
	if(minute >= 60){
		hour++;
		minute = 0;
	}
	if(hour >= 24){
		day++;
		hour = 0;
	}
	if(day >= daysInMonth[month]){
		month++;
		day = 1;
	}
	if(month >= 12){
		year++;
		month = 1;
	}
	
	// Sync time with HMI RTC every 15 minutes
	lastTimeUpdate++;
	if (lastTimeUpdate >= 900) {
		getTime();
		lastTimeUpdate = 0;
	}
	
	if(testingStart && !testingPause)
		lastSdWrite++;
	
	if(lastSdWrite >= updateRateInS){
		//write testing values into sd card
// 		PORTG.OUTSET = PIN0_bm;	// set relay if there is a fault
// 		_delay_ms(200);
// 		PORTG.OUTCLR = PIN0_bm;
// 		_delay_ms(200);
		
		lastSdWrite = 0;
	}
	
	
	TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;	//reset overflow flag
}