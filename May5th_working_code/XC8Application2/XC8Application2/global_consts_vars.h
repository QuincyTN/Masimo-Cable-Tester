#ifndef GLOBAL_CONSTS_VARS_H_
#define GLOBAL_CONSTS_VARS_H_

#include <inttypes.h>

//HMI Objects
/*
The HMI and GUI is structured by pages and the attributes on it. These range from text fields, numbers, buttons, sliders, and other interactive elements.
The MCU can be used to access values and change them by sending "commands" through the USART. Use the NEXTION Instruction set to find the appropriate
commands.
The definitions below will be used to access relevant attributes and their values from the HMI.
The attribute is in the form of "[page].[ID].[field]" (eg "mcu.n0.val")
*/

#define VAL "val"	//used to get the value attribute of a number
#define TXT "txt"	//used to get the text attribute of a text field

//home page and attributes
#define PAGE_HOME "home"

//settings page and attributes
#define PAGE_SETTINGS "settings"
#define RECORD_RATE "rate"
#define RECORD_UNIT "unit"
#define MODE "mode"

//char_in_prog page and attributes
#define PAGE_CHAR_IN_PROG "char_in_prog"

//char_fail page and attributes
#define PAGE_CHAR_FAIL "char_fail"

//char_success page and attributes
#define PAGE_CHAR_SUCCESS "char_success"

//testing page and attributes
#define PAGE_TESTING "testing"
#define START_TIME_TXT "start_time"

//fault_detected page and attributes
#define PAGE_FAULT_DETECTED "fault_detected"
#define FAULT_TXT "fault_msg"

//Constant Values
#define F_CPU 24000000UL
#define BAUDr 9600
#define BUFFER_SIZE 50
#define PRESCALER 1024	// timer0 prescaler
#define RTC_UPDATE 900	// time in seconds to update local MCU time with RTC on HMI

// ADC and Characterization constants
#define TRUNCATED_SHIFT 4
#define NUM_PINS 20
#define MAX_VOLTAGE 5
#define ADC_RESOLUTION 4095.0f
#define ADC_division 1
#define RANGE 410


//HMI starting return message
//Valid range of custom starting bytes: 0x30 - 0x60
#define STRING_MESSAGE 0x70		//message has a string
#define NUM_MESSAGE 0x71		//message is an integer
#define START_CHAR 0x30			//message to start characterization
#define START_TEST 0x31			//message to start testing the cable
#define STOP_TEST  0x32			//message to stop testing the cable
#define PAUSE_TEST 0x33			//message to pause cable testing
#define UNPAUSE_TEST 0x37		//message to unpause cable testing

#define UPDATE_RATE 0x34		//message to update data recording rate
#define UPDATE_RATE_UNIT 0x35	//message to update data recording rate units
#define UPDATE_MODE 0x36		//message to update mode of operation

//USART2 transmitter and receiver buffer
char transmitData[BUFFER_SIZE];
uint8_t dataIndexTx;
char receiveData[BUFFER_SIZE];
uint8_t dataIndexRx;

//Flags for USART
uint8_t hmiReceiving;			//flag for HMI
uint8_t terminalReceiving;		//flag for terminal
uint8_t receiveFlag;
uint8_t timerFlag;

//Flags for main() polling
uint8_t newHmiMessage;			//new HMI message received by ISR, carry out command
uint8_t newTerminalMessage;		//new terminal message received by ISR, carry out command
uint8_t testingStart;			//Begin cable testing,
uint8_t testingPause;			// Cable testing is paused
uint8_t faultDetected;			// fault is detected, stop loop
uint8_t newCharacterization;

//USART3 transmitter and receiver buffer
char transmitData3[BUFFER_SIZE];
uint8_t dataIndexTx3;
char receiveData3[BUFFER_SIZE];
uint8_t dataIndexRx3;

//Buffers for the receiver of the terminal and HMI
char terminalBuffer[BUFFER_SIZE];
char hmiBuffer[BUFFER_SIZE];

//Help menu string
const char helpMenu[];

//Settings page variables
uint32_t rate;
char rate_unit[8];
uint32_t mode;
uint32_t lastSdWrite;		//time in seconds of the last SD card write
uint32_t updateRateInS;		//convert rate and units into seconds

//Local MCU time variables
uint32_t updateTime;
uint32_t year;
uint32_t month;
uint32_t day;
uint32_t hour;
uint32_t minute;
uint32_t second;
uint8_t daysInMonth[13];
uint32_t lastTimeUpdate;


uint8_t afterFault;
#endif /* GLOBAL_CONSTS_VARS_H_ */