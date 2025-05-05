/*
 * utils.c
 *
 * Created: 2023-07-08 21:35:23
 *  Author: liviu
 *
 * Modified 6/15/24 G. Pohly
 * added a function to copy any type of data from one location to another
 * read info in function header for correct use 
 */ 

#include "utils.h"

/*************************************************************
	FUNCTIONS
**************************************************************/
/*______________________________________________________________________________________________
	Integer to string array conversion.
	String arrays must be defined as:
		char string_integer[MAX_NR_OF_DIGITS + 1];
	This allows itoa() to check if the number of digits fits the array.
	
	s[]				array pointer for the returned string
	
	nrOfDigits		Total number of digits desired. If the number to be displayed
					has less digits than "nrOfDigits" then it will be padded with zeros.
					Useful for maintaining the GUI layout and for displaying floats.
_______________________________________________________________________________________________*/
void STRING_itoa(INT_SIZE n, char s[], int8_t nrOfDigits){
	uint8_t str_len = 0;
	uint8_t idx = 0;
	INT_SIZE num_buf = n;
	bool is_negative = false;
	
	// Find number of digits
	while(num_buf != 0){
		str_len++;
		num_buf /= 10;
	}
	
	if(n == 0) str_len = 1;
	
	// Set padding with 0
	nrOfDigits -= str_len;
	if(nrOfDigits < 0) nrOfDigits = 0;
	
	// Check if number is negative and convert it to a positive
	if(n < 0){
		n = -n;
		str_len++; // placeholder for the minus sign
		is_negative = true;
	}

	idx = str_len + nrOfDigits;
	if(idx < MAX_NR_OF_DIGITS) s[idx] = 0; // add null terminator
	
	// Convert int to string array
	while(idx){
		idx--;
		
		// Trim the length of the number if it's bigger than the limit MAX_NR_OF_DIGITS
		if(idx < MAX_NR_OF_DIGITS){
			s[idx] = (n % 10) + '0';
		}

		n /= 10;
	}
	
	if(is_negative)	s[0] = '-';
}



/*______________________________________________________________________________________________
	Float number to string array conversion. The dot and negative sign are not added.
	String arrays must be defined as:
		char string_integer[MAX_NR_OF_DIGITS + 1];
		char string_float[MAX_NR_OF_DIGITS + 1];
	This allows itoa() to check if the number of digits fits the array.
	
	s_int[]			array pointer for the integer part
	s_float[]		array pointer for the decimal part
	nrOfDigits		see STRING_itoa()
	decimals		number of digits after the dot
_______________________________________________________________________________________________*/
void STRING_ftoa(float float_nr, char s_int[], char s_float[], uint8_t nrOfDigits, uint8_t decimals){
	uint8_t float_length = decimals;
	int32_t integer_part = 0;
	float rounding = 0.5;
	
	// Adjust the rounding value
	while(float_length){
		rounding /= 10.0;
		float_length--;
	}
	
	// Restore float length
	float_length = decimals;
	
	// Convert float part to positive
	if(float_nr < 0) float_nr = -float_nr;
	
	// Round up
	float_nr += rounding;
	
	// Get integer part
	integer_part = float_nr;
	
	// Get the decimal portion
	float_nr -= integer_part;
	
	// Convert fractional part to integer
	while(float_length){
		float_nr *= 10;
		float_length--;
	}
	
	STRING_itoa(integer_part, s_int, nrOfDigits);
	STRING_itoa(float_nr, s_float, decimals);
}



/*______________________________________________________________________________________________
	Return the absolute value of i (if the number is negative it will be converted to positive)
_______________________________________________________________________________________________*/
int MATH_abs(int i){
	return i < 0 ? -i : i;
}



/*______________________________________________________________________________________________
	Reverse the order of an array
	
	lenght		length of the array
_______________________________________________________________________________________________*/
void arrayReverse(uint8_t s[], uint8_t lenght){
	uint16_t i, j = lenght - 1;
	uint8_t c;
	
	// Reverse array
	for(i = 0; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


/* **************************************************************************
 *	convert restricted 2-digit ASCII number to a unsigned 8-bit number		*
 ****************************************************************************/
uint8_t STRING_tobyte(char s[]){
	// this is a very specific converter designed only for a two-digit ASCII number
	// to be converted to a decimal, such as converting date/time numbers in the 
	// middle of a terminal entered string such as "07/11/24."
	// It does not need and does not look for a null terminator; it will simply
	// convert the first two digits pointed to by *s regardless of whether they are 
	// legitimate ASCII numerals or not.
	return ((10*(s[0]-0x30)) + (s[1]-0x30));
}


/* **************************************************************************
 *	convert restricted 4-digit ASCII number to a unsigned 16-bit number		*
 ****************************************************************************/
uint16_t STRING_toint(char s[]){
	// this is a very specific converter designed only for a four-digit ASCII 
	// number to be converted to a decimal, such as converting a 4-digit ASCII 
	// year into the decimal equivalent.  
	// It does not need and does not look for a null terminator; it will simply
	// convert the first two digits pointed to by *s regardless of whether they are 
	// legitimate ASCII numerals or not. It will work even when the ASCII form 
	// of the number is in the middle of a string. 
	return (1000*(s[0]-0x30) + 100*(s[1]-0x30) + 10*(s[2]-0x30) + (s[3]-0x30));
}

/* **************************************************************************
 *	convert unrestricted 2-digit ASCII number to a unsigned 8-bit number	*
 ****************************************************************************/
uint8_t uSTRING_tobyte(char s[]){
	// This function will convert a free-form ASCII representation of a number
	// into the decimal equivalent.  It requires the number string to be terminated
	// in a NULL character (0x00), just like any other well-formed string.  It will 
	// error check the digits to be sure they are in the proper ASCII range for 
	// numerals.
	// Since a byte can be up to 0xFF = 256, this means the string could contain 
	// 1 to 3 base10 digits.  Must determine how long the string is and return 
	// the converted value based on that.  
	if (s[1] == 0x00){			// string is a single digit
		if ((s[0]<0x30) || (s[0]>0x39)) return 0;	// digit is out of range of an ascii numeral
		return (s[0]-0x30);
		}
	if (s[2] == 0x00){			// string is two digits
		if ((s[0]<0x30) || (s[0]>0x39) ||
			(s[1]<0x30) || (s[1]>0x39)) return 0;	// digit is out of range of an ascii numeral
		return ((10*(s[0]-0x30)) + (s[1]-0x30));
		}
	// if here, string must be three digits
	if ((s[0]<0x30) || (s[0]>0x39) ||
		(s[1]<0x30) || (s[1]>0x39) ||
		(s[2]<0x30) || (s[2]>0x39)) return 0;	// digit is out of range of an ascii numeral	
	return (100*(s[0]-0x30) + 10*(s[1]-0x30)+ (s[2]-0x30));
}

/* **************************************************************************
 *	convert unrestricted ASCII numbers to a unsigned 16-bit number			*
 ****************************************************************************/
uint16_t uSTRING_toint(char s[]){
	// This function will convert a free-form ASCII representation of a number
	// into the decimal equivalent.  It requires the number string to be terminated
	// in a NULL character (0x00), just like any other well-formed string.  It will 
	// error check the digits to be sure they are in the proper ASCII range for 
	// numerals.
	// Since an interger byte can be up to 0xFFFF = 65,535, this means the string 
	// could contain 1 to 5 base10 digits.  Must determine how long the string is 
	// and return the converted value based on that.  
	if (s[1] == 0x00){			// string is a single digit
		if ((s[0]<0x30) || (s[0]>0x39)) return 0;	// digit is out of range of an ascii numeral
		return (s[0]-0x30);
		}
	if (s[2] == 0x00){			// string is two digits
		if ((s[0]<0x30) || (s[0]>0x39) ||
			(s[1]<0x30) || (s[1]>0x39)) return 0;	// digit is out of range of an ascii numeral
		return ((10*(s[0]-0x30)) + (s[1]-0x30));
		}
	if (s[3] == 0x00){			// string is three digits
		if ((s[0]<0x30) || (s[0]>0x39) ||
			(s[1]<0x30) || (s[1]>0x39) ||
			(s[2]<0x30) || (s[2]>0x39)) return 0;	// digit is out of range of an ascii numeral	
		return (100*(s[0]-0x30) + 10*(s[1]-0x30)+ (s[2]-0x30));
		}
	if (s[4] == 0x00){			// string is four digits
		if ((s[0]<0x30) || (s[0]>0x39) ||
			(s[1]<0x30) || (s[1]>0x39) ||
			(s[2]<0x30) || (s[2]>0x39) ||
			(s[3]<0x30) || (s[3]>0x39)) return 0;	// digit is out of range of an ascii numeral	
		return (1000*(s[0]-0x30) + 100*(s[1]-0x30) + 10*(s[2]-0x30) + (s[3]-0x30));
		}
	// if here, string must be five digits
	if ((s[0]<0x30) || (s[0]>0x39) ||
		(s[1]<0x30) || (s[1]>0x39) ||
		(s[2]<0x30) || (s[2]>0x39) ||
		(s[3]<0x30) || (s[3]>0x39) ||
		(s[4]<0x30) || (s[4]>0x39)) return 0;	// digit is out of range of an ascii numeral	
	return (10000*(s[0]-0x30) + 1000*(s[1]-0x30) + 100*(s[2]-0x30)+ 10*(s[3]-0x30) + (s[4]-0x30));
}	

void copy_data(uint8_t *p1, uint8_t *p2, uint8_t count){
	// gwp 6/10/24
	// copies data from one memory location specified by *p2 to another specified by *p1.
	// Unlike most string functions, this will copy raw data based on two pointers and a 
	// count value. It's a lot faster than structure based or string based copy but its danger 
	// is it does not care what is in the memory location being copied to, so if the 
	// destination pointer or count that is passed into the function are incorrect it is likely
	// that some program or data memory will be unintentionally corrupted.
	// If used to copy strings, and count is obtained by a strlen() function, be sure to add 
	// 1 to the count because strlen() count does not include the NULL at the end of the string.
	uint8_t i=0;
	do{
		p1[i] = p2[i];
	}while(++i<count);
}