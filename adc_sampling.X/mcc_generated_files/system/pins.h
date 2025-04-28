/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.1.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set IO_PB1 aliases
#define IO_PB1_SetHigh() do { PORTB_OUTSET = 0x2; } while(0)
#define IO_PB1_SetLow() do { PORTB_OUTCLR = 0x2; } while(0)
#define IO_PB1_Toggle() do { PORTB_OUTTGL = 0x2; } while(0)
#define IO_PB1_GetValue() (VPORTB.IN & (0x1 << 1))
#define IO_PB1_SetDigitalInput() do { PORTB_DIRCLR = 0x2; } while(0)
#define IO_PB1_SetDigitalOutput() do { PORTB_DIRSET = 0x2; } while(0)
#define IO_PB1_SetPullUp() do { PORTB_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PB1_ResetPullUp() do { PORTB_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PB1_SetInverted() do { PORTB_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PB1_ResetInverted() do { PORTB_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PB1_DisableInterruptOnChange() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PB1_EnableInterruptForBothEdges() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PB1_EnableInterruptForRisingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PB1_EnableInterruptForFallingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PB1_DisableDigitalInputBuffer() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PB1_EnableInterruptForLowLevelSensing() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB1_SetInterruptHandler IO_PB1_SetInterruptHandler

//get/set IO_PB0 aliases
#define IO_PB0_SetHigh() do { PORTB_OUTSET = 0x1; } while(0)
#define IO_PB0_SetLow() do { PORTB_OUTCLR = 0x1; } while(0)
#define IO_PB0_Toggle() do { PORTB_OUTTGL = 0x1; } while(0)
#define IO_PB0_GetValue() (VPORTB.IN & (0x1 << 0))
#define IO_PB0_SetDigitalInput() do { PORTB_DIRCLR = 0x1; } while(0)
#define IO_PB0_SetDigitalOutput() do { PORTB_DIRSET = 0x1; } while(0)
#define IO_PB0_SetPullUp() do { PORTB_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PB0_ResetPullUp() do { PORTB_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PB0_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PB0_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PB0_DisableInterruptOnChange() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PB0_EnableInterruptForBothEdges() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PB0_EnableInterruptForRisingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PB0_EnableInterruptForFallingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PB0_DisableDigitalInputBuffer() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PB0_EnableInterruptForLowLevelSensing() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB0_SetInterruptHandler IO_PB0_SetInterruptHandler

//get/set CTR_1 aliases
#define CTR_1_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define CTR_1_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define CTR_1_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define CTR_1_GetValue() (VPORTA.IN & (0x1 << 7))
#define CTR_1_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define CTR_1_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define CTR_1_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_1_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_1_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_1_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_1_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_1_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_1_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_1_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_1_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_1_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA7_SetInterruptHandler CTR_1_SetInterruptHandler

//get/set CTR_2 aliases
#define CTR_2_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define CTR_2_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define CTR_2_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define CTR_2_GetValue() (VPORTB.IN & (0x1 << 2))
#define CTR_2_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define CTR_2_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define CTR_2_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_2_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_2_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_2_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_2_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_2_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_2_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_2_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_2_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_2_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB2_SetInterruptHandler CTR_2_SetInterruptHandler

//get/set CTR_3 aliases
#define CTR_3_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define CTR_3_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define CTR_3_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define CTR_3_GetValue() (VPORTB.IN & (0x1 << 3))
#define CTR_3_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define CTR_3_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define CTR_3_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_3_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_3_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_3_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_3_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_3_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_3_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_3_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_3_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_3_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB3_SetInterruptHandler CTR_3_SetInterruptHandler

//get/set CTR_4 aliases
#define CTR_4_SetHigh() do { PORTB_OUTSET = 0x10; } while(0)
#define CTR_4_SetLow() do { PORTB_OUTCLR = 0x10; } while(0)
#define CTR_4_Toggle() do { PORTB_OUTTGL = 0x10; } while(0)
#define CTR_4_GetValue() (VPORTB.IN & (0x1 << 4))
#define CTR_4_SetDigitalInput() do { PORTB_DIRCLR = 0x10; } while(0)
#define CTR_4_SetDigitalOutput() do { PORTB_DIRSET = 0x10; } while(0)
#define CTR_4_SetPullUp() do { PORTB_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_4_ResetPullUp() do { PORTB_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_4_SetInverted() do { PORTB_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_4_ResetInverted() do { PORTB_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_4_DisableInterruptOnChange() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_4_EnableInterruptForBothEdges() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_4_EnableInterruptForRisingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_4_EnableInterruptForFallingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_4_DisableDigitalInputBuffer() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_4_EnableInterruptForLowLevelSensing() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB4_SetInterruptHandler CTR_4_SetInterruptHandler

//get/set CTR_5 aliases
#define CTR_5_SetHigh() do { PORTB_OUTSET = 0x20; } while(0)
#define CTR_5_SetLow() do { PORTB_OUTCLR = 0x20; } while(0)
#define CTR_5_Toggle() do { PORTB_OUTTGL = 0x20; } while(0)
#define CTR_5_GetValue() (VPORTB.IN & (0x1 << 5))
#define CTR_5_SetDigitalInput() do { PORTB_DIRCLR = 0x20; } while(0)
#define CTR_5_SetDigitalOutput() do { PORTB_DIRSET = 0x20; } while(0)
#define CTR_5_SetPullUp() do { PORTB_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_5_ResetPullUp() do { PORTB_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_5_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_5_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_5_DisableInterruptOnChange() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_5_EnableInterruptForBothEdges() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_5_EnableInterruptForRisingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_5_EnableInterruptForFallingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_5_DisableDigitalInputBuffer() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_5_EnableInterruptForLowLevelSensing() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB5_SetInterruptHandler CTR_5_SetInterruptHandler

//get/set CTR_6 aliases
#define CTR_6_SetHigh() do { PORTB_OUTSET = 0x40; } while(0)
#define CTR_6_SetLow() do { PORTB_OUTCLR = 0x40; } while(0)
#define CTR_6_Toggle() do { PORTB_OUTTGL = 0x40; } while(0)
#define CTR_6_GetValue() (VPORTB.IN & (0x1 << 6))
#define CTR_6_SetDigitalInput() do { PORTB_DIRCLR = 0x40; } while(0)
#define CTR_6_SetDigitalOutput() do { PORTB_DIRSET = 0x40; } while(0)
#define CTR_6_SetPullUp() do { PORTB_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_6_ResetPullUp() do { PORTB_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_6_SetInverted() do { PORTB_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_6_ResetInverted() do { PORTB_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_6_DisableInterruptOnChange() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_6_EnableInterruptForBothEdges() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_6_EnableInterruptForRisingEdge() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_6_EnableInterruptForFallingEdge() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_6_DisableDigitalInputBuffer() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_6_EnableInterruptForLowLevelSensing() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB6_SetInterruptHandler CTR_6_SetInterruptHandler

//get/set CTR_7 aliases
#define CTR_7_SetHigh() do { PORTB_OUTSET = 0x80; } while(0)
#define CTR_7_SetLow() do { PORTB_OUTCLR = 0x80; } while(0)
#define CTR_7_Toggle() do { PORTB_OUTTGL = 0x80; } while(0)
#define CTR_7_GetValue() (VPORTB.IN & (0x1 << 7))
#define CTR_7_SetDigitalInput() do { PORTB_DIRCLR = 0x80; } while(0)
#define CTR_7_SetDigitalOutput() do { PORTB_DIRSET = 0x80; } while(0)
#define CTR_7_SetPullUp() do { PORTB_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_7_ResetPullUp() do { PORTB_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_7_SetInverted() do { PORTB_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_7_ResetInverted() do { PORTB_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_7_DisableInterruptOnChange() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_7_EnableInterruptForBothEdges() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_7_EnableInterruptForRisingEdge() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_7_EnableInterruptForFallingEdge() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_7_DisableDigitalInputBuffer() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_7_EnableInterruptForLowLevelSensing() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB7_SetInterruptHandler CTR_7_SetInterruptHandler

//get/set CTR_8 aliases
#define CTR_8_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define CTR_8_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define CTR_8_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define CTR_8_GetValue() (VPORTC.IN & (0x1 << 2))
#define CTR_8_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define CTR_8_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define CTR_8_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_8_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_8_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_8_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_8_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_8_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_8_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_8_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_8_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_8_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC2_SetInterruptHandler CTR_8_SetInterruptHandler

//get/set CTR_9 aliases
#define CTR_9_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define CTR_9_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define CTR_9_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define CTR_9_GetValue() (VPORTC.IN & (0x1 << 3))
#define CTR_9_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define CTR_9_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define CTR_9_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_9_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_9_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_9_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_9_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_9_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_9_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_9_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_9_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_9_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC3_SetInterruptHandler CTR_9_SetInterruptHandler

//get/set CTR_10 aliases
#define CTR_10_SetHigh() do { PORTC_OUTSET = 0x10; } while(0)
#define CTR_10_SetLow() do { PORTC_OUTCLR = 0x10; } while(0)
#define CTR_10_Toggle() do { PORTC_OUTTGL = 0x10; } while(0)
#define CTR_10_GetValue() (VPORTC.IN & (0x1 << 4))
#define CTR_10_SetDigitalInput() do { PORTC_DIRCLR = 0x10; } while(0)
#define CTR_10_SetDigitalOutput() do { PORTC_DIRSET = 0x10; } while(0)
#define CTR_10_SetPullUp() do { PORTC_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_10_ResetPullUp() do { PORTC_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_10_SetInverted() do { PORTC_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_10_ResetInverted() do { PORTC_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_10_DisableInterruptOnChange() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_10_EnableInterruptForBothEdges() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_10_EnableInterruptForRisingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_10_EnableInterruptForFallingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_10_DisableDigitalInputBuffer() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_10_EnableInterruptForLowLevelSensing() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC4_SetInterruptHandler CTR_10_SetInterruptHandler

//get/set CTR_11 aliases
#define CTR_11_SetHigh() do { PORTC_OUTSET = 0x20; } while(0)
#define CTR_11_SetLow() do { PORTC_OUTCLR = 0x20; } while(0)
#define CTR_11_Toggle() do { PORTC_OUTTGL = 0x20; } while(0)
#define CTR_11_GetValue() (VPORTC.IN & (0x1 << 5))
#define CTR_11_SetDigitalInput() do { PORTC_DIRCLR = 0x20; } while(0)
#define CTR_11_SetDigitalOutput() do { PORTC_DIRSET = 0x20; } while(0)
#define CTR_11_SetPullUp() do { PORTC_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_11_ResetPullUp() do { PORTC_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_11_SetInverted() do { PORTC_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_11_ResetInverted() do { PORTC_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_11_DisableInterruptOnChange() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_11_EnableInterruptForBothEdges() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_11_EnableInterruptForRisingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_11_EnableInterruptForFallingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_11_DisableDigitalInputBuffer() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_11_EnableInterruptForLowLevelSensing() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC5_SetInterruptHandler CTR_11_SetInterruptHandler

//get/set CTR_12 aliases
#define CTR_12_SetHigh() do { PORTC_OUTSET = 0x40; } while(0)
#define CTR_12_SetLow() do { PORTC_OUTCLR = 0x40; } while(0)
#define CTR_12_Toggle() do { PORTC_OUTTGL = 0x40; } while(0)
#define CTR_12_GetValue() (VPORTC.IN & (0x1 << 6))
#define CTR_12_SetDigitalInput() do { PORTC_DIRCLR = 0x40; } while(0)
#define CTR_12_SetDigitalOutput() do { PORTC_DIRSET = 0x40; } while(0)
#define CTR_12_SetPullUp() do { PORTC_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_12_ResetPullUp() do { PORTC_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_12_SetInverted() do { PORTC_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_12_ResetInverted() do { PORTC_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_12_DisableInterruptOnChange() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_12_EnableInterruptForBothEdges() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_12_EnableInterruptForRisingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_12_EnableInterruptForFallingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_12_DisableDigitalInputBuffer() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_12_EnableInterruptForLowLevelSensing() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC6_SetInterruptHandler CTR_12_SetInterruptHandler

//get/set CTR_13 aliases
#define CTR_13_SetHigh() do { PORTC_OUTSET = 0x80; } while(0)
#define CTR_13_SetLow() do { PORTC_OUTCLR = 0x80; } while(0)
#define CTR_13_Toggle() do { PORTC_OUTTGL = 0x80; } while(0)
#define CTR_13_GetValue() (VPORTC.IN & (0x1 << 7))
#define CTR_13_SetDigitalInput() do { PORTC_DIRCLR = 0x80; } while(0)
#define CTR_13_SetDigitalOutput() do { PORTC_DIRSET = 0x80; } while(0)
#define CTR_13_SetPullUp() do { PORTC_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_13_ResetPullUp() do { PORTC_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_13_SetInverted() do { PORTC_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_13_ResetInverted() do { PORTC_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_13_DisableInterruptOnChange() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_13_EnableInterruptForBothEdges() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_13_EnableInterruptForRisingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_13_EnableInterruptForFallingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_13_DisableDigitalInputBuffer() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_13_EnableInterruptForLowLevelSensing() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC7_SetInterruptHandler CTR_13_SetInterruptHandler

//get/set AIN_1 aliases
#define AIN_1_SetHigh() do { PORTD_OUTSET = 0x1; } while(0)
#define AIN_1_SetLow() do { PORTD_OUTCLR = 0x1; } while(0)
#define AIN_1_Toggle() do { PORTD_OUTTGL = 0x1; } while(0)
#define AIN_1_GetValue() (VPORTD.IN & (0x1 << 0))
#define AIN_1_SetDigitalInput() do { PORTD_DIRCLR = 0x1; } while(0)
#define AIN_1_SetDigitalOutput() do { PORTD_DIRSET = 0x1; } while(0)
#define AIN_1_SetPullUp() do { PORTD_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_1_ResetPullUp() do { PORTD_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_1_SetInverted() do { PORTD_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_1_ResetInverted() do { PORTD_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_1_DisableInterruptOnChange() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_1_EnableInterruptForBothEdges() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_1_EnableInterruptForRisingEdge() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_1_EnableInterruptForFallingEdge() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_1_DisableDigitalInputBuffer() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_1_EnableInterruptForLowLevelSensing() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD0_SetInterruptHandler AIN_1_SetInterruptHandler

//get/set AIN_2 aliases
#define AIN_2_SetHigh() do { PORTD_OUTSET = 0x2; } while(0)
#define AIN_2_SetLow() do { PORTD_OUTCLR = 0x2; } while(0)
#define AIN_2_Toggle() do { PORTD_OUTTGL = 0x2; } while(0)
#define AIN_2_GetValue() (VPORTD.IN & (0x1 << 1))
#define AIN_2_SetDigitalInput() do { PORTD_DIRCLR = 0x2; } while(0)
#define AIN_2_SetDigitalOutput() do { PORTD_DIRSET = 0x2; } while(0)
#define AIN_2_SetPullUp() do { PORTD_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_2_ResetPullUp() do { PORTD_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_2_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_2_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_2_DisableInterruptOnChange() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_2_EnableInterruptForBothEdges() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_2_EnableInterruptForRisingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_2_EnableInterruptForFallingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_2_DisableDigitalInputBuffer() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_2_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD1_SetInterruptHandler AIN_2_SetInterruptHandler

//get/set AIN_3 aliases
#define AIN_3_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define AIN_3_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define AIN_3_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define AIN_3_GetValue() (VPORTD.IN & (0x1 << 2))
#define AIN_3_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define AIN_3_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define AIN_3_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_3_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_3_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_3_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_3_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_3_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_3_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_3_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_3_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_3_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD2_SetInterruptHandler AIN_3_SetInterruptHandler

//get/set AIN_4 aliases
#define AIN_4_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define AIN_4_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define AIN_4_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define AIN_4_GetValue() (VPORTD.IN & (0x1 << 3))
#define AIN_4_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define AIN_4_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define AIN_4_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_4_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_4_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_4_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_4_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_4_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_4_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_4_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_4_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_4_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD3_SetInterruptHandler AIN_4_SetInterruptHandler

//get/set AIN_5 aliases
#define AIN_5_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define AIN_5_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define AIN_5_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define AIN_5_GetValue() (VPORTD.IN & (0x1 << 4))
#define AIN_5_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define AIN_5_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define AIN_5_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_5_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_5_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_5_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_5_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_5_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_5_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_5_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_5_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_5_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD4_SetInterruptHandler AIN_5_SetInterruptHandler

//get/set AIN_6 aliases
#define AIN_6_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define AIN_6_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define AIN_6_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define AIN_6_GetValue() (VPORTD.IN & (0x1 << 5))
#define AIN_6_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define AIN_6_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define AIN_6_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_6_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_6_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_6_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_6_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_6_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_6_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_6_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_6_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_6_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD5_SetInterruptHandler AIN_6_SetInterruptHandler

//get/set AIN_7 aliases
#define AIN_7_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define AIN_7_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define AIN_7_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define AIN_7_GetValue() (VPORTD.IN & (0x1 << 6))
#define AIN_7_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define AIN_7_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define AIN_7_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_7_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_7_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_7_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_7_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_7_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_7_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_7_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_7_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_7_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD6_SetInterruptHandler AIN_7_SetInterruptHandler

//get/set AIN_8 aliases
#define AIN_8_SetHigh() do { PORTD_OUTSET = 0x80; } while(0)
#define AIN_8_SetLow() do { PORTD_OUTCLR = 0x80; } while(0)
#define AIN_8_Toggle() do { PORTD_OUTTGL = 0x80; } while(0)
#define AIN_8_GetValue() (VPORTD.IN & (0x1 << 7))
#define AIN_8_SetDigitalInput() do { PORTD_DIRCLR = 0x80; } while(0)
#define AIN_8_SetDigitalOutput() do { PORTD_DIRSET = 0x80; } while(0)
#define AIN_8_SetPullUp() do { PORTD_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_8_ResetPullUp() do { PORTD_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_8_SetInverted() do { PORTD_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_8_ResetInverted() do { PORTD_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_8_DisableInterruptOnChange() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_8_EnableInterruptForBothEdges() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_8_EnableInterruptForRisingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_8_EnableInterruptForFallingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_8_DisableDigitalInputBuffer() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_8_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD7_SetInterruptHandler AIN_8_SetInterruptHandler

//get/set AIN_9 aliases
#define AIN_9_SetHigh() do { PORTE_OUTSET = 0x1; } while(0)
#define AIN_9_SetLow() do { PORTE_OUTCLR = 0x1; } while(0)
#define AIN_9_Toggle() do { PORTE_OUTTGL = 0x1; } while(0)
#define AIN_9_GetValue() (VPORTE.IN & (0x1 << 0))
#define AIN_9_SetDigitalInput() do { PORTE_DIRCLR = 0x1; } while(0)
#define AIN_9_SetDigitalOutput() do { PORTE_DIRSET = 0x1; } while(0)
#define AIN_9_SetPullUp() do { PORTE_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_9_ResetPullUp() do { PORTE_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_9_SetInverted() do { PORTE_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_9_ResetInverted() do { PORTE_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_9_DisableInterruptOnChange() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_9_EnableInterruptForBothEdges() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_9_EnableInterruptForRisingEdge() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_9_EnableInterruptForFallingEdge() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_9_DisableDigitalInputBuffer() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_9_EnableInterruptForLowLevelSensing() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE0_SetInterruptHandler AIN_9_SetInterruptHandler

//get/set AIN_910 aliases
#define AIN_910_SetHigh() do { PORTE_OUTSET = 0x2; } while(0)
#define AIN_910_SetLow() do { PORTE_OUTCLR = 0x2; } while(0)
#define AIN_910_Toggle() do { PORTE_OUTTGL = 0x2; } while(0)
#define AIN_910_GetValue() (VPORTE.IN & (0x1 << 1))
#define AIN_910_SetDigitalInput() do { PORTE_DIRCLR = 0x2; } while(0)
#define AIN_910_SetDigitalOutput() do { PORTE_DIRSET = 0x2; } while(0)
#define AIN_910_SetPullUp() do { PORTE_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_910_ResetPullUp() do { PORTE_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_910_SetInverted() do { PORTE_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_910_ResetInverted() do { PORTE_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_910_DisableInterruptOnChange() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_910_EnableInterruptForBothEdges() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_910_EnableInterruptForRisingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_910_EnableInterruptForFallingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_910_DisableDigitalInputBuffer() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_910_EnableInterruptForLowLevelSensing() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE1_SetInterruptHandler AIN_910_SetInterruptHandler

//get/set AIN_11 aliases
#define AIN_11_SetHigh() do { PORTE_OUTSET = 0x4; } while(0)
#define AIN_11_SetLow() do { PORTE_OUTCLR = 0x4; } while(0)
#define AIN_11_Toggle() do { PORTE_OUTTGL = 0x4; } while(0)
#define AIN_11_GetValue() (VPORTE.IN & (0x1 << 2))
#define AIN_11_SetDigitalInput() do { PORTE_DIRCLR = 0x4; } while(0)
#define AIN_11_SetDigitalOutput() do { PORTE_DIRSET = 0x4; } while(0)
#define AIN_11_SetPullUp() do { PORTE_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_11_ResetPullUp() do { PORTE_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_11_SetInverted() do { PORTE_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_11_ResetInverted() do { PORTE_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_11_DisableInterruptOnChange() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_11_EnableInterruptForBothEdges() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_11_EnableInterruptForRisingEdge() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_11_EnableInterruptForFallingEdge() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_11_DisableDigitalInputBuffer() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_11_EnableInterruptForLowLevelSensing() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE2_SetInterruptHandler AIN_11_SetInterruptHandler

//get/set AIN_12 aliases
#define AIN_12_SetHigh() do { PORTE_OUTSET = 0x8; } while(0)
#define AIN_12_SetLow() do { PORTE_OUTCLR = 0x8; } while(0)
#define AIN_12_Toggle() do { PORTE_OUTTGL = 0x8; } while(0)
#define AIN_12_GetValue() (VPORTE.IN & (0x1 << 3))
#define AIN_12_SetDigitalInput() do { PORTE_DIRCLR = 0x8; } while(0)
#define AIN_12_SetDigitalOutput() do { PORTE_DIRSET = 0x8; } while(0)
#define AIN_12_SetPullUp() do { PORTE_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_12_ResetPullUp() do { PORTE_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_12_SetInverted() do { PORTE_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_12_ResetInverted() do { PORTE_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_12_DisableInterruptOnChange() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_12_EnableInterruptForBothEdges() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_12_EnableInterruptForRisingEdge() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_12_EnableInterruptForFallingEdge() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_12_DisableDigitalInputBuffer() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_12_EnableInterruptForLowLevelSensing() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE3_SetInterruptHandler AIN_12_SetInterruptHandler

//get/set AIN_13 aliases
#define AIN_13_SetHigh() do { PORTE_OUTSET = 0x10; } while(0)
#define AIN_13_SetLow() do { PORTE_OUTCLR = 0x10; } while(0)
#define AIN_13_Toggle() do { PORTE_OUTTGL = 0x10; } while(0)
#define AIN_13_GetValue() (VPORTE.IN & (0x1 << 4))
#define AIN_13_SetDigitalInput() do { PORTE_DIRCLR = 0x10; } while(0)
#define AIN_13_SetDigitalOutput() do { PORTE_DIRSET = 0x10; } while(0)
#define AIN_13_SetPullUp() do { PORTE_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_13_ResetPullUp() do { PORTE_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_13_SetInverted() do { PORTE_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_13_ResetInverted() do { PORTE_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_13_DisableInterruptOnChange() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_13_EnableInterruptForBothEdges() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_13_EnableInterruptForRisingEdge() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_13_EnableInterruptForFallingEdge() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_13_DisableDigitalInputBuffer() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_13_EnableInterruptForLowLevelSensing() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE4_SetInterruptHandler AIN_13_SetInterruptHandler

//get/set AIN_14 aliases
#define AIN_14_SetHigh() do { PORTE_OUTSET = 0x20; } while(0)
#define AIN_14_SetLow() do { PORTE_OUTCLR = 0x20; } while(0)
#define AIN_14_Toggle() do { PORTE_OUTTGL = 0x20; } while(0)
#define AIN_14_GetValue() (VPORTE.IN & (0x1 << 5))
#define AIN_14_SetDigitalInput() do { PORTE_DIRCLR = 0x20; } while(0)
#define AIN_14_SetDigitalOutput() do { PORTE_DIRSET = 0x20; } while(0)
#define AIN_14_SetPullUp() do { PORTE_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_14_ResetPullUp() do { PORTE_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_14_SetInverted() do { PORTE_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_14_ResetInverted() do { PORTE_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_14_DisableInterruptOnChange() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_14_EnableInterruptForBothEdges() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_14_EnableInterruptForRisingEdge() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_14_EnableInterruptForFallingEdge() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_14_DisableDigitalInputBuffer() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_14_EnableInterruptForLowLevelSensing() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE5_SetInterruptHandler AIN_14_SetInterruptHandler

//get/set AIN_15 aliases
#define AIN_15_SetHigh() do { PORTE_OUTSET = 0x40; } while(0)
#define AIN_15_SetLow() do { PORTE_OUTCLR = 0x40; } while(0)
#define AIN_15_Toggle() do { PORTE_OUTTGL = 0x40; } while(0)
#define AIN_15_GetValue() (VPORTE.IN & (0x1 << 6))
#define AIN_15_SetDigitalInput() do { PORTE_DIRCLR = 0x40; } while(0)
#define AIN_15_SetDigitalOutput() do { PORTE_DIRSET = 0x40; } while(0)
#define AIN_15_SetPullUp() do { PORTE_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_15_ResetPullUp() do { PORTE_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_15_SetInverted() do { PORTE_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_15_ResetInverted() do { PORTE_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_15_DisableInterruptOnChange() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_15_EnableInterruptForBothEdges() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_15_EnableInterruptForRisingEdge() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_15_EnableInterruptForFallingEdge() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_15_DisableDigitalInputBuffer() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_15_EnableInterruptForLowLevelSensing() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE6_SetInterruptHandler AIN_15_SetInterruptHandler

//get/set AIN_16 aliases
#define AIN_16_SetHigh() do { PORTE_OUTSET = 0x80; } while(0)
#define AIN_16_SetLow() do { PORTE_OUTCLR = 0x80; } while(0)
#define AIN_16_Toggle() do { PORTE_OUTTGL = 0x80; } while(0)
#define AIN_16_GetValue() (VPORTE.IN & (0x1 << 7))
#define AIN_16_SetDigitalInput() do { PORTE_DIRCLR = 0x80; } while(0)
#define AIN_16_SetDigitalOutput() do { PORTE_DIRSET = 0x80; } while(0)
#define AIN_16_SetPullUp() do { PORTE_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_16_ResetPullUp() do { PORTE_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_16_SetInverted() do { PORTE_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_16_ResetInverted() do { PORTE_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_16_DisableInterruptOnChange() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_16_EnableInterruptForBothEdges() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_16_EnableInterruptForRisingEdge() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_16_EnableInterruptForFallingEdge() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_16_DisableDigitalInputBuffer() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_16_EnableInterruptForLowLevelSensing() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PE7_SetInterruptHandler AIN_16_SetInterruptHandler

//get/set AIN_17 aliases
#define AIN_17_SetHigh() do { PORTF_OUTSET = 0x4; } while(0)
#define AIN_17_SetLow() do { PORTF_OUTCLR = 0x4; } while(0)
#define AIN_17_Toggle() do { PORTF_OUTTGL = 0x4; } while(0)
#define AIN_17_GetValue() (VPORTF.IN & (0x1 << 2))
#define AIN_17_SetDigitalInput() do { PORTF_DIRCLR = 0x4; } while(0)
#define AIN_17_SetDigitalOutput() do { PORTF_DIRSET = 0x4; } while(0)
#define AIN_17_SetPullUp() do { PORTF_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_17_ResetPullUp() do { PORTF_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_17_SetInverted() do { PORTF_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_17_ResetInverted() do { PORTF_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_17_DisableInterruptOnChange() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_17_EnableInterruptForBothEdges() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_17_EnableInterruptForRisingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_17_EnableInterruptForFallingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_17_DisableDigitalInputBuffer() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_17_EnableInterruptForLowLevelSensing() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF2_SetInterruptHandler AIN_17_SetInterruptHandler

//get/set AIN_18 aliases
#define AIN_18_SetHigh() do { PORTF_OUTSET = 0x8; } while(0)
#define AIN_18_SetLow() do { PORTF_OUTCLR = 0x8; } while(0)
#define AIN_18_Toggle() do { PORTF_OUTTGL = 0x8; } while(0)
#define AIN_18_GetValue() (VPORTF.IN & (0x1 << 3))
#define AIN_18_SetDigitalInput() do { PORTF_DIRCLR = 0x8; } while(0)
#define AIN_18_SetDigitalOutput() do { PORTF_DIRSET = 0x8; } while(0)
#define AIN_18_SetPullUp() do { PORTF_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_18_ResetPullUp() do { PORTF_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_18_SetInverted() do { PORTF_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_18_ResetInverted() do { PORTF_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_18_DisableInterruptOnChange() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_18_EnableInterruptForBothEdges() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_18_EnableInterruptForRisingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_18_EnableInterruptForFallingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_18_DisableDigitalInputBuffer() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_18_EnableInterruptForLowLevelSensing() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF3_SetInterruptHandler AIN_18_SetInterruptHandler

//get/set AIN_19 aliases
#define AIN_19_SetHigh() do { PORTF_OUTSET = 0x10; } while(0)
#define AIN_19_SetLow() do { PORTF_OUTCLR = 0x10; } while(0)
#define AIN_19_Toggle() do { PORTF_OUTTGL = 0x10; } while(0)
#define AIN_19_GetValue() (VPORTF.IN & (0x1 << 4))
#define AIN_19_SetDigitalInput() do { PORTF_DIRCLR = 0x10; } while(0)
#define AIN_19_SetDigitalOutput() do { PORTF_DIRSET = 0x10; } while(0)
#define AIN_19_SetPullUp() do { PORTF_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_19_ResetPullUp() do { PORTF_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_19_SetInverted() do { PORTF_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_19_ResetInverted() do { PORTF_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_19_DisableInterruptOnChange() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_19_EnableInterruptForBothEdges() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_19_EnableInterruptForRisingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_19_EnableInterruptForFallingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_19_DisableDigitalInputBuffer() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_19_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF4_SetInterruptHandler AIN_19_SetInterruptHandler

//get/set AIN_20 aliases
#define AIN_20_SetHigh() do { PORTF_OUTSET = 0x20; } while(0)
#define AIN_20_SetLow() do { PORTF_OUTCLR = 0x20; } while(0)
#define AIN_20_Toggle() do { PORTF_OUTTGL = 0x20; } while(0)
#define AIN_20_GetValue() (VPORTF.IN & (0x1 << 5))
#define AIN_20_SetDigitalInput() do { PORTF_DIRCLR = 0x20; } while(0)
#define AIN_20_SetDigitalOutput() do { PORTF_DIRSET = 0x20; } while(0)
#define AIN_20_SetPullUp() do { PORTF_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define AIN_20_ResetPullUp() do { PORTF_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define AIN_20_SetInverted() do { PORTF_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define AIN_20_ResetInverted() do { PORTF_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define AIN_20_DisableInterruptOnChange() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define AIN_20_EnableInterruptForBothEdges() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define AIN_20_EnableInterruptForRisingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define AIN_20_EnableInterruptForFallingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define AIN_20_DisableDigitalInputBuffer() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define AIN_20_EnableInterruptForLowLevelSensing() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF5_SetInterruptHandler AIN_20_SetInterruptHandler

//get/set CTR_14 aliases
#define CTR_14_SetHigh() do { PORTG_OUTSET = 0x2; } while(0)
#define CTR_14_SetLow() do { PORTG_OUTCLR = 0x2; } while(0)
#define CTR_14_Toggle() do { PORTG_OUTTGL = 0x2; } while(0)
#define CTR_14_GetValue() (VPORTG.IN & (0x1 << 1))
#define CTR_14_SetDigitalInput() do { PORTG_DIRCLR = 0x2; } while(0)
#define CTR_14_SetDigitalOutput() do { PORTG_DIRSET = 0x2; } while(0)
#define CTR_14_SetPullUp() do { PORTG_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_14_ResetPullUp() do { PORTG_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_14_SetInverted() do { PORTG_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_14_ResetInverted() do { PORTG_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_14_DisableInterruptOnChange() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_14_EnableInterruptForBothEdges() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_14_EnableInterruptForRisingEdge() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_14_EnableInterruptForFallingEdge() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_14_DisableDigitalInputBuffer() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_14_EnableInterruptForLowLevelSensing() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG1_SetInterruptHandler CTR_14_SetInterruptHandler

//get/set CTR_15 aliases
#define CTR_15_SetHigh() do { PORTG_OUTSET = 0x4; } while(0)
#define CTR_15_SetLow() do { PORTG_OUTCLR = 0x4; } while(0)
#define CTR_15_Toggle() do { PORTG_OUTTGL = 0x4; } while(0)
#define CTR_15_GetValue() (VPORTG.IN & (0x1 << 2))
#define CTR_15_SetDigitalInput() do { PORTG_DIRCLR = 0x4; } while(0)
#define CTR_15_SetDigitalOutput() do { PORTG_DIRSET = 0x4; } while(0)
#define CTR_15_SetPullUp() do { PORTG_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_15_ResetPullUp() do { PORTG_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_15_SetInverted() do { PORTG_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_15_ResetInverted() do { PORTG_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_15_DisableInterruptOnChange() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_15_EnableInterruptForBothEdges() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_15_EnableInterruptForRisingEdge() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_15_EnableInterruptForFallingEdge() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_15_DisableDigitalInputBuffer() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_15_EnableInterruptForLowLevelSensing() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG2_SetInterruptHandler CTR_15_SetInterruptHandler

//get/set CTR_16 aliases
#define CTR_16_SetHigh() do { PORTG_OUTSET = 0x8; } while(0)
#define CTR_16_SetLow() do { PORTG_OUTCLR = 0x8; } while(0)
#define CTR_16_Toggle() do { PORTG_OUTTGL = 0x8; } while(0)
#define CTR_16_GetValue() (VPORTG.IN & (0x1 << 3))
#define CTR_16_SetDigitalInput() do { PORTG_DIRCLR = 0x8; } while(0)
#define CTR_16_SetDigitalOutput() do { PORTG_DIRSET = 0x8; } while(0)
#define CTR_16_SetPullUp() do { PORTG_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_16_ResetPullUp() do { PORTG_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_16_SetInverted() do { PORTG_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_16_ResetInverted() do { PORTG_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_16_DisableInterruptOnChange() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_16_EnableInterruptForBothEdges() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_16_EnableInterruptForRisingEdge() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_16_EnableInterruptForFallingEdge() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_16_DisableDigitalInputBuffer() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_16_EnableInterruptForLowLevelSensing() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG3_SetInterruptHandler CTR_16_SetInterruptHandler

//get/set CTR_17 aliases
#define CTR_17_SetHigh() do { PORTG_OUTSET = 0x10; } while(0)
#define CTR_17_SetLow() do { PORTG_OUTCLR = 0x10; } while(0)
#define CTR_17_Toggle() do { PORTG_OUTTGL = 0x10; } while(0)
#define CTR_17_GetValue() (VPORTG.IN & (0x1 << 4))
#define CTR_17_SetDigitalInput() do { PORTG_DIRCLR = 0x10; } while(0)
#define CTR_17_SetDigitalOutput() do { PORTG_DIRSET = 0x10; } while(0)
#define CTR_17_SetPullUp() do { PORTG_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_17_ResetPullUp() do { PORTG_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_17_SetInverted() do { PORTG_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_17_ResetInverted() do { PORTG_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_17_DisableInterruptOnChange() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_17_EnableInterruptForBothEdges() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_17_EnableInterruptForRisingEdge() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_17_EnableInterruptForFallingEdge() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_17_DisableDigitalInputBuffer() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_17_EnableInterruptForLowLevelSensing() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG4_SetInterruptHandler CTR_17_SetInterruptHandler

//get/set CTR_18 aliases
#define CTR_18_SetHigh() do { PORTG_OUTSET = 0x20; } while(0)
#define CTR_18_SetLow() do { PORTG_OUTCLR = 0x20; } while(0)
#define CTR_18_Toggle() do { PORTG_OUTTGL = 0x20; } while(0)
#define CTR_18_GetValue() (VPORTG.IN & (0x1 << 5))
#define CTR_18_SetDigitalInput() do { PORTG_DIRCLR = 0x20; } while(0)
#define CTR_18_SetDigitalOutput() do { PORTG_DIRSET = 0x20; } while(0)
#define CTR_18_SetPullUp() do { PORTG_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_18_ResetPullUp() do { PORTG_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_18_SetInverted() do { PORTG_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_18_ResetInverted() do { PORTG_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_18_DisableInterruptOnChange() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_18_EnableInterruptForBothEdges() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_18_EnableInterruptForRisingEdge() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_18_EnableInterruptForFallingEdge() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_18_DisableDigitalInputBuffer() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_18_EnableInterruptForLowLevelSensing() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG5_SetInterruptHandler CTR_18_SetInterruptHandler

//get/set CTR_19 aliases
#define CTR_19_SetHigh() do { PORTG_OUTSET = 0x40; } while(0)
#define CTR_19_SetLow() do { PORTG_OUTCLR = 0x40; } while(0)
#define CTR_19_Toggle() do { PORTG_OUTTGL = 0x40; } while(0)
#define CTR_19_GetValue() (VPORTG.IN & (0x1 << 6))
#define CTR_19_SetDigitalInput() do { PORTG_DIRCLR = 0x40; } while(0)
#define CTR_19_SetDigitalOutput() do { PORTG_DIRSET = 0x40; } while(0)
#define CTR_19_SetPullUp() do { PORTG_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_19_ResetPullUp() do { PORTG_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_19_SetInverted() do { PORTG_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_19_ResetInverted() do { PORTG_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_19_DisableInterruptOnChange() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_19_EnableInterruptForBothEdges() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_19_EnableInterruptForRisingEdge() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_19_EnableInterruptForFallingEdge() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_19_DisableDigitalInputBuffer() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_19_EnableInterruptForLowLevelSensing() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG6_SetInterruptHandler CTR_19_SetInterruptHandler

//get/set CTR_20 aliases
#define CTR_20_SetHigh() do { PORTG_OUTSET = 0x80; } while(0)
#define CTR_20_SetLow() do { PORTG_OUTCLR = 0x80; } while(0)
#define CTR_20_Toggle() do { PORTG_OUTTGL = 0x80; } while(0)
#define CTR_20_GetValue() (VPORTG.IN & (0x1 << 7))
#define CTR_20_SetDigitalInput() do { PORTG_DIRCLR = 0x80; } while(0)
#define CTR_20_SetDigitalOutput() do { PORTG_DIRSET = 0x80; } while(0)
#define CTR_20_SetPullUp() do { PORTG_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_20_ResetPullUp() do { PORTG_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_20_SetInverted() do { PORTG_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_20_ResetInverted() do { PORTG_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_20_DisableInterruptOnChange() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_20_EnableInterruptForBothEdges() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_20_EnableInterruptForRisingEdge() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_20_EnableInterruptForFallingEdge() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_20_DisableDigitalInputBuffer() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_20_EnableInterruptForLowLevelSensing() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG7_SetInterruptHandler CTR_20_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PB1 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PB1_SetInterruptHandler() method.
 *        This handler is called every time the IO_PB1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PB1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PB1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PB1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PB1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PB0 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PB0_SetInterruptHandler() method.
 *        This handler is called every time the IO_PB0 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PB0_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PB0 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PB0 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PB0_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_1 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_1_SetInterruptHandler() method.
 *        This handler is called every time the CTR_1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_2 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_2_SetInterruptHandler() method.
 *        This handler is called every time the CTR_2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_3 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_3_SetInterruptHandler() method.
 *        This handler is called every time the CTR_3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_4 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_4_SetInterruptHandler() method.
 *        This handler is called every time the CTR_4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_5 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_5_SetInterruptHandler() method.
 *        This handler is called every time the CTR_5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_5_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_6 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_6_SetInterruptHandler() method.
 *        This handler is called every time the CTR_6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_7 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_7_SetInterruptHandler() method.
 *        This handler is called every time the CTR_7 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_7_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_7 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_7 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_7_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_8 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_8_SetInterruptHandler() method.
 *        This handler is called every time the CTR_8 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_8_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_8 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_8 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_8_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_9 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_9_SetInterruptHandler() method.
 *        This handler is called every time the CTR_9 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_9_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_9 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_9 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_9_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_10 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_10_SetInterruptHandler() method.
 *        This handler is called every time the CTR_10 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_10_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_10 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_10 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_10_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_11 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_11_SetInterruptHandler() method.
 *        This handler is called every time the CTR_11 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_11_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_11 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_11 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_11_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_12 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_12_SetInterruptHandler() method.
 *        This handler is called every time the CTR_12 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_12_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_12 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_12 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_12_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_13 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_13_SetInterruptHandler() method.
 *        This handler is called every time the CTR_13 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_13_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_13 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_13 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_13_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_1 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_1_SetInterruptHandler() method.
 *        This handler is called every time the AIN_1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_2 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_2_SetInterruptHandler() method.
 *        This handler is called every time the AIN_2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_3 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_3_SetInterruptHandler() method.
 *        This handler is called every time the AIN_3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_4 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_4_SetInterruptHandler() method.
 *        This handler is called every time the AIN_4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_5 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_5_SetInterruptHandler() method.
 *        This handler is called every time the AIN_5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_5_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_6 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_6_SetInterruptHandler() method.
 *        This handler is called every time the AIN_6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_7 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_7_SetInterruptHandler() method.
 *        This handler is called every time the AIN_7 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_7_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_7 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_7 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_7_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_8 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_8_SetInterruptHandler() method.
 *        This handler is called every time the AIN_8 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_8_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_8 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_8 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_8_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_9 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_9_SetInterruptHandler() method.
 *        This handler is called every time the AIN_9 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_9_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_9 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_9 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_9_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_910 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_910_SetInterruptHandler() method.
 *        This handler is called every time the AIN_910 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_910_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_910 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_910 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_910_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_11 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_11_SetInterruptHandler() method.
 *        This handler is called every time the AIN_11 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_11_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_11 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_11 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_11_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_12 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_12_SetInterruptHandler() method.
 *        This handler is called every time the AIN_12 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_12_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_12 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_12 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_12_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_13 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_13_SetInterruptHandler() method.
 *        This handler is called every time the AIN_13 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_13_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_13 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_13 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_13_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_14 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_14_SetInterruptHandler() method.
 *        This handler is called every time the AIN_14 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_14_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_14 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_14 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_14_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_15 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_15_SetInterruptHandler() method.
 *        This handler is called every time the AIN_15 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_15_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_15 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_15 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_15_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_16 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_16_SetInterruptHandler() method.
 *        This handler is called every time the AIN_16 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_16_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_16 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_16 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_16_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_17 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_17_SetInterruptHandler() method.
 *        This handler is called every time the AIN_17 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_17_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_17 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_17 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_17_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_18 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_18_SetInterruptHandler() method.
 *        This handler is called every time the AIN_18 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_18_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_18 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_18 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_18_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_19 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_19_SetInterruptHandler() method.
 *        This handler is called every time the AIN_19 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_19_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_19 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_19 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_19_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for AIN_20 pin. 
 *        This is a predefined interrupt handler to be used together with the AIN_20_SetInterruptHandler() method.
 *        This handler is called every time the AIN_20 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void AIN_20_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for AIN_20 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for AIN_20 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void AIN_20_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_14 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_14_SetInterruptHandler() method.
 *        This handler is called every time the CTR_14 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_14_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_14 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_14 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_14_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_15 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_15_SetInterruptHandler() method.
 *        This handler is called every time the CTR_15 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_15_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_15 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_15 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_15_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_16 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_16_SetInterruptHandler() method.
 *        This handler is called every time the CTR_16 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_16_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_16 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_16 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_16_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_17 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_17_SetInterruptHandler() method.
 *        This handler is called every time the CTR_17 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_17_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_17 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_17 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_17_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_18 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_18_SetInterruptHandler() method.
 *        This handler is called every time the CTR_18 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_18_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_18 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_18 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_18_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_19 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_19_SetInterruptHandler() method.
 *        This handler is called every time the CTR_19 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_19_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_19 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_19 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_19_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_20 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_20_SetInterruptHandler() method.
 *        This handler is called every time the CTR_20 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_20_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_20 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_20 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_20_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
