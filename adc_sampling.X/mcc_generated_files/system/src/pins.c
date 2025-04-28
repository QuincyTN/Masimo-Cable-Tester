/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 1.1.0
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

#include "../pins.h"

static void (*IO_PB1_InterruptHandler)(void);
static void (*IO_PB0_InterruptHandler)(void);
static void (*CTR_1_InterruptHandler)(void);
static void (*CTR_2_InterruptHandler)(void);
static void (*CTR_3_InterruptHandler)(void);
static void (*CTR_4_InterruptHandler)(void);
static void (*CTR_5_InterruptHandler)(void);
static void (*CTR_6_InterruptHandler)(void);
static void (*CTR_7_InterruptHandler)(void);
static void (*CTR_8_InterruptHandler)(void);
static void (*CTR_9_InterruptHandler)(void);
static void (*CTR_10_InterruptHandler)(void);
static void (*CTR_11_InterruptHandler)(void);
static void (*CTR_12_InterruptHandler)(void);
static void (*CTR_13_InterruptHandler)(void);
static void (*AIN_1_InterruptHandler)(void);
static void (*AIN_2_InterruptHandler)(void);
static void (*AIN_3_InterruptHandler)(void);
static void (*AIN_4_InterruptHandler)(void);
static void (*AIN_5_InterruptHandler)(void);
static void (*AIN_6_InterruptHandler)(void);
static void (*AIN_7_InterruptHandler)(void);
static void (*AIN_8_InterruptHandler)(void);
static void (*AIN_9_InterruptHandler)(void);
static void (*AIN_910_InterruptHandler)(void);
static void (*AIN_11_InterruptHandler)(void);
static void (*AIN_12_InterruptHandler)(void);
static void (*AIN_13_InterruptHandler)(void);
static void (*AIN_14_InterruptHandler)(void);
static void (*AIN_15_InterruptHandler)(void);
static void (*AIN_16_InterruptHandler)(void);
static void (*AIN_17_InterruptHandler)(void);
static void (*AIN_18_InterruptHandler)(void);
static void (*AIN_19_InterruptHandler)(void);
static void (*AIN_20_InterruptHandler)(void);
static void (*CTR_14_InterruptHandler)(void);
static void (*CTR_15_InterruptHandler)(void);
static void (*CTR_16_InterruptHandler)(void);
static void (*CTR_17_InterruptHandler)(void);
static void (*CTR_18_InterruptHandler)(void);
static void (*CTR_19_InterruptHandler)(void);
static void (*CTR_20_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{

  /* OUT Registers Initialization */
    PORTA.OUT = 0x0;
    PORTB.OUT = 0x0;
    PORTC.OUT = 0x0;
    PORTD.OUT = 0x0;
    PORTE.OUT = 0x0;
    PORTF.OUT = 0x0;
    PORTG.OUT = 0x0;

  /* DIR Registers Initialization */
    PORTA.DIR = 0x80;
    PORTB.DIR = 0xFD;
    PORTC.DIR = 0xFC;
    PORTD.DIR = 0xFF;
    PORTE.DIR = 0xFF;
    PORTF.DIR = 0x3C;
    PORTG.DIR = 0xFE;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x0;
    PORTA.PIN3CTRL = 0x0;
    PORTA.PIN4CTRL = 0x0;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x4;
    PORTB.PIN0CTRL = 0x0;
    PORTB.PIN1CTRL = 0x0;
    PORTB.PIN2CTRL = 0x4;
    PORTB.PIN3CTRL = 0x4;
    PORTB.PIN4CTRL = 0x4;
    PORTB.PIN5CTRL = 0x4;
    PORTB.PIN6CTRL = 0x4;
    PORTB.PIN7CTRL = 0x4;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x0;
    PORTC.PIN2CTRL = 0x4;
    PORTC.PIN3CTRL = 0x4;
    PORTC.PIN4CTRL = 0x4;
    PORTC.PIN5CTRL = 0x4;
    PORTC.PIN6CTRL = 0x4;
    PORTC.PIN7CTRL = 0x4;
    PORTD.PIN0CTRL = 0x4;
    PORTD.PIN1CTRL = 0x4;
    PORTD.PIN2CTRL = 0x4;
    PORTD.PIN3CTRL = 0x4;
    PORTD.PIN4CTRL = 0x4;
    PORTD.PIN5CTRL = 0x4;
    PORTD.PIN6CTRL = 0x4;
    PORTD.PIN7CTRL = 0x4;
    PORTE.PIN0CTRL = 0x4;
    PORTE.PIN1CTRL = 0x4;
    PORTE.PIN2CTRL = 0x4;
    PORTE.PIN3CTRL = 0x4;
    PORTE.PIN4CTRL = 0x4;
    PORTE.PIN5CTRL = 0x4;
    PORTE.PIN6CTRL = 0x4;
    PORTE.PIN7CTRL = 0x4;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x4;
    PORTF.PIN3CTRL = 0x4;
    PORTF.PIN4CTRL = 0x4;
    PORTF.PIN5CTRL = 0x4;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;
    PORTG.PIN0CTRL = 0x0;
    PORTG.PIN1CTRL = 0x4;
    PORTG.PIN2CTRL = 0x4;
    PORTG.PIN3CTRL = 0x4;
    PORTG.PIN4CTRL = 0x4;
    PORTG.PIN5CTRL = 0x4;
    PORTG.PIN6CTRL = 0x4;
    PORTG.PIN7CTRL = 0x4;

  /* PORTMUX Initialization */
    PORTMUX.ACROUTEA = 0x0;
    PORTMUX.CCLROUTEA = 0x0;
    PORTMUX.EVSYSROUTEA = 0x0;
    PORTMUX.SPIROUTEA = 0x0;
    PORTMUX.TCAROUTEA = 0x0;
    PORTMUX.TCBROUTEA = 0x0;
    PORTMUX.TCDROUTEA = 0x0;
    PORTMUX.TWIROUTEA = 0x0;
    PORTMUX.USARTROUTEA = 0x0;
    PORTMUX.USARTROUTEB = 0x0;
    PORTMUX.ZCDROUTEA = 0x0;

  // register default ISC callback functions at runtime; use these methods to register a custom function
    IO_PB1_SetInterruptHandler(IO_PB1_DefaultInterruptHandler);
    IO_PB0_SetInterruptHandler(IO_PB0_DefaultInterruptHandler);
    CTR_1_SetInterruptHandler(CTR_1_DefaultInterruptHandler);
    CTR_2_SetInterruptHandler(CTR_2_DefaultInterruptHandler);
    CTR_3_SetInterruptHandler(CTR_3_DefaultInterruptHandler);
    CTR_4_SetInterruptHandler(CTR_4_DefaultInterruptHandler);
    CTR_5_SetInterruptHandler(CTR_5_DefaultInterruptHandler);
    CTR_6_SetInterruptHandler(CTR_6_DefaultInterruptHandler);
    CTR_7_SetInterruptHandler(CTR_7_DefaultInterruptHandler);
    CTR_8_SetInterruptHandler(CTR_8_DefaultInterruptHandler);
    CTR_9_SetInterruptHandler(CTR_9_DefaultInterruptHandler);
    CTR_10_SetInterruptHandler(CTR_10_DefaultInterruptHandler);
    CTR_11_SetInterruptHandler(CTR_11_DefaultInterruptHandler);
    CTR_12_SetInterruptHandler(CTR_12_DefaultInterruptHandler);
    CTR_13_SetInterruptHandler(CTR_13_DefaultInterruptHandler);
    AIN_1_SetInterruptHandler(AIN_1_DefaultInterruptHandler);
    AIN_2_SetInterruptHandler(AIN_2_DefaultInterruptHandler);
    AIN_3_SetInterruptHandler(AIN_3_DefaultInterruptHandler);
    AIN_4_SetInterruptHandler(AIN_4_DefaultInterruptHandler);
    AIN_5_SetInterruptHandler(AIN_5_DefaultInterruptHandler);
    AIN_6_SetInterruptHandler(AIN_6_DefaultInterruptHandler);
    AIN_7_SetInterruptHandler(AIN_7_DefaultInterruptHandler);
    AIN_8_SetInterruptHandler(AIN_8_DefaultInterruptHandler);
    AIN_9_SetInterruptHandler(AIN_9_DefaultInterruptHandler);
    AIN_910_SetInterruptHandler(AIN_910_DefaultInterruptHandler);
    AIN_11_SetInterruptHandler(AIN_11_DefaultInterruptHandler);
    AIN_12_SetInterruptHandler(AIN_12_DefaultInterruptHandler);
    AIN_13_SetInterruptHandler(AIN_13_DefaultInterruptHandler);
    AIN_14_SetInterruptHandler(AIN_14_DefaultInterruptHandler);
    AIN_15_SetInterruptHandler(AIN_15_DefaultInterruptHandler);
    AIN_16_SetInterruptHandler(AIN_16_DefaultInterruptHandler);
    AIN_17_SetInterruptHandler(AIN_17_DefaultInterruptHandler);
    AIN_18_SetInterruptHandler(AIN_18_DefaultInterruptHandler);
    AIN_19_SetInterruptHandler(AIN_19_DefaultInterruptHandler);
    AIN_20_SetInterruptHandler(AIN_20_DefaultInterruptHandler);
    CTR_14_SetInterruptHandler(CTR_14_DefaultInterruptHandler);
    CTR_15_SetInterruptHandler(CTR_15_DefaultInterruptHandler);
    CTR_16_SetInterruptHandler(CTR_16_DefaultInterruptHandler);
    CTR_17_SetInterruptHandler(CTR_17_DefaultInterruptHandler);
    CTR_18_SetInterruptHandler(CTR_18_DefaultInterruptHandler);
    CTR_19_SetInterruptHandler(CTR_19_DefaultInterruptHandler);
    CTR_20_SetInterruptHandler(CTR_20_DefaultInterruptHandler);
}

/**
  Allows selecting an interrupt handler for IO_PB1 at application runtime
*/
void IO_PB1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PB1_InterruptHandler = interruptHandler;
}

void IO_PB1_DefaultInterruptHandler(void)
{
    // add your IO_PB1 interrupt custom code
    // or set custom function using IO_PB1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PB0 at application runtime
*/
void IO_PB0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PB0_InterruptHandler = interruptHandler;
}

void IO_PB0_DefaultInterruptHandler(void)
{
    // add your IO_PB0 interrupt custom code
    // or set custom function using IO_PB0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_1 at application runtime
*/
void CTR_1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_1_InterruptHandler = interruptHandler;
}

void CTR_1_DefaultInterruptHandler(void)
{
    // add your CTR_1 interrupt custom code
    // or set custom function using CTR_1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_2 at application runtime
*/
void CTR_2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_2_InterruptHandler = interruptHandler;
}

void CTR_2_DefaultInterruptHandler(void)
{
    // add your CTR_2 interrupt custom code
    // or set custom function using CTR_2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_3 at application runtime
*/
void CTR_3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_3_InterruptHandler = interruptHandler;
}

void CTR_3_DefaultInterruptHandler(void)
{
    // add your CTR_3 interrupt custom code
    // or set custom function using CTR_3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_4 at application runtime
*/
void CTR_4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_4_InterruptHandler = interruptHandler;
}

void CTR_4_DefaultInterruptHandler(void)
{
    // add your CTR_4 interrupt custom code
    // or set custom function using CTR_4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_5 at application runtime
*/
void CTR_5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_5_InterruptHandler = interruptHandler;
}

void CTR_5_DefaultInterruptHandler(void)
{
    // add your CTR_5 interrupt custom code
    // or set custom function using CTR_5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_6 at application runtime
*/
void CTR_6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_6_InterruptHandler = interruptHandler;
}

void CTR_6_DefaultInterruptHandler(void)
{
    // add your CTR_6 interrupt custom code
    // or set custom function using CTR_6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_7 at application runtime
*/
void CTR_7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_7_InterruptHandler = interruptHandler;
}

void CTR_7_DefaultInterruptHandler(void)
{
    // add your CTR_7 interrupt custom code
    // or set custom function using CTR_7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_8 at application runtime
*/
void CTR_8_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_8_InterruptHandler = interruptHandler;
}

void CTR_8_DefaultInterruptHandler(void)
{
    // add your CTR_8 interrupt custom code
    // or set custom function using CTR_8_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_9 at application runtime
*/
void CTR_9_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_9_InterruptHandler = interruptHandler;
}

void CTR_9_DefaultInterruptHandler(void)
{
    // add your CTR_9 interrupt custom code
    // or set custom function using CTR_9_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_10 at application runtime
*/
void CTR_10_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_10_InterruptHandler = interruptHandler;
}

void CTR_10_DefaultInterruptHandler(void)
{
    // add your CTR_10 interrupt custom code
    // or set custom function using CTR_10_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_11 at application runtime
*/
void CTR_11_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_11_InterruptHandler = interruptHandler;
}

void CTR_11_DefaultInterruptHandler(void)
{
    // add your CTR_11 interrupt custom code
    // or set custom function using CTR_11_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_12 at application runtime
*/
void CTR_12_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_12_InterruptHandler = interruptHandler;
}

void CTR_12_DefaultInterruptHandler(void)
{
    // add your CTR_12 interrupt custom code
    // or set custom function using CTR_12_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_13 at application runtime
*/
void CTR_13_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_13_InterruptHandler = interruptHandler;
}

void CTR_13_DefaultInterruptHandler(void)
{
    // add your CTR_13 interrupt custom code
    // or set custom function using CTR_13_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_1 at application runtime
*/
void AIN_1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_1_InterruptHandler = interruptHandler;
}

void AIN_1_DefaultInterruptHandler(void)
{
    // add your AIN_1 interrupt custom code
    // or set custom function using AIN_1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_2 at application runtime
*/
void AIN_2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_2_InterruptHandler = interruptHandler;
}

void AIN_2_DefaultInterruptHandler(void)
{
    // add your AIN_2 interrupt custom code
    // or set custom function using AIN_2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_3 at application runtime
*/
void AIN_3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_3_InterruptHandler = interruptHandler;
}

void AIN_3_DefaultInterruptHandler(void)
{
    // add your AIN_3 interrupt custom code
    // or set custom function using AIN_3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_4 at application runtime
*/
void AIN_4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_4_InterruptHandler = interruptHandler;
}

void AIN_4_DefaultInterruptHandler(void)
{
    // add your AIN_4 interrupt custom code
    // or set custom function using AIN_4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_5 at application runtime
*/
void AIN_5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_5_InterruptHandler = interruptHandler;
}

void AIN_5_DefaultInterruptHandler(void)
{
    // add your AIN_5 interrupt custom code
    // or set custom function using AIN_5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_6 at application runtime
*/
void AIN_6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_6_InterruptHandler = interruptHandler;
}

void AIN_6_DefaultInterruptHandler(void)
{
    // add your AIN_6 interrupt custom code
    // or set custom function using AIN_6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_7 at application runtime
*/
void AIN_7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_7_InterruptHandler = interruptHandler;
}

void AIN_7_DefaultInterruptHandler(void)
{
    // add your AIN_7 interrupt custom code
    // or set custom function using AIN_7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_8 at application runtime
*/
void AIN_8_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_8_InterruptHandler = interruptHandler;
}

void AIN_8_DefaultInterruptHandler(void)
{
    // add your AIN_8 interrupt custom code
    // or set custom function using AIN_8_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_9 at application runtime
*/
void AIN_9_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_9_InterruptHandler = interruptHandler;
}

void AIN_9_DefaultInterruptHandler(void)
{
    // add your AIN_9 interrupt custom code
    // or set custom function using AIN_9_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_910 at application runtime
*/
void AIN_910_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_910_InterruptHandler = interruptHandler;
}

void AIN_910_DefaultInterruptHandler(void)
{
    // add your AIN_910 interrupt custom code
    // or set custom function using AIN_910_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_11 at application runtime
*/
void AIN_11_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_11_InterruptHandler = interruptHandler;
}

void AIN_11_DefaultInterruptHandler(void)
{
    // add your AIN_11 interrupt custom code
    // or set custom function using AIN_11_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_12 at application runtime
*/
void AIN_12_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_12_InterruptHandler = interruptHandler;
}

void AIN_12_DefaultInterruptHandler(void)
{
    // add your AIN_12 interrupt custom code
    // or set custom function using AIN_12_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_13 at application runtime
*/
void AIN_13_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_13_InterruptHandler = interruptHandler;
}

void AIN_13_DefaultInterruptHandler(void)
{
    // add your AIN_13 interrupt custom code
    // or set custom function using AIN_13_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_14 at application runtime
*/
void AIN_14_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_14_InterruptHandler = interruptHandler;
}

void AIN_14_DefaultInterruptHandler(void)
{
    // add your AIN_14 interrupt custom code
    // or set custom function using AIN_14_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_15 at application runtime
*/
void AIN_15_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_15_InterruptHandler = interruptHandler;
}

void AIN_15_DefaultInterruptHandler(void)
{
    // add your AIN_15 interrupt custom code
    // or set custom function using AIN_15_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_16 at application runtime
*/
void AIN_16_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_16_InterruptHandler = interruptHandler;
}

void AIN_16_DefaultInterruptHandler(void)
{
    // add your AIN_16 interrupt custom code
    // or set custom function using AIN_16_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_17 at application runtime
*/
void AIN_17_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_17_InterruptHandler = interruptHandler;
}

void AIN_17_DefaultInterruptHandler(void)
{
    // add your AIN_17 interrupt custom code
    // or set custom function using AIN_17_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_18 at application runtime
*/
void AIN_18_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_18_InterruptHandler = interruptHandler;
}

void AIN_18_DefaultInterruptHandler(void)
{
    // add your AIN_18 interrupt custom code
    // or set custom function using AIN_18_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_19 at application runtime
*/
void AIN_19_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_19_InterruptHandler = interruptHandler;
}

void AIN_19_DefaultInterruptHandler(void)
{
    // add your AIN_19 interrupt custom code
    // or set custom function using AIN_19_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for AIN_20 at application runtime
*/
void AIN_20_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_20_InterruptHandler = interruptHandler;
}

void AIN_20_DefaultInterruptHandler(void)
{
    // add your AIN_20 interrupt custom code
    // or set custom function using AIN_20_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_14 at application runtime
*/
void CTR_14_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_14_InterruptHandler = interruptHandler;
}

void CTR_14_DefaultInterruptHandler(void)
{
    // add your CTR_14 interrupt custom code
    // or set custom function using CTR_14_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_15 at application runtime
*/
void CTR_15_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_15_InterruptHandler = interruptHandler;
}

void CTR_15_DefaultInterruptHandler(void)
{
    // add your CTR_15 interrupt custom code
    // or set custom function using CTR_15_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_16 at application runtime
*/
void CTR_16_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_16_InterruptHandler = interruptHandler;
}

void CTR_16_DefaultInterruptHandler(void)
{
    // add your CTR_16 interrupt custom code
    // or set custom function using CTR_16_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_17 at application runtime
*/
void CTR_17_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_17_InterruptHandler = interruptHandler;
}

void CTR_17_DefaultInterruptHandler(void)
{
    // add your CTR_17 interrupt custom code
    // or set custom function using CTR_17_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_18 at application runtime
*/
void CTR_18_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_18_InterruptHandler = interruptHandler;
}

void CTR_18_DefaultInterruptHandler(void)
{
    // add your CTR_18 interrupt custom code
    // or set custom function using CTR_18_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_19 at application runtime
*/
void CTR_19_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_19_InterruptHandler = interruptHandler;
}

void CTR_19_DefaultInterruptHandler(void)
{
    // add your CTR_19 interrupt custom code
    // or set custom function using CTR_19_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CTR_20 at application runtime
*/
void CTR_20_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_20_InterruptHandler = interruptHandler;
}

void CTR_20_DefaultInterruptHandler(void)
{
    // add your CTR_20 interrupt custom code
    // or set custom function using CTR_20_SetInterruptHandler()
}
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT7_bm)
    {
       CTR_1_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTB_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTB.INTFLAGS & PORT_INT1_bm)
    {
       IO_PB1_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT0_bm)
    {
       IO_PB0_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT2_bm)
    {
       CTR_2_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT3_bm)
    {
       CTR_3_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT4_bm)
    {
       CTR_4_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT5_bm)
    {
       CTR_5_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT6_bm)
    {
       CTR_6_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT7_bm)
    {
       CTR_7_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       CTR_8_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       CTR_9_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT4_bm)
    {
       CTR_10_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT5_bm)
    {
       CTR_11_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT6_bm)
    {
       CTR_12_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT7_bm)
    {
       CTR_13_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT0_bm)
    {
       AIN_1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT1_bm)
    {
       AIN_2_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       AIN_3_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       AIN_4_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       AIN_5_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       AIN_6_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       AIN_7_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       AIN_8_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTE_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTE.INTFLAGS & PORT_INT0_bm)
    {
       AIN_9_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT1_bm)
    {
       AIN_910_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT2_bm)
    {
       AIN_11_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT3_bm)
    {
       AIN_12_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT4_bm)
    {
       AIN_13_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT5_bm)
    {
       AIN_14_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT6_bm)
    {
       AIN_15_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT7_bm)
    {
       AIN_16_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTE.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT2_bm)
    {
       AIN_17_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT3_bm)
    {
       AIN_18_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT4_bm)
    {
       AIN_19_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT5_bm)
    {
       AIN_20_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

ISR(PORTG_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTG.INTFLAGS & PORT_INT1_bm)
    {
       CTR_14_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT2_bm)
    {
       CTR_15_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT3_bm)
    {
       CTR_16_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT4_bm)
    {
       CTR_17_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT5_bm)
    {
       CTR_18_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT6_bm)
    {
       CTR_19_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT7_bm)
    {
       CTR_20_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTG.INTFLAGS = 0xff;
}

/**
 End of File
*/