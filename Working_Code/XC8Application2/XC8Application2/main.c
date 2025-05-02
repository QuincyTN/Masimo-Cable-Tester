/*
 * MAIN Generated Driver File
 */

#include "mcc_generated_files/system/system.h"
#include <math.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>

#include "utils.h"		// string conversion utilities used to communicate w/ terminal
#include "AVR_sd.h"		// low-level SD card functions, including init/using the SPI port
#include "fat.h"		// SD card file functions
// #include "adc.h"		// ADC functions for all the ADC port pins
// #include "detector.h"	// wire pair structure and defines for the short/break detector


void clk_init(void);	// MCU clocks initialization
void SD_demo(void);		// gwp 6/12/2024 Demo SD card file functions.  The code has been moved
// to after main() for code readability.  Eventually this will be replaced
// with the SD card functions needed to support the short/break detector.

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

#define TRUNCATED_SHIFT 4
#define NUM_PINS 20
#define MAX_VOLTAGE 3.3
#define ADC_RESOLUTION 4095.0f

struct {
	uint32_t result;
	uint16_t average_result;
} adc_data[NUM_PINS];

float voltage;

typedef struct {
	float val_1_00;
	float val_1_01;
	float val_1_10;
	float val_1_11;
	float val_2_00;
	float val_2_01;
	float val_2_10;
	float val_2_11;
} DataStruct;


DataStruct myArray[NUM_PINS][NUM_PINS] = {0};
//DataStruct testArray[NUM_PINS][NUM_PINS] = {0};

void setOutput(int n); void setInput(int n); void setHigh(int n); void setLow(int n);


// Map ADC channel to correct MUXPOS input
uint8_t adc_channel_map[NUM_PINS] = {
	ADC_MUXPOS_AIN0_gc, ADC_MUXPOS_AIN1_gc, ADC_MUXPOS_AIN2_gc, ADC_MUXPOS_AIN3_gc,
	ADC_MUXPOS_AIN4_gc, ADC_MUXPOS_AIN5_gc, ADC_MUXPOS_AIN6_gc, ADC_MUXPOS_AIN7_gc,
	ADC_MUXPOS_AIN8_gc, ADC_MUXPOS_AIN9_gc, ADC_MUXPOS_AIN10_gc, ADC_MUXPOS_AIN11_gc,
	ADC_MUXPOS_AIN12_gc, ADC_MUXPOS_AIN13_gc, ADC_MUXPOS_AIN14_gc, ADC_MUXPOS_AIN15_gc,
	ADC_MUXPOS_AIN18_gc, ADC_MUXPOS_AIN19_gc, ADC_MUXPOS_AIN20_gc, ADC_MUXPOS_AIN21_gc
};

float process_adc_conversion(uint8_t current_channel) {
	uint16_t result;
	ADC0.MUXPOS = adc_channel_map[current_channel];
	//_delay_ms(5);
	ADC0.COMMAND = ADC_STCONV_bm;
	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
	ADC0.INTFLAGS = ADC_RESRDY_bm;
	result = ADC0.RES;
	float voltage = (result * MAX_VOLTAGE) / ADC_RESOLUTION;
	return voltage;
}

void characterize(int pin1, int pin2) {
	if (pin1 != pin2) {
		setOutput(pin1);
		setOutput(pin2);
		setLow(pin1);
		setLow(pin2);
		//myArray[pin1][pin2].val_1_00 = process_adc_conversion(pin1);
		myArray[pin1][pin2].val_1_00 = process_adc_conversion(pin1);
		myArray[pin1][pin2].val_2_00 = process_adc_conversion(pin2);
		
		setHigh(pin1);
		setLow(pin2);
		myArray[pin1][pin2].val_1_10 = process_adc_conversion(pin1);
		myArray[pin1][pin2].val_2_10 = process_adc_conversion(pin2);
		
		setLow(pin1);
		setHigh(pin2);
		myArray[pin1][pin2].val_1_01 = process_adc_conversion(pin1);
		myArray[pin1][pin2].val_2_01 = process_adc_conversion(pin2);
		
		setHigh(pin1);
		setHigh(pin2);
		myArray[pin1][pin2].val_1_11 =  process_adc_conversion(pin1);
		myArray[pin1][pin2].val_2_11 =  process_adc_conversion(pin2);
		
		setInput(pin1);
		setInput(pin2);
	}
}



bool check_adc_within_range(int pin1, int pin2) {
	setOutput(pin1);
	setOutput(pin2);
	setHigh(pin1);
	setLow(pin2);
	if (fabs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_10) > 0.1 ||
		fabs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_10) > 0.1)
		return false;
	setLow(pin1);
	setHigh(pin2);
	if (fabs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_01) > 0.1 ||
		fabs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_01) > 0.1)
		return false;
	setInput(pin1);
	setInput(pin2);
	return true;
}

void relay_init() {
	PORTG.DIRSET = PIN0_bm;
	PORTG.OUTSET = PIN0_bm;
}

void setOutput(int n) {
	switch (n) {
		case 0: PORTE.DIRSET = PIN1_bm; break;
		case 1: PORTE.DIRSET = PIN0_bm; break;
		case 2 ... 9: PORTD.DIRSET = (1 << (9 - n)); break;
		case 10 ... 15: PORTE.DIRSET = (1 << (n - 8)); break;
		case 16 ... 19: PORTF.DIRSET = (1 << (n - 14)); break;
	}
}

void setInput(int n) {
	switch (n) {
		case 0: PORTE.DIRCLR = PIN1_bm; break;
		case 1: PORTE.DIRCLR = PIN0_bm; break;
		case 2 ... 9: PORTD.DIRCLR = (1 << (9 - n)); break;
		case 10 ... 15: PORTE.DIRCLR = (1 << (n - 8)); break;
		case 16 ... 19: PORTF.DIRCLR = (1 << (n - 14)); break;
	}
}

void setHigh(int n) {
	switch (n) {
		case 0: PORTE.OUTSET = PIN1_bm; break;
		case 1: PORTE.OUTSET = PIN0_bm; break;
		case 2 ... 9: PORTD.OUTSET = (1 << (9 - n)); break;
		case 10 ... 15: PORTE.OUTSET = (1 << (n - 8)); break;
		case 16 ... 19: PORTF.OUTSET = (1 << (n - 14)); break;
	}
}

void setLow(int n) {
	switch (n) {
		case 0: PORTE.OUTCLR = PIN1_bm; break;
		case 1: PORTE.OUTCLR = PIN0_bm; break;
		case 2 ... 9: PORTD.OUTCLR = (1 << (9 - n)); break;
		case 10 ... 15: PORTE.OUTCLR = (1 << (n - 8)); break;
		case 16 ... 19: PORTF.OUTCLR = (1 << (n - 14)); break;
	}
}


int main(void) {
	SYSTEM_Initialize();
	relay_init();
	volatile bool CARD_IN = false;		// variables for determining state of the SD card insertion
	volatile bool CARD_OUT = false;
// 	for (int i = 0; i < NUM_PINS; i++) {
// 		for(int j = 0; i < NUM_PINS; j++) {
// 			if(i!=j){
// 				setOutput(i);
// 				setHigh(i);
// 				myArray[i][j].val_1_11 = process_adc_conversion(i);
// 				myArray[i][j].val_2_11 = process_adc_conversion(j);	
// 			}
// 		}
// 	}
	for (int i = 0; i < NUM_PINS; i++) {
		setInput(i);
	}
// 		setOutput(0);
// 		setHigh(0);
// 		
// 		for (int i = 0; i < 4; i++) {
// 		 		for(int j = 0; i < 4; j++) {
// 		 			if(i!=j){
// 		 				myArray[i][j].val_1_00 = process_adc_conversion(0);
// 		 				myArray[i][j].val_2_00 = process_adc_conversion(0);
// 						myArray[i][j].val_1_01 = process_adc_conversion(0);
// 						myArray[i][j].val_2_01 = process_adc_conversion(0);
// 						myArray[i][j].val_1_10 = process_adc_conversion(0);
// 						myArray[i][j].val_2_10 = process_adc_conversion(0);
// 						myArray[i][j].val_1_11 = process_adc_conversion(0);
// 						myArray[i][j].val_2_11 = process_adc_conversion(0);
// 		 			}
// 		 		}
// 		 	}
		//myArray[0][1].val_1_11 = process_adc_conversion(0);
	
	for (int i = 0; i < NUM_PINS; i++) {
		for (int j = 0; j < NUM_PINS; j++) {
			if(i!=j){
			characterize(i, j);
			}
		}
	}
 	while(1) {
		SD_demo();
	while (1) {
		
		if(sd_detected()){
			if (!CARD_IN){
				//UART_sendString("Card connected\n");
				CARD_IN = true;
				if (CARD_OUT)   // can only get here if SD card was inserted, removed, and reinserted
				{
					CARD_OUT = false;
					break;  // returns to checking for an SD Card
				}
				CARD_OUT = false;
				/*
				for (int i = 0; i < NUM_PINS; i++) {
					for (int j = 0; j < NUM_PINS; j++) {
						characterize(i, j);
					}
				}
				*/
			}
		}
		else{
			if(!CARD_OUT) {
				//UART_sendString("Card disconnected\n");
				CARD_OUT = true;
				CARD_IN = false;
			}
		} // end of card has been read and is in place
		if (process_adc_conversion(0) > 3) {
			PORTG.OUTSET = PIN0_bm;
			_delay_ms(1000);
			PORTG.OUTCLR = PIN0_bm;
			_delay_ms(1000);
		} else {
			PORTG.OUTSET = PIN0_bm;
			_delay_ms(200);
			PORTG.OUTCLR = PIN0_bm;
			_delay_ms(200);
		}
	}
	}
}

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
}	

void SD_demo(void){
// Mount the memory card
	_delay_ms(100);
	return_code = FAT_mountVolume();
	//sprintf(return_code);

	// If no error
		if(return_code == MR_OK){
		
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
		
		if(return_code == FR_OK){
		}else{
		}
		
		// Open the created folder
		return_code = FAT_openDir(&dir, "Logs Folder");
		
		if(return_code == FR_OK){

			// Create a new file in the currently open folder
			return_code = FAT_makeFile(&dir, "log_1.csv");
			
			if(return_code == FR_OK){
			}
			else{
			}
			
			
			// Get number of folders and files inside the directory
			dirItems = FAT_dirCountItems(&dir);
			
			// Print folder content
			for(uint16_t i = 0; i < dirItems; i++){
				
				return_code = FAT_findNext(&dir, &file);
				
				if(FAT_attrIsFolder(&file)){
				}else{
				}
				
			}
		}else{
		}

		
		/*FAT_openDir(&dir, "/");
		return_code = FAT_fdeleteByName(&dir, "Logging dir");
		UART_sendString("\nReturn code delete: ");
		UART_sendInt(return_code);
		UART_sendString("\n");*/
			
		// Open a file for reading or writing
		// Open the folder containing the file
		FAT_openDir(&dir, "Logs Folder");
		return_code = FAT_fopen(&dir, &file, "log_1.csv");
			
		if(return_code == FR_OK){			
			// Keep only first 10 bytes of the file (example)
			//FAT_fseek(&file, 10);
			//FAT_ftruncate(&file);
			
			// Move the writing pointer to the end of the file
			FAT_fseekEnd(&file);
			
			/////////////////////////////**EDIT///////////////////////////
			FAT_fwriteString(&file, "Test 1"); FAT_fwriteString(&file, ",");
			//sprintf(target, "Pins (%d.%d) Pin %c voltage, ", pin1, pin2, output);
			char target1[50];
			char target2[50];
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "Pins (%d.%d) Pin %c voltage, ", i, j, 'A');
						sprintf(target2, "Pins (%d.%d) Pin %c voltage, ", i, j, 'B');
						FAT_fwriteString(&file, target1);
						FAT_fwriteString(&file, target2);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Both Low Test,");

			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", myArray[i][j].val_1_00);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", myArray[i][j].val_2_00);
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Pin A high/Pin B low,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", myArray[i][j].val_1_10);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", myArray[i][j].val_2_10);
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Pin A low/Pin B high,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", myArray[i][j].val_1_01);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", myArray[i][j].val_2_01);
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Both High Test,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", myArray[i][j].val_1_11);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", myArray[i][j].val_2_11);
						FAT_fwriteString(&file, target1);
					}
				}
			}

			

			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "\n");

			
			////////////////////////////////////////**EDIT**//////////////////////////////////////////////
			
			
			
			
			// Synchronize the writing buffer with the card
			FAT_fsync(&file);
			
		}else if(return_code == FR_NOT_FOUND){
			// Make the file if it doesn't exist
			// ... code ...
			
		}else{
		}
			
	}else{ // end if(return_code == MR_OK)
		
	}
	//FAT_fsync(&file);
}		/* **************** end of SD card demo functions  ****************** */