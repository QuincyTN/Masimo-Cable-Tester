#include "../Headers/global_consts_vars.h"

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