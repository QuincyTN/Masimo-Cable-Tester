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

//mcu page and attributes
#define PAGE_MCU "mcu"
#define N0 "n0"
#define N1 "n1"
#define T2 "t2"
#define T3 "t3"

//hmi page and attributes
#define PAGE_HMI "hmi"

//Constant Values
#define F_CPU 24000000UL
#define BAUDr 9600
#define BUFFER_SIZE 50
#define PRESCALER 1024

//HMI starting return message
//Valid range of custom starting bytes: 0x30 - 0x60
#define STRING_MESSAGE 0x70		//message has a string
#define NUM_MESSAGE 0x71		//message is an integer
#define START_CHAR 0x30			//message to start characterization
#define START_TEST 0x31			//message to start testing the wire cable
#define STOP_TEST  0x32			//message to stop testing the wire cable

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

#endif /* GLOBAL_CONSTS_VARS_H_ */