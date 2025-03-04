/*
 * main.c
 *
 * Created: 6/1/2024 12:01:42 PM
 *  Author: GPohly
 *
 * Porting the SD Card functions written by Liviu Istrate to an AVR128DA48 MCU
 * See file "fact.c" for author contact info, public domain disclaimer, and GNU 
 * open-source license.
 * 
 7/1/2024
 * Discovered that the AVR128DA48 Curiosity Nano has a bug that does not permit diabling
 * the on-board volgate regulator or changing the voltage of the Curiosity Nano.
 * Modified this implementation to use an AVR128DB48 Curiosity Nano instead.  
 *
 * See "AVR_sd.h" for the pins used for the SPI port and Card Detect pins.  Modify if your 
 * SPI implementation uses different pins.
 */
 
// #define F_CPU  16000000 - defined in project file
// Tab Project -> <file name>Properties -> Toolchain -> X8C C Compiler -> Symbols
// Note that CLK_PER is the same as F_CPU; take care to set peripheral 
// prescalers to not exceed their max frequency
// SPI and ADC both need to be scaled down from 16MHz

// #include <xc.h>
#include <avr/io.h>

#include <util/delay.h>
#include <time.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>
#include <avr/cpufunc.h> // needed to write to CCP protected registers
#include <avr/delay.h>
#include <stdlib.h>
#include <avr/io.h>
#include <inttypes.h>
#include <string.h>

#include "utils.h"		// string conversion utilities used to communicate w/ terminal
#include "uart.h"		// sets and uses up the local debug uart for communication w/ terminal
#include "AVR_sd.h"		// low-level SD card functions, including init/using the SPI port
#include "fat.h"		// SD card file functions
// #include "adc.h"		// ADC functions for all the ADC port pins
// #include "detector.h"	// wire pair structure and defines for the short/break detector

// function declarations for functions here in main.c
void clk_init(void);	// MCU clocks initialization
void SD_demo(void);		// gwp 6/12/2024 Demo SD card file functions.  The code has been moved 
						// to after main() for code readability.  Eventually this will be replaced 
						// with the SD card functions needed to support the short/break detector.
void SD_card_read(char input[]);
void SD_card_read_test(char input[]);

//  variable declarations for reading/writing the SD card.  
//  These were moved outside of main when SD demo functions were moved 
//  after main() so they are globally visable to all functions in this file
DIR dir;				// directory object, for writing to the SD card
SD_FILE file;			// file object, for writing to the SD card
uint8_t return_code = 0;
uint16_t dirItems = 0;
	
/* declare the variables used by the USART receive function */
extern bool new_data;				// set by the receive UART interrupt when
									// new data is received from the terminal
extern char USART_ReceiveBuffer[];  // buffer containing received data
char cmd_buffer[RX_BUF_MAX];		// local buffer to copy a received command into

///////////////////////////////////////////// **added start** ///////////////////////////////////////////////////////
#define VAL "val"	//used to get the value attribute of a number
#define TXT "txt"	//used to get the text attribute of a text field

//mcu page and attributes
#define PAGE_MCU "mcu"
#define N0 "n0"
#define N1 "n1"
#define T2 "t2"
#define T3 "t3"

//hmi page and attributes
#define PAGE_HMI "hmi"

//Constant Values
#define BAUDr 9600
#define BUFFER_SIZE 50
#define PRESCALER 1024

//HMI starting return message
#define STRING_MESSAGE 0x70		//message has a string
#define NUM_MESSAGE 0x71		//message is an integer 


//USART2 transmitter and receiver buffer 
char transmitData[BUFFER_SIZE];
uint8_t dataIndexTx = 0;
char receiveData[BUFFER_SIZE];
uint8_t dataIndexRx = 0;

uint8_t hmiReceiving = 0;			//flag for HMI
uint8_t terminalReceiving = 0;		//flag for terminal

//Flags for USART 
uint8_t enable = 0;
uint8_t newHmiMessage = 0;
uint8_t newTerminalMessage = 0;
uint8_t receiveFlag = 0;
uint8_t timerFlag = 0;

//USART3 transmitter and receiver buffer 
char transmitData3[BUFFER_SIZE];
uint8_t dataIndexTx3 = 0;
char receiveData3[BUFFER_SIZE];
uint8_t dataIndexRx3 = 0;

//Buffers for the receiver of the terminal and HMI
char terminalBuffer[BUFFER_SIZE];
char hmiBuffer[BUFFER_SIZE];

const char helpMenu[] =
"Terminal Functions\n"
"__________________________________________________\n"
"led on     - Turns the LED on\n"
"led off    - Turns the LED off\n"
"help       - Display a menu of terminal functions\n"
"get [arg]  - Get data from the MCU page on the HMI\n"
"	- Valid arguments: n0, n1, t2, t3\n";

void portInit(){
	/*
	Purpose: initialize port and pin directions (as input/output)
	PORTx.DIRSET is the register to set port x's pin directions
	x can be A,B,C,D,E,F with register sizes PA[7:0], PB[5:0], PC[7:0], PD[7:0], PE[3:0], PF[6:0]
	*/
	PORTB.DIRSET = (1<<3);		//set 3rd pin of PORTB to output, LED on board
	PORTB.OUT |= (1<<3);		//turn LED off
}

void transmitTerminal(char* str){
	for(int i = 0; i < strlen(str); i++){
		while(!(USART3.STATUS & (USART_DREIF_bm)));	//wait until all data in buffer is sent
		USART3.TXDATAL = (char)str[i];		//send new char
	}
	
	while(!(USART3.STATUS & (USART_DREIF_bm)));		//wait until all data in buffer is sent
	USART3.TXDATAL = '\r';
}

void initUSART2(){
	//Initialize USART2 in ASynchronous mode with baudrate 9600
	
	uint16_t BAUDRATEE = 64UL * F_CPU / (16UL * BAUDr);	//calculate aysynchronous baudrate
	PORTMUX.USARTROUTEA = PORTMUX_USART2_ALT1_gc;	//USART2 using PF4 as TxD and PF5 as RxD
	PORTF.DIRSET = (1 << 4);    //Set PF4 as output (TxD)
	PORTF.DIRCLR = (1 << 5);	//Set PF5 as input (RxD)

	USART2.BAUD = BAUDRATEE;

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

void initTimer1s() {
	//Set the period for 1 second
	TCA0.SINGLE.PER = (F_CPU / PRESCALER) - 1; // 23437 for 1s

	//Enable overflow interrupt
	TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;

	//Set prescaler to 1024 and enable timer
	TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1024_gc | TCA_SINGLE_ENABLE_bm;
}

ISR(TCA0_OVF_vect) {
	//get a value every second
	switch((timerFlag++)%4){
		case 0: transmitHmi(PAGE_MCU,N0,VAL,NULL, 1); break;
		case 1: transmitHmi(PAGE_MCU,N1,VAL,NULL, 1); break;
		case 2: transmitHmi(PAGE_MCU,T2,TXT,NULL, 1); break;
		case 3: transmitHmi(PAGE_MCU,T3,TXT,NULL, 1); break;
		default: transmitHmi(PAGE_MCU,N0,VAL,NULL, 1); break;
	}
		
	TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;	//reset overflow flag
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

void parseHmiData(char* strData){
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
	//uint8_t dataLength = strlen(strData);		//get length of data
	int dataLength = strlen(strData);
	if(strData[0] == STRING_MESSAGE){
		char string[dataLength];
		strncpy(string, strData+1, dataLength+1);
		string[dataLength-4] = "\0";
		transmitTerminal(string);
	}
	else if(strData[0] == NUM_MESSAGE){
		char number[BUFFER_SIZE];
		uint32_t intValue = ((uint32_t)strData[1]) | ((uint32_t)strData[2]<<8) | ((uint32_t)strData[3]<<16) | ((uint32_t)strData[4]<<24);
		sprintf(number, "%lu", intValue);	//convert the integer to a string of characters
		transmitTerminal(number);
	}
	//memset(hmiBuffer, 0, sizeof(hmiBuffer));	//clear the hmiBuffer
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
	else if(strcmp(terminalBuffer, "get n0") == 0) {
		transmitHmi(PAGE_MCU,N0,VAL,NULL, 1);	//get n0.val value
	}
	else if(strcmp(terminalBuffer, "get n1") == 0) {
		transmitHmi(PAGE_MCU,N1,VAL,NULL, 1);	//get n1.val value
	}
	else if(strcmp(terminalBuffer, "get t2") == 0) {
		transmitHmi(PAGE_MCU,T2,TXT,NULL, 1);	//get t2.txt text
	}
	else if(strcmp(terminalBuffer, "get t3") == 0) {
		transmitHmi(PAGE_MCU,T3,TXT,NULL, 1);	//get t3.txt text
	}
}


////////////////////////////////////**added end**////////////////////////////////////////////////////////////////////



/* ***************************************************************************	 
   ********************************** main ***********************************
   *************************************************************************** */
int main(void)
{	
	volatile bool CARD_IN = false;		// variables for determining state of the SD card insertion
    volatile bool CARD_OUT = false;

	portInit();
	clk_init();			// sets up main and peripheral clocks
	uart_init();		// sets up UART 3 - 115200 baud, 1 stop bit,  no parity, no flow control
	initUSART2();

	UART_sendString("\n\n");	// reset terminal lines
	
	while(1){  // main loop  
	//transmitHmi("page0", "c0", NULL, "1", 0);

    SD_demo();			// call the SD card initialization/file write demo functions.
						// this will be replaced by the SD card functions to support the 
						// short/break detector.  Functions follow main.
		
	//if(return_code==1) {					      // makes sure the requirement is not checked off if
	//	transmitHmi("page0", "c0", NULL, "0", 0); // there was a mounting error
	//}
	
	//if(FAT_getFileSize(&file) >= 10) {
	//	transmitHmi("page0", "c0", NULL, "1", 0);
	//}

	//transmitHmi("page0", "c0", NULL, "0", 0);
    while (1){  // inner loop.  Only broken out of back to main loop if the 
				// SD card has been removed and re-inserted
		
		//UART_sendString("Testing delay...\n");	// debug to see delay is working properly
		 //_delay_ms(1000);						    // execute this loop approximately once per second
		
		if(sd_detected()){
			
			if (!CARD_IN){
				UART_sendString("Card connected\n");
				CARD_IN = true;
				//transmitHmi("page0", "c0", NULL, "1", 0); // changes requirement to true since sd card was inserted
				
				
				if (CARD_OUT)   // can only get here if SD card was inserted, removed, and reinserted
					{
						CARD_OUT = false;
						//transmitHmi("page0", "c0", NULL, "1", 0);
						break;  // returns to checking for an SD Card
					}
				CARD_OUT = false;
				}
			}
		else{
			if(!CARD_OUT) {
				//transmitHmi("page0", "c0", NULL, "0", 0); // changed requirement to false since sd card was removed
				UART_sendString("Card disconnected\n");
				CARD_OUT = true;
				CARD_IN = false;
				}
			} // end of card has been read and is in place
			/*
			if(new_data){  // data has been received from the keyboard
				// copy the received string into a local buffer and re-enable the receiver
				copy_data((uint8_t *)cmd_buffer,(uint8_t *)USART_ReceiveBuffer,strlen(USART_ReceiveBuffer)+1);	// add 1 to count to copy the null character
				enable_rx1();	// re-enables RX to get more data from terminal
				// DO NOT RE-ENABLE until you have saved the received data into a different buffer if needed!

				// option to echo the received data back to the terminal, comment out this line if echo to terminal is not desired
				//FAT_fwriteString(&file, cmd_buffer);
				UART_sendStringn(cmd_buffer);	
				
				SD_card_read(cmd_buffer);
				//SD_card_read_test(cmd_buffer);
				
				
				//FAT_fwriteFloat(&file, -30.004, 3);
	
				// parse the receive data here if you want to command special functions
				// do this by comparing the data in the cmd_buffer with string values
				//if (strcmp(cmd_buffer, "testsd") == 0) {
				//	SD_demo();		// run the SD demo again w/o changing state of the SD card
					//SD_card_read(cmd_buffer);
				//	}
				
			}	// end of new data received from terminal 
			*/
			
		}	// only breaks out if card inserted state has changed
			// returns to initializing and reading the SD card
    }	// end of outer while loop in main()
}	// ********************************  end of main()  ******************************************

/* ******************************************************************************
   ****************************  clock intialization   **************************
   **************************************************************************** */
// initialize main clock if needed, and set prescale for F_CPU/CLK_PER
void clk_init (void)
{
/* AVR128DB64 Curiosity Nano default CPU clock rate is 4MHz, we increase to 16MHz or 24MHz here. 
 * 
 * Note that the peripherals clock rate CLK_PER is equal to F_CPU.  However, many peripherals 
 * will not operate at speeds the CPU can; care must be taken when selecting peripherals to use 
 * the peripheral clock prescalers to bring their clock into data sheet specs.
  * All the clock control registers are protected registers, requiring a write 
 * to the corresponding bit in the CCP register first. This can be done by
 * using the special compiler function "ccp_write_io()"
 */
	// ccp_write_io((void *)&(CLKCTRL.MCLKCTRLB),CLKCTRL_PDIV_2X_gc | CLKCTRL_PEN_bm);	// used to prescale F_CPU and CLK_PER if desired.  Otherwise, leave F_CPU/CLK_PER
																						// at full frequency and use the individual peripheral pre-scalers as needed.
	// ccp_write_io((void *)&(CLKCTRL.MCLKCTRLA),CLKCTRL_CLKOUT_bm);					// output CLK_PER on CLKOUT pin (PA7).  If you don't need to monitor CLK_PER,
																						// don't enable.  Otherwise ties up pin PA7
	ccp_write_io((void *)&(CLKCTRL.OSCHFCTRLA),CLKCTRL_FRQSEL_24M_gc);					// changes CPU CLK to 16MHz.  Note F_CPU = CLK_PER
																						// individual peripherals may need pre-scale settings based on how fast
}																						// clk_main is set.
  

/* ******************************************************************************
   *************************  SD card demo functions   **************************
   **************************************************************************** */

void SD_card_read(char input[]) {
	// Mount the memory card
	return_code = FAT_mountVolume();
	//sprintf(return_code);

	// If no error
		if(return_code == MR_OK){
		UART_sendString("Card mounted.\n");
		
		// Read label and serial number
		char label[12];
		char vol_sn_byte[4];
		uint32_t vol_sn = 0;
		FAT_getLabel(label, &vol_sn);
		
		// Extract serial number
		vol_sn_byte[0] = (vol_sn >> 24) & 0xFF;
		vol_sn_byte[1] = (vol_sn >> 16) & 0xFF;
		vol_sn_byte[2] = (vol_sn >> 8) & 0xFF;
		vol_sn_byte[3] = vol_sn & 0xFF;
		
		
		
		// Make a directory in the root folder
		return_code = FAT_makeDir(&dir, "Logs Folder");
		
		
		// Open the created folder
		return_code = FAT_openDir(&dir, "Logs Folder");
		
		if(return_code == FR_OK){
			// Create a new file in the currently open folder
			return_code = FAT_makeFile(&dir, "log_1.txt");
			
			// Get number of folders and files inside the directory
			dirItems = FAT_dirCountItems(&dir);
			
			// Print folder content
			for(uint16_t i = 0; i < dirItems; i++){
				return_code = FAT_findNext(&dir, &file);
			}
		}else{
			UART_sendString("Could not open folder.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}

		
		//FAT_openDir(&dir, "/");
		//return_code = FAT_fdeleteByName(&dir, "Logging dir");
		//UART_sendString("\nReturn code delete: ");
		//UART_sendInt(return_code);
		//UART_sendString("\n");
			
		// Open a file for reading or writing
		// Open the folder containing the file
		FAT_openDir(&dir, "Logs Folder");
		return_code = FAT_fopen(&dir, &file, "log_1.txt");
			
		if(return_code == FR_OK){
			UART_sendString("\nFile open: ");
			UART_sendString(FAT_getFilename());
			UART_sendString("\n\n");
			
			UART_sendString("File size: ");
			UART_sendInt(FAT_getFileSize(&file));
			UART_sendString("\n");
			
			// Keep only first 10 bytes of the file (example)
			//FAT_fseek(&file, 10);
			//FAT_ftruncate(&file);
			
			// Move the writing pointer to the end of the file
			FAT_fseekEnd(&file);
			
			// Write a string
			FAT_fwriteString(&file, "Logging Date: 2024\n");
			
			FAT_fwriteString(&file, input);
			FAT_fwriteString(&file, "\n");
			// Synchronize the writing buffer with the card
			FAT_fsync(&file);
			
			UART_sendString("File new size: ");
			UART_sendInt(FAT_getFileSize(&file));
			UART_sendString(" bytes.\n");
			
		}else if(return_code == FR_NOT_FOUND){
			// Make the file if it doesn't exist
			// ... code ...
			
			UART_sendString("File could not be found.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}else{
			UART_sendString("File could not be opened.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}
			
	}else{ // end if(return_code == MR_OK)
		UART_sendString("Card not mounted. here0");
		UART_sendString(" Return code: ");
		UART_sendInt(return_code);
		UART_sendString("\n\n");
	}
	//FAT_fsync(&file);
}		// **************** end of SD card reading  ****************** //


void SD_card_read_test(char input[]){
// Mount the memory card
	//_delay_ms(1000);
	return_code = FAT_mountVolume();
	//sprintf(return_code);

	// If no error
		if(return_code == MR_OK){
		UART_sendString("Card mounted.\n");
		
		// Read label and serial number
		char label[12];
		char vol_sn_byte[4];
		uint32_t vol_sn = 0;
		FAT_getLabel(label, &vol_sn);
		
		// Extract serial number
		vol_sn_byte[0] = (vol_sn >> 24) & 0xFF;
		vol_sn_byte[1] = (vol_sn >> 16) & 0xFF;
		vol_sn_byte[2] = (vol_sn >> 8) & 0xFF;
		vol_sn_byte[3] = vol_sn & 0xFF;
		
		// Print serial number in hexadecimal format to serial terminal
		UART_sendString("\nVolume Serial Number is ");
		UART_sendHex8(vol_sn_byte[0]);
		UART_sendHex8(vol_sn_byte[1]);
		UART_sendString("-");
		UART_sendHex8(vol_sn_byte[2]);
		UART_sendHex8(vol_sn_byte[3]);
		UART_sendString("\n"); // new line character
		
		// Print label
		UART_sendString("Volume label is: ");
		UART_sendString(label);
		UART_sendString("\n\n"); // 2x new line character
		
		
		// Make a directory in the root folder
		return_code = FAT_makeDir(&dir, "Logs Folder");
		
		if(return_code == FR_OK){
			UART_sendString("Folder created.\n");
		}else{
			UART_sendString("Folder could not be created.\n");
			UART_sendString("Return error code: ");
			UART_sendInt(return_code);
			UART_sendString("\n");
		}
		
		// Open the created folder
		return_code = FAT_openDir(&dir, "Logs Folder");
		
		if(return_code == FR_OK){
			UART_sendString("Folder open: ");
			UART_sendString(FAT_getFilename());
			UART_sendString("\n\n");
			
			// Create a new file in the currently open folder
			return_code = FAT_makeFile(&dir, "log_1.txt");
			
			if(return_code == FR_OK){
				UART_sendString("File created.\n\n");
			}
			else{
				UART_sendString("File could not be created.\n");
				UART_sendString("Return error code: ");
				UART_sendInt(return_code);
				UART_sendString("\n\n");
			}
			
			
			// Get number of folders and files inside the directory
			dirItems = FAT_dirCountItems(&dir);
			UART_sendString("Folder has ");
			UART_sendInt(dirItems);
			UART_sendString(" items:\n");
			
			// Print folder content
			for(uint16_t i = 0; i < dirItems; i++){
				return_code = FAT_findNext(&dir, &file);
				
				if(FAT_attrIsFolder(&file)){
					UART_sendString("D, "); // Directory
				}else{
					UART_sendString("F, "); // File
				}
				
				UART_sendString("Idx: ");
				UART_sendInt(FAT_getItemIndex(&dir));
				UART_sendString(", ");
				
				UART_sendString(FAT_getFilename());
				UART_sendString("\n");
			}
		}else{
			UART_sendString("Could not open folder.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}

		
		/*FAT_openDir(&dir, "/");
		return_code = FAT_fdeleteByName(&dir, "Logging dir");
		UART_sendString("\nReturn code delete: ");
		UART_sendInt(return_code);
		UART_sendString("\n");*/
			
		// Open a file for reading or writing
		// Open the folder containing the file
		FAT_openDir(&dir, "Logs Folder");
		return_code = FAT_fopen(&dir, &file, "log_1.txt");
			
		if(return_code == FR_OK){
			UART_sendString("\nFile open: ");
			UART_sendString(FAT_getFilename());
			UART_sendString("\n\n");
			
			UART_sendString("File size: ");
			UART_sendInt(FAT_getFileSize(&file));
			UART_sendString("\n");
			
			// Keep only first 10 bytes of the file (example)
			//FAT_fseek(&file, 10);
			//FAT_ftruncate(&file);
			
			// Move the writing pointer to the end of the file
			FAT_fseekEnd(&file);
			
			FAT_fwriteString(&file, input);
			FAT_fwriteString(&file, "\n");
		
			// Synchronize the writing buffer with the card
			FAT_fsync(&file);
			
			UART_sendString("File new size: ");
			UART_sendInt(FAT_getFileSize(&file));
			UART_sendString(" bytes.\n");
			
		}else if(return_code == FR_NOT_FOUND){
			// Make the file if it doesn't exist
			// ... code ...
			
			UART_sendString("File could not be found.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}else{
			UART_sendString("File could not be opened.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}
			
	}else{ // end if(return_code == MR_OK)
		UART_sendString("Card not mounted. here1");
		UART_sendString(" Return code: ");
		UART_sendInt(return_code);
		UART_sendString("\n\n");
	}
	//FAT_fsync(&file);
}		/* **************** end of SD card demo functions  ****************** */
	
	
	
void SD_demo(void){
// Mount the memory card
	_delay_ms(200);
	return_code = FAT_mountVolume();
	//sprintf(return_code);

	// If no error
		if(return_code == MR_OK){
		UART_sendString("Card mounted.\n");
		
		// Read label and serial number
		char label[12];
		char vol_sn_byte[4];
		uint32_t vol_sn = 0;
		FAT_getLabel(label, &vol_sn);
		
		// Extract serial number
		vol_sn_byte[0] = (vol_sn >> 24) & 0xFF;
		vol_sn_byte[1] = (vol_sn >> 16) & 0xFF;
		vol_sn_byte[2] = (vol_sn >> 8) & 0xFF;
		vol_sn_byte[3] = vol_sn & 0xFF;
		
		// Print serial number in hexadecimal format to serial terminal
		UART_sendString("\nVolume Serial Number is ");
		UART_sendHex8(vol_sn_byte[0]);
		UART_sendHex8(vol_sn_byte[1]);
		UART_sendString("-");
		UART_sendHex8(vol_sn_byte[2]);
		UART_sendHex8(vol_sn_byte[3]);
		UART_sendString("\n"); // new line character
		
		// Print label
		UART_sendString("Volume label is: ");
		UART_sendString(label);
		UART_sendString("\n\n"); // 2x new line character
		
		
		// Make a directory in the root folder
		return_code = FAT_makeDir(&dir, "Logs Folder");
		
		if(return_code == FR_OK){
			UART_sendString("Folder created.\n");
		}else{
			UART_sendString("Folder could not be created.\n");
			UART_sendString("Return error code: ");
			UART_sendInt(return_code);
			UART_sendString("\n");
		}
		
		// Open the created folder
		return_code = FAT_openDir(&dir, "Logs Folder");
		
		if(return_code == FR_OK){
			UART_sendString("Folder open: ");
			UART_sendString(FAT_getFilename());
			UART_sendString("\n\n");
			
			// Create a new file in the currently open folder
			return_code = FAT_makeFile(&dir, "log_1.txt");
			
			if(return_code == FR_OK){
				UART_sendString("File created.\n\n");
			}
			else{
				UART_sendString("File could not be created.\n");
				UART_sendString("Return error code: ");
				UART_sendInt(return_code);
				UART_sendString("\n\n");
			}
			
			
			// Get number of folders and files inside the directory
			dirItems = FAT_dirCountItems(&dir);
			UART_sendString("Folder has ");
			UART_sendInt(dirItems);
			UART_sendString(" items:\n");
			
			// Print folder content
			for(uint16_t i = 0; i < dirItems; i++){
				
				return_code = FAT_findNext(&dir, &file);
				
				if(FAT_attrIsFolder(&file)){
					UART_sendString("D, "); // Directory
				}else{
					UART_sendString("F, "); // File
				}
				
				UART_sendString("Idx: ");
				UART_sendInt(FAT_getItemIndex(&dir));
				UART_sendString(", ");
				
				UART_sendString(FAT_getFilename());
				UART_sendString("\n");
			}
		}else{
			UART_sendString("Could not open folder.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}

		
		/*FAT_openDir(&dir, "/");
		return_code = FAT_fdeleteByName(&dir, "Logging dir");
		UART_sendString("\nReturn code delete: ");
		UART_sendInt(return_code);
		UART_sendString("\n");*/
			
		// Open a file for reading or writing
		// Open the folder containing the file
		FAT_openDir(&dir, "Logs Folder");
		return_code = FAT_fopen(&dir, &file, "log_1.txt");
			
		if(return_code == FR_OK){
			UART_sendString("\nFile open: ");
			UART_sendString(FAT_getFilename());
			UART_sendString("\n\n");
			
			UART_sendString("File size: ");
			UART_sendInt(FAT_getFileSize(&file));
			UART_sendString("\n");
			
			// Keep only first 10 bytes of the file (example)
			//FAT_fseek(&file, 10);
			//FAT_ftruncate(&file);
			
			// Move the writing pointer to the end of the file
			FAT_fseekEnd(&file);
			
			// Write a string
			FAT_fwriteString(&file, "Logging Date: 2024\n");
			
			// Write sensor output
			FAT_fwriteFloat(&file, 120.033, 3);
			FAT_fwriteString(&file, ",");
			FAT_fwriteFloat(&file, -0.221, 3);
			FAT_fwriteString(&file, ",");
			FAT_fwriteFloat(&file, -30.004, 3);
			FAT_fwriteString(&file, ",");
			FAT_fwriteFloat(&file, 0.023, 3);
			
			FAT_fwriteString(&file, "\n");
			// Synchronize the writing buffer with the card
			FAT_fsync(&file);
			
			UART_sendString("File new size: ");
			UART_sendInt(FAT_getFileSize(&file));
			UART_sendString("Next thing is total bytes");
			UART_sendInt(FAT_volumeCapacity());
			UART_sendString(" bytes.\n");
			
		}else if(return_code == FR_NOT_FOUND){
			// Make the file if it doesn't exist
			// ... code ...
			
			UART_sendString("File could not be found.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}else{
			UART_sendString("File could not be opened.\n");
			UART_sendString("Return code: ");
			UART_sendInt(return_code);
			UART_sendString("\n\n");
		}
			
	}else{ // end if(return_code == MR_OK)
		UART_sendString("Card not mounted. here2");
		UART_sendString(" Return code: ");
		UART_sendInt(return_code);
		UART_sendString("\n\n");
		//transmitHmi("page0", "c0", NULL, "0", 0);
	}
	//FAT_fsync(&file);
}		/* **************** end of SD card demo functions  ****************** */

