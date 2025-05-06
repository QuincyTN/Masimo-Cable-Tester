/*
 * MAIN Generated Driver File
 */

#include "mcc_generated_files/system/system.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <util/delay.h>

#include "utils.h"		// string conversion utilities used to communicate w/ terminal
#include "AVR_sd.h"		// low-level SD card functions, including init/using the SPI port
#include "fat.h"		// SD card file functions
#include "global_consts_vars.h"
#include "hmi_mcu_com.h"
// #include "adc.h"		// ADC functions for all the ADC port pins
// #include "detector.h"	// wire pair structure and defines for the short/break detector


void clk_init(void);	// MCU clocks initialization
void SD_demo(void);
void SD_characterization(void);		// gwp 6/12/2024 Demo SD card file functions.  The code has been moved
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

// #define TRUNCATED_SHIFT 4
// #define NUM_PINS 20
// #define MAX_VOLTAGE 5
// #define ADC_RESOLUTION 4095.0f
// #define ADC_division 1
// #define RANGE 410

struct {
	uint32_t result;
	uint16_t average_result;
} adc_data[NUM_PINS];

float voltage;

typedef struct {
	uint16_t val_1_00;
	uint16_t val_1_01;
	uint16_t val_1_10;
	uint16_t val_1_11;
	uint16_t val_2_00;
	uint16_t val_2_01;
	uint16_t val_2_10;
	uint16_t val_2_11;
} DataStruct;


DataStruct myArray[NUM_PINS][NUM_PINS] = {0};
DataStruct myArray2[NUM_PINS][NUM_PINS] = {0};
//DataStruct testArray[NUM_PINS][NUM_PINS] = {0};
#define FAULT_TRIP_THRESHOLD 50
uint8_t	numFaults[NUM_PINS][NUM_PINS] = {0};

void setOutput(int n); void setInput(int n); void setHigh(int n); void setLow(int n);


// Map ADC channel to correct MUXPOS input
// uint8_t adc_channel_map[NUM_PINS] = {
// 	ADC_MUXPOS_AIN0_gc, ADC_MUXPOS_AIN1_gc, ADC_MUXPOS_AIN2_gc, ADC_MUXPOS_AIN3_gc,
// 	ADC_MUXPOS_AIN4_gc, ADC_MUXPOS_AIN5_gc, ADC_MUXPOS_AIN6_gc, ADC_MUXPOS_AIN7_gc,
// 	ADC_MUXPOS_AIN8_gc, ADC_MUXPOS_AIN9_gc, ADC_MUXPOS_AIN10_gc, ADC_MUXPOS_AIN11_gc,
// 	ADC_MUXPOS_AIN12_gc, ADC_MUXPOS_AIN13_gc, ADC_MUXPOS_AIN14_gc, ADC_MUXPOS_AIN15_gc,
// 	ADC_MUXPOS_AIN18_gc, ADC_MUXPOS_AIN19_gc, ADC_MUXPOS_AIN20_gc, ADC_MUXPOS_AIN21_gc
// };

uint8_t adc_channel_map[NUM_PINS] = {
	ADC_MUXPOS_AIN9_gc, ADC_MUXPOS_AIN8_gc, ADC_MUXPOS_AIN7_gc, ADC_MUXPOS_AIN6_gc,
	ADC_MUXPOS_AIN5_gc, ADC_MUXPOS_AIN4_gc, ADC_MUXPOS_AIN3_gc, ADC_MUXPOS_AIN2_gc,
	ADC_MUXPOS_AIN1_gc, ADC_MUXPOS_AIN0_gc, ADC_MUXPOS_AIN10_gc, ADC_MUXPOS_AIN11_gc,
	ADC_MUXPOS_AIN12_gc, ADC_MUXPOS_AIN13_gc, ADC_MUXPOS_AIN14_gc, ADC_MUXPOS_AIN15_gc,
	ADC_MUXPOS_AIN18_gc, ADC_MUXPOS_AIN19_gc, ADC_MUXPOS_AIN20_gc, ADC_MUXPOS_AIN21_gc
};


// float process_adc_conversion(uint8_t current_channel) {
// 	uint16_t result;
// 	ADC0.MUXPOS = adc_channel_map[current_channel];
// 	//_delay_ms(5);
// 	ADC0.COMMAND = ADC_STCONV_bm;
// 	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
// 	ADC0.INTFLAGS = ADC_RESRDY_bm;
// 	result = ADC0.RES;
// 	float voltage = (result * MAX_VOLTAGE) / ADC_RESOLUTION;
// 	return voltage;
// }


uint16_t process_adc_conversion(uint8_t current_channel) {
	uint16_t result;
	ADC0.MUXPOS = adc_channel_map[current_channel];
	//_delay_ms(5);
	ADC0.COMMAND = ADC_STCONV_bm;
	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
	ADC0.INTFLAGS = ADC_RESRDY_bm;
	result = ADC0.RES;
	return result;
}

// uint16_t process_adc_conversion(uint8_t adcx) {
// 	ADC0.MUXPOS = (0x7F & adcx);	// Set the channel desired for the conversion
// 	ADC0.COMMAND = ADC_STCONV_bm;	// start conversion
// 	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
// 	ADC0.INTFLAGS = ADC_RESRDY_bm;
// 
// 	return ADC0.RES;	// return the converted value to the calling function.
//

void characterize(int pin1, int pin2) {
	if (pin1 != pin2) {
		setOutput(pin1);
		setOutput(pin2);
		setLow(pin1);
		setLow(pin2);
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
	
	setLow(pin1);
	setLow(pin2);
	if (abs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_00) > RANGE ||
		abs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_00) > RANGE)
		{ setInput(pin1); setInput(pin2); return false; } 
	
	setHigh(pin1);
	setLow(pin2);
	if (abs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_10) > RANGE ||
		abs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_10) > RANGE)
		{ setInput(pin1); setInput(pin2); return false; } 
		
	setLow(pin1);
	setHigh(pin2);
	if (abs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_01) > RANGE ||
		abs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_01) > RANGE)
		{ setInput(pin1); setInput(pin2); return false; } 
		
	setHigh(pin1);
	setHigh(pin2);
	if (abs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_11) > RANGE ||
		abs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_11) > RANGE)
		{ setInput(pin1); setInput(pin2); return false; } 
		
	setInput(pin1);
	setInput(pin2);
	return true;
}

void relay_init() {
	PORTG.DIRSET = PIN0_bm;
	PORTG.OUTSET = PIN0_bm;
}


void setADCInput(int n) {
	switch (n) {
		case 0: PORTE.DIRCLR = PIN1_bm; break;
		case 1: PORTE.DIRCLR = PIN0_bm; break;
		case 2 ... 9: PORTD.DIRCLR = (1 << (9 - n)); break;
		case 10 ... 15: PORTE.DIRCLR = (1 << (n - 8)); break;
		case 16 ... 19: PORTF.DIRCLR = (1 << (n - 14)); break;
	}
}

/*
void setOutput(int n) {
	switch (n) {
		case 0: PORTE.DIRSET = PIN1_bm; break;
		case 1: PORTE.DIRSET = PIN0_bm; break;
		case 2 ... 9: PORTD.DIRSET = (1 << (9 - n)); break;
		case 10 ... 15: PORTE.DIRSET = (1 << (n - 8)); break;
		case 16 ... 19: PORTF.DIRSET = (1 << (n - 14)); break;
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
*/

void setOutput(int n) {
	switch (n) {
		case 0: PORTA.DIRSET = PIN7_bm; break; //CTRL 1
		case 1 ... 6: PORTB.DIRSET = (1 << (1 + n)); break; //CTRL 2 - CTRL 7
		case 7 ... 12: PORTC.DIRSET = (1 << (n - 5)); break; //CTRL 8 - CTRL 13
		case 13 ... 19: PORTG.DIRSET = (1 << (n - 12)); break; //CTRL 14 - CTRL 20
	}
}

void setInput(int n) {
	switch (n) {
		case 0: PORTA.DIRCLR = PIN7_bm; break; //CTRL 1
		case 1 ... 6: PORTB.DIRCLR = (1 << (1 + n)); break; //CTRL 2 - CTRL 7
		case 7 ... 12: PORTC.DIRCLR = (1 << (n - 5)); break; //CTRL 8 - CTRL 13
		case 13 ... 19: PORTG.DIRCLR = (1 << (n - 12)); break; //CTRL 14 - CTRL 20
	}
}

void setHigh(int n) {
	switch (n) {
		case 0: PORTA.OUTSET = PIN7_bm; break; //CTRL 1
		case 1 ... 6: PORTB.OUTSET = (1 << (1 + n)); break; //CTRL 2 - CTRL 7
		case 7 ... 12: PORTC.OUTSET = (1 << (n - 5)); break; //CTRL 8 - CTRL 13
		case 13 ... 19: PORTG.OUTSET = (1 << (n - 12)); break; //CTRL 14 - CTRL 20
	}
}

void setLow(int n) {
	switch (n) {
		case 0: PORTA.OUTCLR = PIN7_bm; break; //CTRL 1
		case 1 ... 6: PORTB.OUTCLR = (1 << (1 + n)); break; //CTRL 2 - CTRL 7
		case 7 ... 12: PORTC.OUTCLR = (1 << (n - 5)); break; //CTRL 8 - CTRL 13
		case 13 ... 19: PORTG.OUTCLR = (1 << (n - 12)); break; //CTRL 14 - CTRL 20
	}
}


int main(void) {
	clk_init();
	SYSTEM_Initialize();
	initUSART1();
	relay_init();
	initTimer1s();
	
	sei();
	
	volatile bool CARD_IN = false;		// variables for determining state of the SD card insertion
	volatile bool CARD_OUT = false;
	bool testadc = true;

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
	*/
	
	//Sets ADC to inputs
	for (int i = 0; i < NUM_PINS; i++) {
		setADCInput(i);
	}
	
	getTime();	//update MCU clock
	
 	while(1) {
		if(return_code==1) {					      // makes sure the requirement is not checked off if
			transmitHmi(PAGE_HOME, "t5", NULL, "X", 2); // there was a mounting error
		}
		
		if(FAT_getFileSize(&file) >= 10) {
			//transmitHmi(PAGE_HOME, "t6", NULL, "OK", 2);
		}
		//transmitHmi("home", "t5", NULL, "hii", 2);
		
		 
		//SD_demo();
		//TODO: MOVE THIS FUNCTION IN THE HMI_MCU_COM.c after done characterization
		//SD_characterization();
	while (1) {
		
		if(sd_detected()){
			if (!CARD_IN){
				transmitHmi(PAGE_HOME, "t5", NULL, "OK", 2);
				//SD_characterization();
				//SD_demo();
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
				//UART_sendString("Card disconnected\n");
				transmitHmi(PAGE_HOME, "t5", NULL, "X", 2);	// SD card inserted requirement not met
				//transmitHmi(PAGE_HOME, "t6", NULL, "X", 2);	// SD card capacity requirement not met
				//transmitHmi(PAGE_HOME, "t7", NULL, "X", 2);	// characterization requirement not met
				CARD_OUT = true;
				CARD_IN = false;
			}
		} // end of card has been read and is in place
		/*
		for (int i = 0; i < NUM_PINS; i++) {
			for (int j = 0; j < NUM_PINS; j++) {
				if(i!=j){
					testadc = check_adc_within_range(i,j);
		
					if (!testadc) {
						PORTG.OUTSET = PIN0_bm;
						_delay_ms(200);
						PORTG.OUTCLR = PIN0_bm;
						_delay_ms(200);
					} else {
						//PORTG.OUTSET = PIN0_bm;
						//_delay_ms(200);
						PORTG.OUTCLR = PIN0_bm;
						//_delay_ms(200);
						//transmitHmi(PAGE_FAULT_DETECTED, NULL, NULL, NULL, 4);
					}
		
					}
				}
			}
		}
		*/
		if(newHmiMessage){
			parseHmiData(hmiBuffer);
			newHmiMessage = 0;	//reset flag
		}
		
		if(newCharacterization){
					
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
					
			SD_characterization();
			newCharacterization = 0;
			transmitHmi(PAGE_CHAR_SUCCESS, NULL, NULL, NULL, 4);	// display characterization success screen
			transmitHmi(PAGE_HOME, "t7", NULL, "OK", 2);	// characterization available, set requirement on HMI
		}
		
		if(testingStart && !testingPause){
			for (uint8_t i = 0; i < NUM_PINS && !faultDetected; i++) {
				for (uint8_t j = 0; j < NUM_PINS && !faultDetected; j++) {
					if(i!=j){
						testadc = check_adc_within_range(i,j);
						
						if (!testadc) {
// 							PORTG.OUTSET = PIN0_bm;	// set relay if there is a fault
// 							_delay_ms(200);
// 							PORTG.OUTCLR = PIN0_bm;
// 							_delay_ms(200);
	
							numFaults[i][j] += 1;	//when fault detected, increment the fault count
							
						} 
						else {
							//PORTG.OUTSET = PIN0_bm;
							//_delay_ms(200);
							//PORTG.OUTCLR = PIN0_bm;	//
							//_delay_ms(200);
							//transmitHmi(PAGE_FAULT_DETECTED, NULL, NULL, NULL, 4);
						}
						
						if(numFaults[i][j] >= FAULT_TRIP_THRESHOLD){
							// Number of faults in a single pin pair has occurred over the threshold, therefore a fault is detected
							//SD_characterization();
							
							char temp[BUFFER_SIZE*2];
							
							//TODO FIX THIS WHY IS IT TRUNCATED
							sprintf(temp, "Short/Open between:\\rPin %u and Pin %u\\rAt %0.2lu/%0.2lu/%0.4lu %0.2lu:%0.2lu:%0.2lu", 
									i, j, month, day, year, hour, minute, second);	// Print the error message
							transmitHmi(PAGE_FAULT_DETECTED, FAULT_TXT, NULL, temp, 2);
							
							transmitHmi(PAGE_FAULT_DETECTED, NULL, NULL, NULL, 4);	// go to FAULT_DETECTED page
							
							faultDetected = 1;
							testingStart = 0;
							testingPause = 0;
							
							afterFault = 1;
							memset(numFaults, 0, sizeof(numFaults));
							
							PORTG.OUTSET = PIN0_bm;	// set relay, stop the bend cycle tester
						}
					}
				}
			}
		}			
		else if (testingPause){
			//TODO PAUSE SD CARD COUNTING
			transmitHmi(PAGE_TESTING, "t4", NULL, "PAUSED", 2);

		}
		else{
			//PORTG.OUTCLR = 0x01;	// relay is open during no test
			//memset(numFaults, 0, sizeof(numFaults));
// 			for(int i = 0; i < NUM_PINS; i++){
// 				for(int j = 0; j < NUM_PINS; j++){
// 					numFaults[i][j] = 0;
// 				}
// 			}
			

			faultDetected = 0;
			lastSdWrite = 0;
			PORTG.OUTCLR = PIN0_bm;
			
			
			
// 			PORTG.OUTSET = PIN0_bm;
// 			_delay_ms(1000);
// 			PORTG.OUTCLR = PIN0_bm;
// 			_delay_ms(1000);
			
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

void SD_characterization(void){
// Mount the memory card
	_delay_ms(100);
	return_code = FAT_mountVolume();
	//sprintf(return_code);

	// If no error
		if(return_code == MR_OK){
		
		// Read label and serial number
		char label[12];
		uint32_t vol_sn = 0;
		FAT_getLabel(label, &vol_sn);
		
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
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_1_00 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_2_00 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Pin A high/Pin B low,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_1_10 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_2_10 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Pin A low/Pin B high,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_1_01 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_2_01 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Both High Test,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_1_11 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%.2f,", (float) (((myArray[i][j].val_2_11 * MAX_VOLTAGE) / ADC_RESOLUTION)/ADC_division));
						FAT_fwriteString(&file, target1);
					}
				}
			}

			

// 			FAT_fwriteString(&file, "\n");
// 			
// 			for(int i = 0; i < NUM_PINS; i++){
// 				for(int j = 0; j < NUM_PINS; j++){
// 					if (i != j){
// 						sprintf(target1, "%u,", numFaults[i][j]);
// 						FAT_fwriteString(&file, target1);
// 					}
// 				}
// 			}
			
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


void SD_demo(void){
// Mount the memory card
	_delay_ms(100);
	return_code = FAT_mountVolume();
	//sprintf(return_code);

	// If no error
		if(return_code == MR_OK){
		
		// Read label and serial number
		char label[12];
		uint32_t vol_sn = 0;
		FAT_getLabel(label, &vol_sn);
		
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
						sprintf(target1, "%u,", myArray[i][j].val_1_00);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%u,", myArray[i][j].val_2_00);
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Pin A high/Pin B low,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%u,",  myArray[i][j].val_1_10);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%u,", myArray[i][j].val_2_10);
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Pin A low/Pin B high,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%u,", myArray[i][j].val_1_01);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%u,", myArray[i][j].val_2_01);
						FAT_fwriteString(&file, target1);
					}
				}
			}
			
			FAT_fwriteString(&file, "\n");
			FAT_fwriteString(&file, "Both High Test,");
			for(int i = 0; i < NUM_PINS; i++){
				for(int j = 0; j < NUM_PINS; j++){
					if (i != j){
						sprintf(target1, "%u,", myArray[i][j].val_1_11);
						FAT_fwriteString(&file, target1);
						sprintf(target1, "%u,", myArray[i][j].val_2_11);
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
