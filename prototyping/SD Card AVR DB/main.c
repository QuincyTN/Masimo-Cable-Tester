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

/* ***************************************************************************	 
   ********************************** main ***********************************
   *************************************************************************** */
int main(void)
{	
	volatile bool CARD_IN = false;		// variables for determining state of the SD card insertion
    volatile bool CARD_OUT = false;

	clk_init();			// sets up main and peripheral clocks
	uart_init();		// sets up UART 3 - 115200 baud, 1 stop bit,  no parity, no flow control

	UART_sendString("\n\n");	// reset terminal lines
	
	while(1){  // main loop  

    SD_demo();			// call the SD card initialization/file write demo functions.
						// this will be replaced by the SD card functions to support the 
						// short/break detector.  Functions follow main.

    while (1){  // inner loop.  Only broken out of back to main loop if the 
				// SD card has been removed and re-inserted
		
		//UART_sendString("Testing delay...\n");	// debug to see delay is working properly
		 //_delay_ms(1000);						    // execute this loop approximately once per second
		
		if(sd_detected()){
			if (!CARD_IN){
				UART_sendString("Card connected\n");
				CARD_IN = true;
				if (CARD_OUT)   // can only get here if SD card was inserted, removed, and reinserted
					{
						CARD_OUT = false;
						break;  // returns to checking for an SD Card
					}
				CARD_OUT = false;
				}
			}
		else{
			if(!CARD_OUT) {
				UART_sendString("Card disconnected\n");
				CARD_OUT = true;
				CARD_IN = false;
				}
			} // end of card has been read and is in place
			
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
				if (strcmp(cmd_buffer, "testsd") == 0) {
					SD_demo();		// run the SD demo again w/o changing state of the SD card
					//SD_card_read(cmd_buffer);
					}
				
			}	// end of new data received from terminal 
			
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
	_delay_ms(100);
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
	}
	//FAT_fsync(&file);
}		/* **************** end of SD card demo functions  ****************** */

