#include "global_consts_vars.h"

//USART2 transmitter and receiver buffer
char transmitData[BUFFER_SIZE];
uint8_t dataIndexTx = 0;
char receiveData[BUFFER_SIZE];
uint8_t dataIndexRx = 0;

//Flags for USART
uint8_t hmiReceiving = 0;			//flag for currently recievng HMI message
uint8_t terminalReceiving = 0;		//flag for currently recievng Terminal message
uint8_t receiveFlag = 0;
uint8_t timerFlag = 0;

//Flags for main() polling
uint8_t newHmiMessage = 0;
uint8_t newTerminalMessage = 0;
uint8_t testingStart = 0;	
uint8_t testingPause = 0;
uint8_t faultDetected = 0;
uint8_t newCharacterization = 0;

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
"_____________________________________________________________________\n"
"led on          - Turns the LED on\n"
"led off         - Turns the LED off\n"
"help            - Display a menu of terminal functions\n"
"settings        - Display current settings\n"
"get time(WIP)   - Display local MCU time\n"
"char done       - Simulate characterization finish, go to respective page\n"
"fault           - Go to the fault_detected\n";

//Settings page variables
uint32_t rate = 5;
char rate_unit[8] = "/min";
uint32_t bypassMode = 0;		// 0 = normal, 1 = bypass
uint32_t lastSdWrite = 0;
uint32_t updateRateInS = 22;

//Local MCU time variables
uint32_t updateTime = 0;
uint32_t year = 2025;
uint32_t month = 1;
uint32_t day = 1;
uint32_t hour = 1;
uint32_t minute = 1;
uint32_t second = 1;
uint8_t daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
uint32_t lastTimeUpdate = 0;

//SD file writing variables
char fileNum[100];
uint32_t testNumber = 1;