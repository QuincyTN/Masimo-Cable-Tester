/*___________________________________________________________________________________________________

Title:
	utils.h v1.0

Description:
	Utility functions used by multiple libraries.
	
	For complete details visit
	https://www.programming-electronics-diy.xyz

Author:
 	Liviu Istrate
	istrateliviu24@yahoo.com
	
Donate:
	Software development takes time and effort so if you find this useful consider a small donation at:
	paypal.me/alientransducer
_____________________________________________________________________________________________________*/


/* ----------------------------- LICENSE - GNU GPL v3 -----------------------------------------------

* This license must be included in any redistribution.

* Copyright (c) 2022 Liviu Istrate, www.programming-electronics-diy.xyz (istrateliviu24@yahoo.com)

* Project URL: https://www.programming-electronics-diy.xyz

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.

* See <https://www.gnu.org/licenses/> for a copy of the GNU General Public License.

--------------------------------- END OF LICENSE --------------------------------------------------*/

/* Modified 6/15/24 G. Pohly
 * added a function to copy any type of data from one location to another
 * read info in function header for correct use 
 */

#ifndef UTILS_H_
#define UTILS_H_

/*************************************************************
	INCLUDE
**************************************************************/
#include <stdint.h>
#include <stdbool.h>

/*************************************************************
	USER DEFINED SETTINGS
**************************************************************/
// Used by functions that write numbers. Select between 32-bit and 64-bit types.
// If you need to display really huge numbers select 64-bit. 32-bit is faster though.
// Maximum number that can be used is 2^32 / 2 or 2^64 / 2
// Division by 2 is because one half is for negative and the other for positive.
// typedef int32_t INT_SIZE;						// can be int32_t (default) or int64_t
typedef int64_t INT_SIZE;						// 10/8/24 gwp - changed to uint64_t to accommodate SD info commands
#define MAX_NR_OF_DIGITS					12	// maximum digits a number can have

/*************************************************************
	FUNCTION PROTOTYPES
**************************************************************/
void STRING_itoa(INT_SIZE n, char s[], int8_t padding);
void STRING_ftoa(float float_nr, char s_int[], char s_float[], uint8_t padding, uint8_t decimals);
int MATH_abs(int i);
void arrayReverse(uint8_t s[], uint8_t lenght);
uint8_t STRING_tobyte(char s[]);		// converts a 2-digit ASCII numbers to a byte
uint16_t STRING_toint(char s[]);		// converts a 4-digit ASCII number to an int
uint8_t uSTRING_tobyte(char s[]);		// converts a numerical ASCII string to a byte
uint16_t uSTRING_toint(char s[]);		// converts a numerical ASCII string to an int
void copy_data(uint8_t *p1, uint8_t *p2, uint8_t count);	// unstructured copy from one memory location to another


#endif /* UTILS_H_ */