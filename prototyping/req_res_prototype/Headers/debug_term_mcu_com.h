#ifndef DEBUG_TERM_MCU_COM_H_
#define DEBUG_TERM_MCU_COM_H_

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "global_consts_vars.h"

void initUSART3();
void transmitTerminal(char* str);
void parseTerminalData(char* strData);
extern void transmitHmi(char* page, char* ID, char* field, char* value, uint8_t request);


#endif