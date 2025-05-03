#ifndef HMI_MCU_COM_H_
#define HMI_MCU_COM_H_

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "global_consts_vars.h"

void initUSART1();
void transmitHmi(char* page, char* ID, char* field, char* value, uint8_t action);
char* parseHmiString(char* string);
uint32_t parseHmiInt(char* string);
void parseHmiData(char* strData);
void getTime();
extern void transmitTerminal(char* str);

#endif