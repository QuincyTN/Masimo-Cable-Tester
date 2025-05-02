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

//get/set CTR_0 aliases
#define CTR_0_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define CTR_0_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define CTR_0_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define CTR_0_GetValue() (VPORTA.IN & (0x1 << 7))
#define CTR_0_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define CTR_0_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define CTR_0_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_0_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_0_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_0_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_0_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_0_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_0_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_0_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_0_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_0_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA7_SetInterruptHandler CTR_0_SetInterruptHandler

//get/set CTR_1 aliases
#define CTR_1_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define CTR_1_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define CTR_1_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define CTR_1_GetValue() (VPORTB.IN & (0x1 << 2))
#define CTR_1_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define CTR_1_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define CTR_1_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_1_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_1_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_1_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_1_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_1_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_1_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_1_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_1_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_1_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB2_SetInterruptHandler CTR_1_SetInterruptHandler

//get/set CTR_2 aliases
#define CTR_2_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define CTR_2_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define CTR_2_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define CTR_2_GetValue() (VPORTB.IN & (0x1 << 3))
#define CTR_2_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define CTR_2_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define CTR_2_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_2_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_2_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_2_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_2_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_2_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_2_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_2_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_2_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_2_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB3_SetInterruptHandler CTR_2_SetInterruptHandler

//get/set CTR_3 aliases
#define CTR_3_SetHigh() do { PORTB_OUTSET = 0x10; } while(0)
#define CTR_3_SetLow() do { PORTB_OUTCLR = 0x10; } while(0)
#define CTR_3_Toggle() do { PORTB_OUTTGL = 0x10; } while(0)
#define CTR_3_GetValue() (VPORTB.IN & (0x1 << 4))
#define CTR_3_SetDigitalInput() do { PORTB_DIRCLR = 0x10; } while(0)
#define CTR_3_SetDigitalOutput() do { PORTB_DIRSET = 0x10; } while(0)
#define CTR_3_SetPullUp() do { PORTB_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_3_ResetPullUp() do { PORTB_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_3_SetInverted() do { PORTB_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_3_ResetInverted() do { PORTB_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_3_DisableInterruptOnChange() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_3_EnableInterruptForBothEdges() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_3_EnableInterruptForRisingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_3_EnableInterruptForFallingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_3_DisableDigitalInputBuffer() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_3_EnableInterruptForLowLevelSensing() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB4_SetInterruptHandler CTR_3_SetInterruptHandler

//get/set CTR_4 aliases
#define CTR_4_SetHigh() do { PORTB_OUTSET = 0x20; } while(0)
#define CTR_4_SetLow() do { PORTB_OUTCLR = 0x20; } while(0)
#define CTR_4_Toggle() do { PORTB_OUTTGL = 0x20; } while(0)
#define CTR_4_GetValue() (VPORTB.IN & (0x1 << 5))
#define CTR_4_SetDigitalInput() do { PORTB_DIRCLR = 0x20; } while(0)
#define CTR_4_SetDigitalOutput() do { PORTB_DIRSET = 0x20; } while(0)
#define CTR_4_SetPullUp() do { PORTB_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_4_ResetPullUp() do { PORTB_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_4_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_4_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_4_DisableInterruptOnChange() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_4_EnableInterruptForBothEdges() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_4_EnableInterruptForRisingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_4_EnableInterruptForFallingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_4_DisableDigitalInputBuffer() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_4_EnableInterruptForLowLevelSensing() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB5_SetInterruptHandler CTR_4_SetInterruptHandler

//get/set CTR_5 aliases
#define CTR_5_SetHigh() do { PORTB_OUTSET = 0x40; } while(0)
#define CTR_5_SetLow() do { PORTB_OUTCLR = 0x40; } while(0)
#define CTR_5_Toggle() do { PORTB_OUTTGL = 0x40; } while(0)
#define CTR_5_GetValue() (VPORTB.IN & (0x1 << 6))
#define CTR_5_SetDigitalInput() do { PORTB_DIRCLR = 0x40; } while(0)
#define CTR_5_SetDigitalOutput() do { PORTB_DIRSET = 0x40; } while(0)
#define CTR_5_SetPullUp() do { PORTB_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_5_ResetPullUp() do { PORTB_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_5_SetInverted() do { PORTB_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_5_ResetInverted() do { PORTB_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_5_DisableInterruptOnChange() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_5_EnableInterruptForBothEdges() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_5_EnableInterruptForRisingEdge() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_5_EnableInterruptForFallingEdge() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_5_DisableDigitalInputBuffer() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_5_EnableInterruptForLowLevelSensing() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB6_SetInterruptHandler CTR_5_SetInterruptHandler

//get/set CTR_6 aliases
#define CTR_6_SetHigh() do { PORTB_OUTSET = 0x80; } while(0)
#define CTR_6_SetLow() do { PORTB_OUTCLR = 0x80; } while(0)
#define CTR_6_Toggle() do { PORTB_OUTTGL = 0x80; } while(0)
#define CTR_6_GetValue() (VPORTB.IN & (0x1 << 7))
#define CTR_6_SetDigitalInput() do { PORTB_DIRCLR = 0x80; } while(0)
#define CTR_6_SetDigitalOutput() do { PORTB_DIRSET = 0x80; } while(0)
#define CTR_6_SetPullUp() do { PORTB_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_6_ResetPullUp() do { PORTB_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_6_SetInverted() do { PORTB_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_6_ResetInverted() do { PORTB_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_6_DisableInterruptOnChange() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_6_EnableInterruptForBothEdges() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_6_EnableInterruptForRisingEdge() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_6_EnableInterruptForFallingEdge() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_6_DisableDigitalInputBuffer() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_6_EnableInterruptForLowLevelSensing() do { PORTB.PIN7CTRL = (PORTB.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PB7_SetInterruptHandler CTR_6_SetInterruptHandler

//get/set CTR_7 aliases
#define CTR_7_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define CTR_7_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define CTR_7_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define CTR_7_GetValue() (VPORTC.IN & (0x1 << 2))
#define CTR_7_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define CTR_7_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define CTR_7_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_7_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_7_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_7_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_7_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_7_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_7_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_7_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_7_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_7_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC2_SetInterruptHandler CTR_7_SetInterruptHandler

//get/set CTR_8 aliases
#define CTR_8_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define CTR_8_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define CTR_8_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define CTR_8_GetValue() (VPORTC.IN & (0x1 << 3))
#define CTR_8_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define CTR_8_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define CTR_8_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_8_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_8_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_8_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_8_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_8_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_8_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_8_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_8_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_8_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC3_SetInterruptHandler CTR_8_SetInterruptHandler

//get/set CTR_9 aliases
#define CTR_9_SetHigh() do { PORTC_OUTSET = 0x10; } while(0)
#define CTR_9_SetLow() do { PORTC_OUTCLR = 0x10; } while(0)
#define CTR_9_Toggle() do { PORTC_OUTTGL = 0x10; } while(0)
#define CTR_9_GetValue() (VPORTC.IN & (0x1 << 4))
#define CTR_9_SetDigitalInput() do { PORTC_DIRCLR = 0x10; } while(0)
#define CTR_9_SetDigitalOutput() do { PORTC_DIRSET = 0x10; } while(0)
#define CTR_9_SetPullUp() do { PORTC_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_9_ResetPullUp() do { PORTC_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_9_SetInverted() do { PORTC_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_9_ResetInverted() do { PORTC_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_9_DisableInterruptOnChange() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_9_EnableInterruptForBothEdges() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_9_EnableInterruptForRisingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_9_EnableInterruptForFallingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_9_DisableDigitalInputBuffer() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_9_EnableInterruptForLowLevelSensing() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC4_SetInterruptHandler CTR_9_SetInterruptHandler

//get/set CTR_10 aliases
#define CTR_10_SetHigh() do { PORTC_OUTSET = 0x20; } while(0)
#define CTR_10_SetLow() do { PORTC_OUTCLR = 0x20; } while(0)
#define CTR_10_Toggle() do { PORTC_OUTTGL = 0x20; } while(0)
#define CTR_10_GetValue() (VPORTC.IN & (0x1 << 5))
#define CTR_10_SetDigitalInput() do { PORTC_DIRCLR = 0x20; } while(0)
#define CTR_10_SetDigitalOutput() do { PORTC_DIRSET = 0x20; } while(0)
#define CTR_10_SetPullUp() do { PORTC_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_10_ResetPullUp() do { PORTC_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_10_SetInverted() do { PORTC_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_10_ResetInverted() do { PORTC_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_10_DisableInterruptOnChange() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_10_EnableInterruptForBothEdges() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_10_EnableInterruptForRisingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_10_EnableInterruptForFallingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_10_DisableDigitalInputBuffer() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_10_EnableInterruptForLowLevelSensing() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC5_SetInterruptHandler CTR_10_SetInterruptHandler

//get/set CTR_11 aliases
#define CTR_11_SetHigh() do { PORTC_OUTSET = 0x40; } while(0)
#define CTR_11_SetLow() do { PORTC_OUTCLR = 0x40; } while(0)
#define CTR_11_Toggle() do { PORTC_OUTTGL = 0x40; } while(0)
#define CTR_11_GetValue() (VPORTC.IN & (0x1 << 6))
#define CTR_11_SetDigitalInput() do { PORTC_DIRCLR = 0x40; } while(0)
#define CTR_11_SetDigitalOutput() do { PORTC_DIRSET = 0x40; } while(0)
#define CTR_11_SetPullUp() do { PORTC_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_11_ResetPullUp() do { PORTC_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_11_SetInverted() do { PORTC_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_11_ResetInverted() do { PORTC_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_11_DisableInterruptOnChange() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_11_EnableInterruptForBothEdges() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_11_EnableInterruptForRisingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_11_EnableInterruptForFallingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_11_DisableDigitalInputBuffer() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_11_EnableInterruptForLowLevelSensing() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC6_SetInterruptHandler CTR_11_SetInterruptHandler

//get/set CTR_12 aliases
#define CTR_12_SetHigh() do { PORTC_OUTSET = 0x80; } while(0)
#define CTR_12_SetLow() do { PORTC_OUTCLR = 0x80; } while(0)
#define CTR_12_Toggle() do { PORTC_OUTTGL = 0x80; } while(0)
#define CTR_12_GetValue() (VPORTC.IN & (0x1 << 7))
#define CTR_12_SetDigitalInput() do { PORTC_DIRCLR = 0x80; } while(0)
#define CTR_12_SetDigitalOutput() do { PORTC_DIRSET = 0x80; } while(0)
#define CTR_12_SetPullUp() do { PORTC_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_12_ResetPullUp() do { PORTC_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_12_SetInverted() do { PORTC_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_12_ResetInverted() do { PORTC_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_12_DisableInterruptOnChange() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_12_EnableInterruptForBothEdges() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_12_EnableInterruptForRisingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_12_EnableInterruptForFallingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_12_DisableDigitalInputBuffer() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_12_EnableInterruptForLowLevelSensing() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC7_SetInterruptHandler CTR_12_SetInterruptHandler

//get/set ADC_0 aliases
#define ADC_0_SetHigh() do { PORTE.OUTSET = PIN1_bm; } while(0)
#define ADC_0_SetLow() do { PORTE.OUTCLR = PIN1_bm; } while(0)
#define ADC_0_Toggle() do { PORTE.OUTTGL = PIN1_bm; } while(0)
#define ADC_0_GetValue() (VPORTE.IN & PIN1_bm)
#define ADC_0_SetDigitalInput() do { PORTE.DIRCLR = PIN1_bm; } while(0)
#define ADC_0_SetDigitalOutput() do { PORTE.DIRSET = PIN1_bm; } while(0)
#define ADC_0_SetPullUp() do { PORTE.PIN1CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_0_ResetPullUp() do { PORTE.PIN1CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_0_SetInverted() do { PORTE.PIN1CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_0_ResetInverted() do { PORTE.PIN1CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_0_DisableInterruptOnChange() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_0_EnableInterruptForBothEdges() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_0_EnableInterruptForRisingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_0_EnableInterruptForFallingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_0_DisableDigitalInputBuffer() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_0_EnableInterruptForLowLevelSensing() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE1_SetInterruptHandler ADC_0_SetInterruptHandler

//get/set ADC_1 aliases
#define ADC_1_SetHigh()                do { PORTE.OUTSET = PIN0_bm; } while(0)
#define ADC_1_SetLow()                 do { PORTE.OUTCLR = PIN0_bm; } while(0)
#define ADC_1_Toggle()                 do { PORTE.OUTTGL = PIN0_bm; } while(0)
#define ADC_1_GetValue()              (VPORTE.IN & PIN0_bm)
#define ADC_1_SetDigitalInput()       do { PORTE.DIRCLR = PIN0_bm; } while(0)
#define ADC_1_SetDigitalOutput()      do { PORTE.DIRSET = PIN0_bm; } while(0)
#define ADC_1_SetPullUp()             do { PORTE.PIN0CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_1_ResetPullUp()           do { PORTE.PIN0CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_1_SetInverted()           do { PORTE.PIN0CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_1_ResetInverted()         do { PORTE.PIN0CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_1_DisableInterruptOnChange()        do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_1_EnableInterruptForBothEdges()     do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_1_EnableInterruptForRisingEdge()    do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_1_EnableInterruptForFallingEdge()   do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_1_DisableDigitalInputBuffer()       do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_1_EnableInterruptForLowLevelSensing() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE0_SetInterruptHandler ADC_1_SetInterruptHandler


//get/set ADC_2 aliases
#define ADC_2_SetHigh()                do { PORTD.OUTSET = PIN7_bm; } while(0)
#define ADC_2_SetLow()                 do { PORTD.OUTCLR = PIN7_bm; } while(0)
#define ADC_2_Toggle()                 do { PORTD.OUTTGL = PIN7_bm; } while(0)
#define ADC_2_GetValue()              (VPORTD.IN & PIN7_bm)
#define ADC_2_SetDigitalInput()       do { PORTD.DIRCLR = PIN7_bm; } while(0)
#define ADC_2_SetDigitalOutput()      do { PORTD.DIRSET = PIN7_bm; } while(0)
#define ADC_2_SetPullUp()             do { PORTD.PIN7CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_2_ResetPullUp()           do { PORTD.PIN7CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_2_SetInverted()           do { PORTD.PIN7CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_2_ResetInverted()         do { PORTD.PIN7CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_2_DisableInterruptOnChange()        do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_2_EnableInterruptForBothEdges()     do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_2_EnableInterruptForRisingEdge()    do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_2_EnableInterruptForFallingEdge()   do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_2_DisableDigitalInputBuffer()       do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_2_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD7_SetInterruptHandler ADC_2_SetInterruptHandler


//get/set ADC_3 aliases
#define ADC_3_SetHigh()                do { PORTD.OUTSET = PIN6_bm; } while(0)
#define ADC_3_SetLow()                 do { PORTD.OUTCLR = PIN6_bm; } while(0)
#define ADC_3_Toggle()                 do { PORTD.OUTTGL = PIN6_bm; } while(0)
#define ADC_3_GetValue()              (VPORTD.IN & PIN6_bm)
#define ADC_3_SetDigitalInput()       do { PORTD.DIRCLR = PIN6_bm; } while(0)
#define ADC_3_SetDigitalOutput()      do { PORTD.DIRSET = PIN6_bm; } while(0)
#define ADC_3_SetPullUp()             do { PORTD.PIN6CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_3_ResetPullUp()           do { PORTD.PIN6CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_3_SetInverted()           do { PORTD.PIN6CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_3_ResetInverted()         do { PORTD.PIN6CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_3_DisableInterruptOnChange()        do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_3_EnableInterruptForBothEdges()     do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_3_EnableInterruptForRisingEdge()    do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_3_EnableInterruptForFallingEdge()   do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_3_DisableDigitalInputBuffer()       do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_3_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD6_SetInterruptHandler ADC_3_SetInterruptHandler


//get/set ADC_4 aliases
#define ADC_4_SetHigh()                do { PORTD.OUTSET = PIN5_bm; } while(0)
#define ADC_4_SetLow()                 do { PORTD.OUTCLR = PIN5_bm; } while(0)
#define ADC_4_Toggle()                 do { PORTD.OUTTGL = PIN5_bm; } while(0)
#define ADC_4_GetValue()              (VPORTD.IN & PIN5_bm)
#define ADC_4_SetDigitalInput()       do { PORTD.DIRCLR = PIN5_bm; } while(0)
#define ADC_4_SetDigitalOutput()      do { PORTD.DIRSET = PIN5_bm; } while(0)
#define ADC_4_SetPullUp()             do { PORTD.PIN5CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_4_ResetPullUp()           do { PORTD.PIN5CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_4_SetInverted()           do { PORTD.PIN5CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_4_ResetInverted()         do { PORTD.PIN5CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_4_DisableInterruptOnChange()        do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_4_EnableInterruptForBothEdges()     do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_4_EnableInterruptForRisingEdge()    do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_4_EnableInterruptForFallingEdge()   do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_4_DisableDigitalInputBuffer()       do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_4_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD5_SetInterruptHandler ADC_4_SetInterruptHandler

//get/set ADC_5 aliases
#define ADC_5_SetHigh()                do { PORTD.OUTSET = PIN4_bm; } while(0)
#define ADC_5_SetLow()                 do { PORTD.OUTCLR = PIN4_bm; } while(0)
#define ADC_5_Toggle()                 do { PORTD.OUTTGL = PIN4_bm; } while(0)
#define ADC_5_GetValue()              (VPORTD.IN & PIN4_bm)
#define ADC_5_SetDigitalInput()       do { PORTD.DIRCLR = PIN4_bm; } while(0)
#define ADC_5_SetDigitalOutput()      do { PORTD.DIRSET = PIN4_bm; } while(0)
#define ADC_5_SetPullUp()             do { PORTD.PIN4CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_5_ResetPullUp()           do { PORTD.PIN4CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_5_SetInverted()           do { PORTD.PIN4CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_5_ResetInverted()         do { PORTD.PIN4CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_5_DisableInterruptOnChange()        do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_5_EnableInterruptForBothEdges()     do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_5_EnableInterruptForRisingEdge()    do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_5_EnableInterruptForFallingEdge()   do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_5_DisableDigitalInputBuffer()       do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_5_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD4_SetInterruptHandler ADC_5_SetInterruptHandler

//get/set ADC_6 aliases
#define ADC_6_SetHigh()                do { PORTD.OUTSET = PIN3_bm; } while(0)
#define ADC_6_SetLow()                 do { PORTD.OUTCLR = PIN3_bm; } while(0)
#define ADC_6_Toggle()                 do { PORTD.OUTTGL = PIN3_bm; } while(0)
#define ADC_6_GetValue()              (VPORTD.IN & PIN3_bm)
#define ADC_6_SetDigitalInput()       do { PORTD.DIRCLR = PIN3_bm; } while(0)
#define ADC_6_SetDigitalOutput()      do { PORTD.DIRSET = PIN3_bm; } while(0)
#define ADC_6_SetPullUp()             do { PORTD.PIN3CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_6_ResetPullUp()           do { PORTD.PIN3CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_6_SetInverted()           do { PORTD.PIN3CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_6_ResetInverted()         do { PORTD.PIN3CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_6_DisableInterruptOnChange()        do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_6_EnableInterruptForBothEdges()     do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_6_EnableInterruptForRisingEdge()    do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_6_EnableInterruptForFallingEdge()   do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_6_DisableDigitalInputBuffer()       do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_6_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD3_SetInterruptHandler ADC_6_SetInterruptHandler


//get/set ADC_7 aliases
#define ADC_7_SetHigh()                do { PORTD.OUTSET = PIN2_bm; } while(0)
#define ADC_7_SetLow()                 do { PORTD.OUTCLR = PIN2_bm; } while(0)
#define ADC_7_Toggle()                 do { PORTD.OUTTGL = PIN2_bm; } while(0)
#define ADC_7_GetValue()              (VPORTD.IN & PIN2_bm)
#define ADC_7_SetDigitalInput()       do { PORTD.DIRCLR = PIN2_bm; } while(0)
#define ADC_7_SetDigitalOutput()      do { PORTD.DIRSET = PIN2_bm; } while(0)
#define ADC_7_SetPullUp()             do { PORTD.PIN2CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_7_ResetPullUp()           do { PORTD.PIN2CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_7_SetInverted()           do { PORTD.PIN2CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_7_ResetInverted()         do { PORTD.PIN2CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_7_DisableInterruptOnChange()        do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_7_EnableInterruptForBothEdges()     do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_7_EnableInterruptForRisingEdge()    do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_7_EnableInterruptForFallingEdge()   do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_7_DisableDigitalInputBuffer()       do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_7_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD2_SetInterruptHandler ADC_7_SetInterruptHandler

//get/set ADC_8 aliases
#define ADC_8_SetHigh()                do { PORTD.OUTSET = PIN1_bm; } while(0)
#define ADC_8_SetLow()                 do { PORTD.OUTCLR = PIN1_bm; } while(0)
#define ADC_8_Toggle()                 do { PORTD.OUTTGL = PIN1_bm; } while(0)
#define ADC_8_GetValue()              (VPORTD.IN & PIN1_bm)
#define ADC_8_SetDigitalInput()       do { PORTD.DIRCLR = PIN1_bm; } while(0)
#define ADC_8_SetDigitalOutput()      do { PORTD.DIRSET = PIN1_bm; } while(0)
#define ADC_8_SetPullUp()             do { PORTD.PIN1CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_8_ResetPullUp()           do { PORTD.PIN1CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_8_SetInverted()           do { PORTD.PIN1CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_8_ResetInverted()         do { PORTD.PIN1CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_8_DisableInterruptOnChange()        do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_8_EnableInterruptForBothEdges()     do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_8_EnableInterruptForRisingEdge()    do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_8_EnableInterruptForFallingEdge()   do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_8_DisableDigitalInputBuffer()       do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_8_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD1_SetInterruptHandler ADC_8_SetInterruptHandler


//get/set ADC_9 aliases
#define ADC_9_SetHigh()                do { PORTD.OUTSET = PIN0_bm; } while(0)
#define ADC_9_SetLow()                 do { PORTD.OUTCLR = PIN0_bm; } while(0)
#define ADC_9_Toggle()                 do { PORTD.OUTTGL = PIN0_bm; } while(0)
#define ADC_9_GetValue()              (VPORTD.IN & PIN0_bm)
#define ADC_9_SetDigitalInput()       do { PORTD.DIRCLR = PIN0_bm; } while(0)
#define ADC_9_SetDigitalOutput()      do { PORTD.DIRSET = PIN0_bm; } while(0)
#define ADC_9_SetPullUp()             do { PORTD.PIN0CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_9_ResetPullUp()           do { PORTD.PIN0CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_9_SetInverted()           do { PORTD.PIN0CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_9_ResetInverted()         do { PORTD.PIN0CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_9_DisableInterruptOnChange()        do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_9_EnableInterruptForBothEdges()     do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_9_EnableInterruptForRisingEdge()    do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_9_EnableInterruptForFallingEdge()   do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_9_DisableDigitalInputBuffer()       do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_9_EnableInterruptForLowLevelSensing() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PD0_SetInterruptHandler ADC_9_SetInterruptHandler


//get/set ADC_10 aliases
#define ADC_10_SetHigh()                do { PORTE.OUTSET = PIN2_bm; } while(0)
#define ADC_10_SetLow()                 do { PORTE.OUTCLR = PIN2_bm; } while(0)
#define ADC_10_Toggle()                 do { PORTE.OUTTGL = PIN2_bm; } while(0)
#define ADC_10_GetValue()              (VPORTE.IN & PIN2_bm)
#define ADC_10_SetDigitalInput()       do { PORTE.DIRCLR = PIN2_bm; } while(0)
#define ADC_10_SetDigitalOutput()      do { PORTE.DIRSET = PIN2_bm; } while(0)
#define ADC_10_SetPullUp()             do { PORTE.PIN2CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_10_ResetPullUp()           do { PORTE.PIN2CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_10_SetInverted()           do { PORTE.PIN2CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_10_ResetInverted()         do { PORTE.PIN2CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_10_DisableInterruptOnChange()        do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_10_EnableInterruptForBothEdges()     do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_10_EnableInterruptForRisingEdge()    do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_10_EnableInterruptForFallingEdge()   do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_10_DisableDigitalInputBuffer()       do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_10_EnableInterruptForLowLevelSensing() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE2_SetInterruptHandler ADC_10_SetInterruptHandler


//get/set ADC_11 aliases
#define ADC_11_SetHigh()                do { PORTE.OUTSET = PIN3_bm; } while(0)
#define ADC_11_SetLow()                 do { PORTE.OUTCLR = PIN3_bm; } while(0)
#define ADC_11_Toggle()                 do { PORTE.OUTTGL = PIN3_bm; } while(0)
#define ADC_11_GetValue()              (VPORTE.IN & PIN3_bm)
#define ADC_11_SetDigitalInput()       do { PORTE.DIRCLR = PIN3_bm; } while(0)
#define ADC_11_SetDigitalOutput()      do { PORTE.DIRSET = PIN3_bm; } while(0)
#define ADC_11_SetPullUp()             do { PORTE.PIN3CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_11_ResetPullUp()           do { PORTE.PIN3CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_11_SetInverted()           do { PORTE.PIN3CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_11_ResetInverted()         do { PORTE.PIN3CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_11_DisableInterruptOnChange()        do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_11_EnableInterruptForBothEdges()     do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_11_EnableInterruptForRisingEdge()    do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_11_EnableInterruptForFallingEdge()   do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_11_DisableDigitalInputBuffer()       do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_11_EnableInterruptForLowLevelSensing() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE3_SetInterruptHandler ADC_11_SetInterruptHandler



//get/set ADC_12 aliases
#define ADC_12_SetHigh()                do { PORTE.OUTSET = PIN4_bm; } while(0)
#define ADC_12_SetLow()                 do { PORTE.OUTCLR = PIN4_bm; } while(0)
#define ADC_12_Toggle()                 do { PORTE.OUTTGL = PIN4_bm; } while(0)
#define ADC_12_GetValue()              (VPORTE.IN & PIN4_bm)
#define ADC_12_SetDigitalInput()       do { PORTE.DIRCLR = PIN4_bm; } while(0)
#define ADC_12_SetDigitalOutput()      do { PORTE.DIRSET = PIN4_bm; } while(0)
#define ADC_12_SetPullUp()             do { PORTE.PIN4CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_12_ResetPullUp()           do { PORTE.PIN4CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_12_SetInverted()           do { PORTE.PIN4CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_12_ResetInverted()         do { PORTE.PIN4CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_12_DisableInterruptOnChange()        do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_12_EnableInterruptForBothEdges()     do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_12_EnableInterruptForRisingEdge()    do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_12_EnableInterruptForFallingEdge()   do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_12_DisableDigitalInputBuffer()       do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_12_EnableInterruptForLowLevelSensing() do { PORTE.PIN4CTRL = (PORTE.PIN4CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE4_SetInterruptHandler ADC_12_SetInterruptHandler


//get/set ADC_13 aliases
#define ADC_13_SetHigh()                do { PORTE.OUTSET = PIN5_bm; } while(0)
#define ADC_13_SetLow()                 do { PORTE.OUTCLR = PIN5_bm; } while(0)
#define ADC_13_Toggle()                 do { PORTE.OUTTGL = PIN5_bm; } while(0)
#define ADC_13_GetValue()              (VPORTE.IN & PIN5_bm)
#define ADC_13_SetDigitalInput()       do { PORTE.DIRCLR = PIN5_bm; } while(0)
#define ADC_13_SetDigitalOutput()      do { PORTE.DIRSET = PIN5_bm; } while(0)
#define ADC_13_SetPullUp()             do { PORTE.PIN5CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_13_ResetPullUp()           do { PORTE.PIN5CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_13_SetInverted()           do { PORTE.PIN5CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_13_ResetInverted()         do { PORTE.PIN5CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_13_DisableInterruptOnChange()        do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_13_EnableInterruptForBothEdges()     do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_13_EnableInterruptForRisingEdge()    do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_13_EnableInterruptForFallingEdge()   do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_13_DisableDigitalInputBuffer()       do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_13_EnableInterruptForLowLevelSensing() do { PORTE.PIN5CTRL = (PORTE.PIN5CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE5_SetInterruptHandler ADC_13_SetInterruptHandler


//get/set ADC_14 aliases
#define ADC_14_SetHigh()                do { PORTE.OUTSET = PIN6_bm; } while(0)
#define ADC_14_SetLow()                 do { PORTE.OUTCLR = PIN6_bm; } while(0)
#define ADC_14_Toggle()                 do { PORTE.OUTTGL = PIN6_bm; } while(0)
#define ADC_14_GetValue()              (VPORTE.IN & PIN6_bm)
#define ADC_14_SetDigitalInput()       do { PORTE.DIRCLR = PIN6_bm; } while(0)
#define ADC_14_SetDigitalOutput()      do { PORTE.DIRSET = PIN6_bm; } while(0)
#define ADC_14_SetPullUp()             do { PORTE.PIN6CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_14_ResetPullUp()           do { PORTE.PIN6CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_14_SetInverted()           do { PORTE.PIN6CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_14_ResetInverted()         do { PORTE.PIN6CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_14_DisableInterruptOnChange()        do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_14_EnableInterruptForBothEdges()     do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_14_EnableInterruptForRisingEdge()    do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_14_EnableInterruptForFallingEdge()   do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_14_DisableDigitalInputBuffer()       do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_14_EnableInterruptForLowLevelSensing() do { PORTE.PIN6CTRL = (PORTE.PIN6CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE6_SetInterruptHandler ADC_14_SetInterruptHandler


//get/set ADC_15 aliases
#define ADC_15_SetHigh()                do { PORTE.OUTSET = PIN7_bm; } while(0)
#define ADC_15_SetLow()                 do { PORTE.OUTCLR = PIN7_bm; } while(0)
#define ADC_15_Toggle()                 do { PORTE.OUTTGL = PIN7_bm; } while(0)
#define ADC_15_GetValue()              (VPORTE.IN & PIN7_bm)
#define ADC_15_SetDigitalInput()       do { PORTE.DIRCLR = PIN7_bm; } while(0)
#define ADC_15_SetDigitalOutput()      do { PORTE.DIRSET = PIN7_bm; } while(0)
#define ADC_15_SetPullUp()             do { PORTE.PIN7CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_15_ResetPullUp()           do { PORTE.PIN7CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_15_SetInverted()           do { PORTE.PIN7CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_15_ResetInverted()         do { PORTE.PIN7CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_15_DisableInterruptOnChange()        do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_15_EnableInterruptForBothEdges()     do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_15_EnableInterruptForRisingEdge()    do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_15_EnableInterruptForFallingEdge()   do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_15_DisableDigitalInputBuffer()       do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_15_EnableInterruptForLowLevelSensing() do { PORTE.PIN7CTRL = (PORTE.PIN7CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PE7_SetInterruptHandler ADC_15_SetInterruptHandler


//get/set ADC_16 aliases
#define ADC_16_SetHigh()                do { PORTF.OUTSET = PIN2_bm; } while(0)
#define ADC_16_SetLow()                 do { PORTF.OUTCLR = PIN2_bm; } while(0)
#define ADC_16_Toggle()                 do { PORTF.OUTTGL = PIN2_bm; } while(0)
#define ADC_16_GetValue()              (VPORTF.IN & PIN2_bm)
#define ADC_16_SetDigitalInput()       do { PORTF.DIRCLR = PIN2_bm; } while(0)
#define ADC_16_SetDigitalOutput()      do { PORTF.DIRSET = PIN2_bm; } while(0)
#define ADC_16_SetPullUp()             do { PORTF.PIN2CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_16_ResetPullUp()           do { PORTF.PIN2CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_16_SetInverted()           do { PORTF.PIN2CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_16_ResetInverted()         do { PORTF.PIN2CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_16_DisableInterruptOnChange()        do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_16_EnableInterruptForBothEdges()     do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_16_EnableInterruptForRisingEdge()    do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_16_EnableInterruptForFallingEdge()   do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_16_DisableDigitalInputBuffer()       do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_16_EnableInterruptForLowLevelSensing() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PF2_SetInterruptHandler ADC_16_SetInterruptHandler


//get/set ADC_17 aliases
#define ADC_17_SetHigh()                do { PORTF.OUTSET = PIN3_bm; } while(0)
#define ADC_17_SetLow()                 do { PORTF.OUTCLR = PIN3_bm; } while(0)
#define ADC_17_Toggle()                 do { PORTF.OUTTGL = PIN3_bm; } while(0)
#define ADC_17_GetValue()              (VPORTF.IN & PIN3_bm)
#define ADC_17_SetDigitalInput()       do { PORTF.DIRCLR = PIN3_bm; } while(0)
#define ADC_17_SetDigitalOutput()      do { PORTF.DIRSET = PIN3_bm; } while(0)
#define ADC_17_SetPullUp()             do { PORTF.PIN3CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_17_ResetPullUp()           do { PORTF.PIN3CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_17_SetInverted()           do { PORTF.PIN3CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_17_ResetInverted()         do { PORTF.PIN3CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_17_DisableInterruptOnChange()        do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_17_EnableInterruptForBothEdges()     do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_17_EnableInterruptForRisingEdge()    do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_17_EnableInterruptForFallingEdge()   do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_17_DisableDigitalInputBuffer()       do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_17_EnableInterruptForLowLevelSensing() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PF3_SetInterruptHandler ADC_17_SetInterruptHandler


//get/set ADC_18 aliases
#define ADC_18_SetHigh()                do { PORTF.OUTSET = PIN4_bm; } while(0)
#define ADC_18_SetLow()                 do { PORTF.OUTCLR = PIN4_bm; } while(0)
#define ADC_18_Toggle()                 do { PORTF.OUTTGL = PIN4_bm; } while(0)
#define ADC_18_GetValue()              (VPORTF.IN & PIN4_bm)
#define ADC_18_SetDigitalInput()       do { PORTF.DIRCLR = PIN4_bm; } while(0)
#define ADC_18_SetDigitalOutput()      do { PORTF.DIRSET = PIN4_bm; } while(0)
#define ADC_18_SetPullUp()             do { PORTF.PIN4CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_18_ResetPullUp()           do { PORTF.PIN4CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_18_SetInverted()           do { PORTF.PIN4CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_18_ResetInverted()         do { PORTF.PIN4CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_18_DisableInterruptOnChange()        do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_18_EnableInterruptForBothEdges()     do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_18_EnableInterruptForRisingEdge()    do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_18_EnableInterruptForFallingEdge()   do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_18_DisableDigitalInputBuffer()       do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_18_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PF4_SetInterruptHandler ADC_18_SetInterruptHandler


//get/set ADC_19 aliases
#define ADC_19_SetHigh()                do { PORTF.OUTSET = PIN5_bm; } while(0)
#define ADC_19_SetLow()                 do { PORTF.OUTCLR = PIN5_bm; } while(0)
#define ADC_19_Toggle()                 do { PORTF.OUTTGL = PIN5_bm; } while(0)
#define ADC_19_GetValue()              (VPORTF.IN & PIN5_bm)
#define ADC_19_SetDigitalInput()       do { PORTF.DIRCLR = PIN5_bm; } while(0)
#define ADC_19_SetDigitalOutput()      do { PORTF.DIRSET = PIN5_bm; } while(0)
#define ADC_19_SetPullUp()             do { PORTF.PIN5CTRL |= PORT_PULLUPEN_bm; } while(0)
#define ADC_19_ResetPullUp()           do { PORTF.PIN5CTRL &= ~PORT_PULLUPEN_bm; } while(0)
#define ADC_19_SetInverted()           do { PORTF.PIN5CTRL |= PORT_INVEN_bm; } while(0)
#define ADC_19_ResetInverted()         do { PORTF.PIN5CTRL &= ~PORT_INVEN_bm; } while(0)
#define ADC_19_DisableInterruptOnChange()        do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x0; } while(0)
#define ADC_19_EnableInterruptForBothEdges()     do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x1; } while(0)
#define ADC_19_EnableInterruptForRisingEdge()    do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x2; } while(0)
#define ADC_19_EnableInterruptForFallingEdge()   do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x3; } while(0)
#define ADC_19_DisableDigitalInputBuffer()       do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x4; } while(0)
#define ADC_19_EnableInterruptForLowLevelSensing() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x5; } while(0)
#define PF5_SetInterruptHandler ADC_19_SetInterruptHandler


//get/set CTR_13 aliases
#define CTR_13_SetHigh() do { PORTG_OUTSET = 0x2; } while(0)
#define CTR_13_SetLow() do { PORTG_OUTCLR = 0x2; } while(0)
#define CTR_13_Toggle() do { PORTG_OUTTGL = 0x2; } while(0)
#define CTR_13_GetValue() (VPORTG.IN & (0x1 << 1))
#define CTR_13_SetDigitalInput() do { PORTG_DIRCLR = 0x2; } while(0)
#define CTR_13_SetDigitalOutput() do { PORTG_DIRSET = 0x2; } while(0)
#define CTR_13_SetPullUp() do { PORTG_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_13_ResetPullUp() do { PORTG_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_13_SetInverted() do { PORTG_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_13_ResetInverted() do { PORTG_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_13_DisableInterruptOnChange() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_13_EnableInterruptForBothEdges() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_13_EnableInterruptForRisingEdge() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_13_EnableInterruptForFallingEdge() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_13_DisableDigitalInputBuffer() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_13_EnableInterruptForLowLevelSensing() do { PORTG.PIN1CTRL = (PORTG.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG1_SetInterruptHandler CTR_13_SetInterruptHandler

//get/set CTR_14 aliases
#define CTR_14_SetHigh() do { PORTG_OUTSET = 0x4; } while(0)
#define CTR_14_SetLow() do { PORTG_OUTCLR = 0x4; } while(0)
#define CTR_14_Toggle() do { PORTG_OUTTGL = 0x4; } while(0)
#define CTR_14_GetValue() (VPORTG.IN & (0x1 << 2))
#define CTR_14_SetDigitalInput() do { PORTG_DIRCLR = 0x4; } while(0)
#define CTR_14_SetDigitalOutput() do { PORTG_DIRSET = 0x4; } while(0)
#define CTR_14_SetPullUp() do { PORTG_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_14_ResetPullUp() do { PORTG_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_14_SetInverted() do { PORTG_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_14_ResetInverted() do { PORTG_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_14_DisableInterruptOnChange() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_14_EnableInterruptForBothEdges() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_14_EnableInterruptForRisingEdge() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_14_EnableInterruptForFallingEdge() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_14_DisableDigitalInputBuffer() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_14_EnableInterruptForLowLevelSensing() do { PORTG.PIN2CTRL = (PORTG.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG2_SetInterruptHandler CTR_14_SetInterruptHandler

//get/set CTR_15 aliases
#define CTR_15_SetHigh() do { PORTG_OUTSET = 0x8; } while(0)
#define CTR_15_SetLow() do { PORTG_OUTCLR = 0x8; } while(0)
#define CTR_15_Toggle() do { PORTG_OUTTGL = 0x8; } while(0)
#define CTR_15_GetValue() (VPORTG.IN & (0x1 << 3))
#define CTR_15_SetDigitalInput() do { PORTG_DIRCLR = 0x8; } while(0)
#define CTR_15_SetDigitalOutput() do { PORTG_DIRSET = 0x8; } while(0)
#define CTR_15_SetPullUp() do { PORTG_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_15_ResetPullUp() do { PORTG_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_15_SetInverted() do { PORTG_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_15_ResetInverted() do { PORTG_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_15_DisableInterruptOnChange() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_15_EnableInterruptForBothEdges() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_15_EnableInterruptForRisingEdge() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_15_EnableInterruptForFallingEdge() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_15_DisableDigitalInputBuffer() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_15_EnableInterruptForLowLevelSensing() do { PORTG.PIN3CTRL = (PORTG.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG3_SetInterruptHandler CTR_15_SetInterruptHandler

//get/set CTR_16 aliases
#define CTR_16_SetHigh() do { PORTG_OUTSET = 0x10; } while(0)
#define CTR_16_SetLow() do { PORTG_OUTCLR = 0x10; } while(0)
#define CTR_16_Toggle() do { PORTG_OUTTGL = 0x10; } while(0)
#define CTR_16_GetValue() (VPORTG.IN & (0x1 << 4))
#define CTR_16_SetDigitalInput() do { PORTG_DIRCLR = 0x10; } while(0)
#define CTR_16_SetDigitalOutput() do { PORTG_DIRSET = 0x10; } while(0)
#define CTR_16_SetPullUp() do { PORTG_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_16_ResetPullUp() do { PORTG_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_16_SetInverted() do { PORTG_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_16_ResetInverted() do { PORTG_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_16_DisableInterruptOnChange() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_16_EnableInterruptForBothEdges() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_16_EnableInterruptForRisingEdge() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_16_EnableInterruptForFallingEdge() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_16_DisableDigitalInputBuffer() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_16_EnableInterruptForLowLevelSensing() do { PORTG.PIN4CTRL = (PORTG.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG4_SetInterruptHandler CTR_16_SetInterruptHandler

//get/set CTR_17 aliases
#define CTR_17_SetHigh() do { PORTG_OUTSET = 0x20; } while(0)
#define CTR_17_SetLow() do { PORTG_OUTCLR = 0x20; } while(0)
#define CTR_17_Toggle() do { PORTG_OUTTGL = 0x20; } while(0)
#define CTR_17_GetValue() (VPORTG.IN & (0x1 << 5))
#define CTR_17_SetDigitalInput() do { PORTG_DIRCLR = 0x20; } while(0)
#define CTR_17_SetDigitalOutput() do { PORTG_DIRSET = 0x20; } while(0)
#define CTR_17_SetPullUp() do { PORTG_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_17_ResetPullUp() do { PORTG_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_17_SetInverted() do { PORTG_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_17_ResetInverted() do { PORTG_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_17_DisableInterruptOnChange() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_17_EnableInterruptForBothEdges() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_17_EnableInterruptForRisingEdge() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_17_EnableInterruptForFallingEdge() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_17_DisableDigitalInputBuffer() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_17_EnableInterruptForLowLevelSensing() do { PORTG.PIN5CTRL = (PORTG.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG5_SetInterruptHandler CTR_17_SetInterruptHandler

//get/set CTR_18 aliases
#define CTR_18_SetHigh() do { PORTG_OUTSET = 0x40; } while(0)
#define CTR_18_SetLow() do { PORTG_OUTCLR = 0x40; } while(0)
#define CTR_18_Toggle() do { PORTG_OUTTGL = 0x40; } while(0)
#define CTR_18_GetValue() (VPORTG.IN & (0x1 << 6))
#define CTR_18_SetDigitalInput() do { PORTG_DIRCLR = 0x40; } while(0)
#define CTR_18_SetDigitalOutput() do { PORTG_DIRSET = 0x40; } while(0)
#define CTR_18_SetPullUp() do { PORTG_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_18_ResetPullUp() do { PORTG_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_18_SetInverted() do { PORTG_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_18_ResetInverted() do { PORTG_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_18_DisableInterruptOnChange() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_18_EnableInterruptForBothEdges() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_18_EnableInterruptForRisingEdge() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_18_EnableInterruptForFallingEdge() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_18_DisableDigitalInputBuffer() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_18_EnableInterruptForLowLevelSensing() do { PORTG.PIN6CTRL = (PORTG.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG6_SetInterruptHandler CTR_18_SetInterruptHandler

//get/set CTR_19 aliases
#define CTR_19_SetHigh() do { PORTG_OUTSET = 0x80; } while(0)
#define CTR_19_SetLow() do { PORTG_OUTCLR = 0x80; } while(0)
#define CTR_19_Toggle() do { PORTG_OUTTGL = 0x80; } while(0)
#define CTR_19_GetValue() (VPORTG.IN & (0x1 << 7))
#define CTR_19_SetDigitalInput() do { PORTG_DIRCLR = 0x80; } while(0)
#define CTR_19_SetDigitalOutput() do { PORTG_DIRSET = 0x80; } while(0)
#define CTR_19_SetPullUp() do { PORTG_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CTR_19_ResetPullUp() do { PORTG_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CTR_19_SetInverted() do { PORTG_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define CTR_19_ResetInverted() do { PORTG_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CTR_19_DisableInterruptOnChange() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CTR_19_EnableInterruptForBothEdges() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CTR_19_EnableInterruptForRisingEdge() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CTR_19_EnableInterruptForFallingEdge() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CTR_19_DisableDigitalInputBuffer() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CTR_19_EnableInterruptForLowLevelSensing() do { PORTG.PIN7CTRL = (PORTG.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PG7_SetInterruptHandler CTR_19_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CTR_0 pin. 
 *        This is a predefined interrupt handler to be used together with the CTR_0_SetInterruptHandler() method.
 *        This handler is called every time the CTR_0 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CTR_0_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CTR_0 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CTR_0 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CTR_0_SetInterruptHandler(void (* interruptHandler)(void)) ; 

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
 * @brief Default Interrupt Handler for ADC_0 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_0_SetInterruptHandler() method.
 *        This handler is called every time the ADC_0 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_0_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_0 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_0 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_0_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_1 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_1_SetInterruptHandler() method.
 *        This handler is called every time the ADC_1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_2 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_2_SetInterruptHandler() method.
 *        This handler is called every time the ADC_2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_3 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_3_SetInterruptHandler() method.
 *        This handler is called every time the ADC_3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_4 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_4_SetInterruptHandler() method.
 *        This handler is called every time the ADC_4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_5 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_5_SetInterruptHandler() method.
 *        This handler is called every time the ADC_5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_5_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_6 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_6_SetInterruptHandler() method.
 *        This handler is called every time the ADC_6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_7 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_7_SetInterruptHandler() method.
 *        This handler is called every time the ADC_7 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_7_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_7 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_7 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_7_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_8 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_8_SetInterruptHandler() method.
 *        This handler is called every time the ADC_8 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_8_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_8 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_8 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_8_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_9 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_9_SetInterruptHandler() method.
 *        This handler is called every time the ADC_9 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_9_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_9 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_9 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_9_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_10 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_10_SetInterruptHandler() method.
 *        This handler is called every time the ADC_10 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_10_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_10 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_10 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_10_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_11 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_11_SetInterruptHandler() method.
 *        This handler is called every time the ADC_11 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_11_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_11 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_11 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_11_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_12 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_12_SetInterruptHandler() method.
 *        This handler is called every time the ADC_12 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_12_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_12 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_12 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_12_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_13 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_13_SetInterruptHandler() method.
 *        This handler is called every time the ADC_13 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_13_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_13 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_13 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_13_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_14 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_14_SetInterruptHandler() method.
 *        This handler is called every time the ADC_14 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_14_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_14 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_14 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_14_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_15 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_15_SetInterruptHandler() method.
 *        This handler is called every time the ADC_15 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_15_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_15 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_15 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_15_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_16 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_16_SetInterruptHandler() method.
 *        This handler is called every time the ADC_16 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_16_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_16 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_16 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_16_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_17 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_17_SetInterruptHandler() method.
 *        This handler is called every time the ADC_17 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_17_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_17 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_17 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_17_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_18 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_18_SetInterruptHandler() method.
 *        This handler is called every time the ADC_18 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_18_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_18 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_18 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_18_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADC_19 pin. 
 *        This is a predefined interrupt handler to be used together with the ADC_19_SetInterruptHandler() method.
 *        This handler is called every time the ADC_19 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADC_19_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADC_19 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADC_19 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADC_19_SetInterruptHandler(void (* interruptHandler)(void)) ; 

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
#endif /* PINS_H_INCLUDED */
