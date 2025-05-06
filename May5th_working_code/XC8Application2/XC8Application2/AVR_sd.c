/*___________________________________________________________________________________________________

Title:
	sd.c v2.0

Author:
 	Liviu Istrate
	istrateliviu24@yahoo.com
	www.programming-electronics-diy.xyz

Donate:
	Software development takes time and effort so if you find this useful consider a small donation at:
	paypal.me/alientransducer
_____________________________________________________________________________________________________*/


/* ----------------------------- LICENSE - GNU GPL v3 -----------------------------------------------

* This license must be included in any redistribution.

* Copyright (C) 2022 Liviu Istrate, www.programming-electronics-diy.xyz (istrateliviu24@yahoo.com)

* Project URL: https://www.programming-electronics-diy.xyz/2022/07/sd-memory-card-library-for-avr.html
* Inspired by: http://www.rjhcoding.com/avrc-sd-interface-1.php

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

#include "AVR_sd.h"

/*************************************************************
	GLOBALS
**************************************************************/
// Sectors below this value will not be written by the write functions.
// Protected sectors could include Boot Sectors, FATs, Root Directory.
//uint16_t SD_MaxProtectedSector; // not implemented as is not needed

uint8_t SD_Buffer[SD_BUFFER_SIZE + 1]; // reserve 1 byte for the null
uint8_t SD_ResponseToken;
static uint8_t SD_CardType;


/*************************************************************
	FUNCTION PROTOTYPES
**************************************************************/
static void sd_assert_cs(void);
static void sd_deassert_cs(void);
static SD_RETURN_CODES sd_command_ACMD41(void);
static uint8_t sd_read_response1(void);
static void sd_read_response3_7(uint8_t *res);
static void sd_command(uint8_t cmd, uint32_t arg, uint8_t crc);

static void SPI_Init(void);
static uint8_t SPI_ReceiveByte(void);
static void SPI_SendByte(uint8_t byte);
static void SPI_BusyCheck(void);


/*************************************************************
	FUNCTIONS
**************************************************************/

/*______________________________________________________________________________________________
	Initialize the SD card into SPI mode
	returns 0 on success or error code
________________________________________________________________________________________________*/
SD_RETURN_CODES sd_init(void){
	uint8_t SD_Response[5]; // array to hold response
	uint8_t cmdAttempts = 0;
	
	// SPI Setup
	SPI_Init();
		
		
	// Give SD card time to power up
	_delay_ms(1);
	
	// Send 80 clock cycles to synchronize
	// The card must be deselected during this time
	sd_deassert_cs();
	for(uint8_t i = 0; i < 10; i++) SPI_SendByte(0xFF);
	
	// Card powers up in SD Bus protocol mode and switch to SPI 
	// when the Chip Select line is driven low and CMD0 is sent.
	// In SPI mode CRCs are ignored but because they start in SD Bus mode
	// a correct checksum must be provided.
	
	// Send CMD0 (GO_IDLE_STATE) - R1 response
	// Resets the SD Memory Card
	// Argument is 0x00 for the reset command, precalculated checksum
	while(SD_Response[0] != 0x01){
		// Assert chip select
		sd_assert_cs();
		
		// Send CMD0
		sd_command(CMD0, CMD0_ARG, CMD0_CRC);
		
		// Read R1 response
		SD_Response[0] = sd_read_response1();
		
		// Send some dummy clocks after GO_IDLE_STATE
		// Deassert chip select
		sd_deassert_cs();
		
		cmdAttempts++;
		
		if(cmdAttempts > 10){
			SPI_CARD_CS_DISABLE();
			return SD_IDLE_STATE_TIMEOUT;
		}
	}

	
	// Send CMD8 - SEND_IF_COND (Send Interface Condition) - R7 response (or R1 for < V2 cards)
	// Sends SD Memory Card interface condition that includes host supply voltage information and asks the
	// accessed card whether card can operate in supplied voltage range.
	// Check whether the card is first generation or Version 2.00 (or later).
	// If the card is of first generation, it will respond with R1 with bit 2 set (illegal command)
	// otherwise the response will be 5 bytes long R7 type
	// Voltage Supplied (VHS) argument is set to 3.3V (0b0001)
	// Check Pattern argument is the recommended pattern '0b10101010'
	// CRC is 0b1000011 and is precalculated
	sd_assert_cs();
	sd_command(CMD8, CMD8_ARG, CMD8_CRC);
	sd_read_response3_7(SD_Response);
	sd_deassert_cs();
	
	// Select initialization sequence path
	if(SD_Response[0] == 0x01){
		// The card is Version 2.00 (or later) or SD memory card, can speed up SPI clock
		
		// Enable maximum SPI speed - Version 2 and later cards can support minimum 8MHz clock
		_SPCRA &= ~SPI_PRESC_gm;		// fosc/4, assuming 16MHz F_CPU, then this is 4MHz
		_SPCRB |= SPI_CLK2X_bm;			// SPI speed (SCK frequency) is doubled in Master mode to 8MHz
		
		// Check voltage range
		if(SD_Response[3] != 0x01){
			return SD_NONCOMPATIBLE_VOLTAGE_RANGE;
		}
		
		// Check echo pattern
		if(SD_Response[4] != 0xAA){
			return SD_CHECK_PATTERN_MISMATCH;
		}
		
		// CMD58 - read OCR (Operation Conditions Register) - R3 response
		// Reads the OCR register of a card
		sd_assert_cs();
		sd_command(CMD58, CMD58_ARG, CMD58_CRC);
		sd_read_response3_7(SD_Response);
		sd_deassert_cs();
		
		// ACMD41 - starts the initialization process - R1 response
		// Continue to send ACMD41 (always preceded by CMD55) until the card responds 
		// with 'in_idle_state', which is R1 = 0x00.
		if(sd_command_ACMD41() > 0) return SD_IDLE_STATE_TIMEOUT;
		
		// CMD58 - read OCR (Operation Conditions Register) - R3 response
		sd_assert_cs();
		sd_command(CMD58, CMD58_ARG, CMD58_CRC);
		sd_read_response3_7(SD_Response);
		sd_deassert_cs();
		
		// Check if the card is ready
		// Read bit OCR 31 in R3
		if(!(SD_Response[1] & 0x80)){
			return SD_POWER_UP_BIT_NOT_SET;
		}
		
		// Read CCS bit OCR 30 in R3
		if(SD_Response[1] & 0x40){
			// SDXC or SDHC card
			SD_CardType = SD_V2_SDHC_SDXC;
		}else{
			// SDSC
			SD_CardType = SD_V2_SDSC;
		}
		
	}else if(SD_Response[0] == 0x05){
		// Response code 0x05 = Idle State + Illegal Command indicates
		// the card is of first generation. SD or MMC card.
		SD_CardType = SD_V1_SDSC;
		
		// ACMD41
		SD_Response[0] = sd_command_ACMD41();
		if(ILLEGAL_CMD(SD_Response[0])) return SD_NOT_SD_CARD;
		if(SD_Response[0]) return SD_IDLE_STATE_TIMEOUT;
		
	}else{
		return SD_GENERAL_ERROR;
	}
	
	
	// Read and write operations are performed on SD cards in blocks of set lengths. 
	// Block length can be set in Standard Capacity SD cards using CMD16 (SET_BLOCKLEN). 
	// For SDHC and SDXC cards the block length is always set to 512 bytes.
	
	return SD_OK;
}



/*______________________________________________________________________________________________
	Write a single block of data
				
	addr	32-bit address. SDHC and SDXC are block addressed, meaning an address of 0 
			will read back bytes 0-511, address 1 will read back 512-1023, etc.
			With 32 bits to specify a 512 byte block, the maximum size a card can support is 
			(2^32)*512 = 2048 megabytes or 2 terabytes.
					
	buff	512 bytes of data to write
	
	token	0x00 - busy timeout
			0x05 - data accepted
			0xFF - response timeout
_______________________________________________________________________________________________*/
uint8_t sd_write_single_block(uint32_t addr, uint8_t *buf){
	uint8_t res1;
	uint32_t readAttempts;
	
	if(SD_CardType == SD_V1_SDSC) addr *= 512;

	// set token to none
	SD_ResponseToken = 0xFF;

	sd_assert_cs();
	sd_command(CMD24, addr, CMD24_CRC);

	// read response
	res1 = sd_read_response1();

	// if no error
	if(res1 == 0){
		// send start token
		SPI_SendByte(0xFE);

		// write buffer to card
		for(uint16_t i = 0; i < SD_BUFFER_SIZE; i++) SPI_SendByte(buf[i]);

		// wait for a response (timeout = 250ms)
		// maximum timeout is defined as 250 ms for all write operations
		readAttempts = 0;
		while(++readAttempts < SD_MAX_WRITE_ATTEMPTS){
			if((res1 = SPI_ReceiveByte()) != 0xFF) break;
		}

		// if data accepted
		if((res1 & 0x1F) == 0x05){
			// set token to data accepted
			SD_ResponseToken = 0x05;

			// wait for write to finish (timeout = 250ms)
			readAttempts = 0;
			while(SPI_ReceiveByte() == 0x00){
				if(++readAttempts > SD_MAX_WRITE_ATTEMPTS){
					SD_ResponseToken = 0x00;
					break;
				}
			}
		}
	}

	sd_deassert_cs();
	return res1;
}


/*______________________________________________________________________________________________
	Read a single block of data
				
	addr	32-bit address. SDHC and SDXC are block addressed, meaning an address of 0 
			will read back bytes 0-511, address 1 will read back 512-1023, etc.
			With 32 bits to specify a 512 byte block, the maximum size a card can support is 
			(2^32)*512 = 2048 megabytes or 2 terabytes.
					
	buff	a buffer of at least 512 bytes to store the data in
	
	token	0xFE - Successful read
			0x0X - Data error (Note that some cards don't return an error token instead timeout will occur)
			0xFF - Timeout
_______________________________________________________________________________________________*/
uint8_t sd_read_single_block(uint32_t addr, uint8_t *buf){
	uint8_t res1, read = 0;
	uint32_t readAttempts;
	
	if(SD_CardType == SD_V1_SDSC) addr *= 512;

	// set token to none
	SD_ResponseToken = 0xFF;

	sd_assert_cs();
	sd_command(CMD17, addr, CMD17_CRC);

	// read R1
	res1 = sd_read_response1();

	// if response received from card
	if(res1 != 0xFF){
		// wait for a response token (timeout = 100ms)
		// The host should use 100ms timeout (minimum) for single and multiple read operations
		readAttempts = 0;
		while(++readAttempts != SD_MAX_READ_ATTEMPTS){
			if((read = SPI_ReceiveByte()) != 0xFF) break;
		}

		// if response token is 0xFE
		if(read == 0xFE){
			// read 512 byte block
			for(uint16_t i = 0; i < SD_BUFFER_SIZE; i++) *buf++ = SPI_ReceiveByte();
			
			// add null to the end
			*buf = 0;

			// read and discard 16-bit CRC
			SPI_ReceiveByte();
			SPI_ReceiveByte();
		}

		// set token to card response
		SD_ResponseToken = read;
	}

	sd_deassert_cs();
	return res1;
}


/*______________________________________________________________________________________________
	Returns the inverted state of the card detect pin which is high when a card in not present.
	
	return	0 - card not detected, 1 - card detected
_______________________________________________________________________________________________*/
bool sd_detected(void){
	#if CARD_DETECT_SENSE == 1
		return ((CARD_DETECT_PORT.IN & CARD_DETECT_PIN) != 0);  // SD card inserted sets CD high
	#else
		return ((CARD_DETECT_PORT.IN & CARD_DETECT_PIN) == 0);	// SD card inserted set CD low
	#endif
}


/*______________________________________________________________________________________________
	Assert Chip Select Line by sending a byte before and after changing the CS line
_______________________________________________________________________________________________*/
static void sd_assert_cs(void){
	SPI_SendByte(0xFF);
	SPI_CARD_CS_ENABLE();
	SPI_SendByte(0xFF);
}


/*______________________________________________________________________________________________
	De-Assert Chip 
	Line by sending a byte before and after changing the CS line
_______________________________________________________________________________________________*/
static void sd_deassert_cs(void){
	SPI_SendByte(0xFF);
	SPI_CARD_CS_DISABLE();
	SPI_SendByte(0xFF);
}


/*______________________________________________________________________________________________
	Send ACMD41 - Sends host capacity support information and activates the card's
	initialization process. Reserved bits shall be set to '0'.
_______________________________________________________________________________________________*/
static SD_RETURN_CODES sd_command_ACMD41(void){
	uint8_t response;
	uint8_t i = 100;
	
	// Initialization process can take up to 1 second so we add a 10ms delay
	// and a maximum of 100 iterations
	
	do{
		// CMD55 - APP_CMD - R1 response
		sd_assert_cs();
		sd_command(CMD55, CMD55_ARG, CMD55_CRC);
		sd_read_response1();
		sd_deassert_cs();
		
		// ACMD41 - SD_SEND_OP_COND (Send Operating Condition) - R1 response
		sd_assert_cs();
		
		if(SD_CardType == SD_V1_SDSC)
			sd_command(ACMD41, 0, ACMD41_CRC);
		else
			sd_command(ACMD41, ACMD41_ARG, ACMD41_CRC);
		
		response = sd_read_response1();
		sd_deassert_cs();
		
		i--;
		_delay_ms(10);
		
	}while((response != 0) && (i > 0));
	
	// Timeout
	if(i == 0) return SD_IDLE_STATE_TIMEOUT;
	
	return response;
}



/*______________________________________________________________________________________________
	Wait for a response from the card other than 0xFF which is the normal state of the
	MISO line. Timeout occurs after 16 bytes.
			
	return		response code
_______________________________________________________________________________________________*/
static uint8_t sd_read_response1(void){
	uint8_t i = 0, response = 0xFF;

	// Keep polling until actual data received
	while((response = SPI_ReceiveByte()) == 0xFF){
		i++;

		// If no data received for 16 bytes, break
		if(i > 16) break;
	}

	return response;
}



/*______________________________________________________________________________________________
	Read Response 3 or 7 which is 5 bytes long
				
	res			Pointer to a 5 bytes array
_______________________________________________________________________________________________*/
static void sd_read_response3_7(uint8_t *res){
	res[0] = sd_read_response1(); // read response 1 in R3 or R7
	
	if(res[0] > 1) return; // if error reading R1, return
	
	res[1] = SPI_ReceiveByte();
	res[2] = SPI_ReceiveByte();
	res[3] = SPI_ReceiveByte();
	res[4] = SPI_ReceiveByte();
}


/*______________________________________________________________________________________________
	Send a command to the card
				
	cmd			8-bit command index
	arg			a 32-bit argument
	crc			an 8-bit CRC
_______________________________________________________________________________________________*/
static void sd_command(uint8_t cmd, uint32_t arg, uint8_t crc){
	// Transmit command
	SPI_SendByte(cmd | 0x40);

	// Transmit argument
	SPI_SendByte((uint8_t)(arg >> 24));
	SPI_SendByte((uint8_t)(arg >> 16));
	SPI_SendByte((uint8_t)(arg >> 8));
	SPI_SendByte((uint8_t)(arg));

	// Transmit CRC
	SPI_SendByte(crc | 0x01);
}



/*______________________________________________________________________________________________
	SPI - Initialization
_______________________________________________________________________________________________*/
static void SPI_Init(void){
	
	// SPI control B - disable SS pin, use as IO CS pin instead
	
	_SPCRB =	  SPI_SSD_bm		// no buffering, SS diasbled
				| SPI_MODE_0_gc;	// MODE 0:
									// Leading edge: Rising, sample									// Trailing edge: Falling, setup
	// setup AVR pins
	// set CS pin and disable (set high) before enabling SPI
	CARD_CS_PORT.DIR	 |= CARD_CS_PIN;		// CS as output
	CARD_DETECT_PORT.DIR &= ~CARD_DETECT_PIN;	// CD pin as input
	
	//I uncommented the comment below
	//CARD_DETECT_PORT.PIN3CTRL |= PORT_PULLUPEN_bm;  // enable pullup on card detect
	//I commented the comment above
	
	SPI_MOSI_PORT.DIR	 |= SPI_MOSI_PIN;		// MOSI as output
	SPI_MISO_PORT.DIR	 &= ~SPI_MISO_PIN;		// MISO as input
	SPI_SCK_PORT.DIR	 |= SPI_SCK_PIN;		// SCK as output
	// SPI_SS_PORT.DIR		 |= SPI_SS_PIN;		// SS not used in Master mode, single SPI
	
	// SET CS high before enabling SPI
	CARD_CS_PORT.OUT	 |= CARD_CS_PIN;
	
	// The MSB of the data word is transmitted first
	// Start with a lower speed for older cards (100-400kHz)
	//  Enable SPI, Master, set mode 3, set clock rate fck/32
	_SPCRA =	//  SPI_DORD_bm			// 0 is MSB first
				  SPI_MASTER_bm			// 1 for master/host, 0 for slave/client
				| SPI_ENABLE_bm			// 1 to enable SPI	
				//| SPI_CLK2X_bm		// start at slower speed until we know the class of the SD card
				| SPI_PRESC_DIV64_gc;	// 16MHz CPU/64 = 250KHz initial SPI clock rate
										// this is sped up later if detect newer card can handle speed
	
}


/*______________________________________________________________________________________________
	SPI - Send a block of data based on the data length
				
	buf			Data to send
	length		Number of bytes
_______________________________________________________________________________________________*/
void SPI_Send(uint8_t *buf, uint16_t length){
	while(length != 0){
		
		// SPI0.DATA = *buf;
		_SPDR = *buf;
		
		// Wait until the Busy bit is cleared
		SPI_BusyCheck();
		
		length--;
		buf++;
	}
}


/*______________________________________________________________________________________________
	SPI - Send a byte
_______________________________________________________________________________________________*/
static void SPI_SendByte(uint8_t byte){
	
	// SPI0.DATA = byte;
	_SPDR = byte;
		
	// Wait until the Busy bit is cleared
	SPI_BusyCheck();
}


/*______________________________________________________________________________________________
	SPI - Receives a block of data based on the length
				
	buf			Pointer to an array where to receive the data
	length		Number of bytes
_______________________________________________________________________________________________*/
void SPI_Receive(uint8_t *buf, uint16_t length){
	for(uint16_t i = 0; i < length; i++){
		*buf = SPI_ReceiveByte();
		buf++;
	}
}


/*______________________________________________________________________________________________
	SPI - Receive and returns one byte only
_______________________________________________________________________________________________*/
static uint8_t SPI_ReceiveByte(void){
	
		// Write dummy byte out to generate clock, then read data from MISO
		// SPI0.DATA = 0xFF;
		_SPDR = 0xFF;
		
		// Wait until the Busy bit is cleared
		SPI_BusyCheck();

		// return SPI0.DATA;
		return _SPDR;
	// #endif
}


/*______________________________________________________________________________________________
	SPI - Wait until the Busy bit is cleared
_______________________________________________________________________________________________*/
static void SPI_BusyCheck(void){
	// while(!(SPI0.INTFLAGS & (SPI_IF_bm)));
	while(!(_SPSR & SPI_IF_bm));
}