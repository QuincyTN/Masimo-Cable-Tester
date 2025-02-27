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
static void (*AIN_0_InterruptHandler)(void);
static void (*AIN_1_InterruptHandler)(void);
static void (*AIN_2_InterruptHandler)(void);
static void (*AIN_3_InterruptHandler)(void);
static void (*CTR_0_InterruptHandler)(void);
static void (*CTR_1_InterruptHandler)(void);
static void (*CTR_2_InterruptHandler)(void);
static void (*CTR_3_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{

  /* OUT Registers Initialization */
    PORTA.OUT = 0x0;
    PORTB.OUT = 0x0;
    PORTC.OUT = 0x0;
    PORTD.OUT = 0x0;
    PORTE.OUT = 0x0;
    PORTF.OUT = 0x0;

  /* DIR Registers Initialization */
    PORTA.DIR = 0x0;
    PORTB.DIR = 0x1;
    PORTC.DIR = 0xF0;
    PORTD.DIR = 0x0;
    PORTE.DIR = 0x0;
    PORTF.DIR = 0x0;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x0;
    PORTA.PIN3CTRL = 0x0;
    PORTA.PIN4CTRL = 0x0;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x0;
    PORTB.PIN0CTRL = 0x0;
    PORTB.PIN1CTRL = 0x0;
    PORTB.PIN2CTRL = 0x0;
    PORTB.PIN3CTRL = 0x0;
    PORTB.PIN4CTRL = 0x0;
    PORTB.PIN5CTRL = 0x0;
    PORTB.PIN6CTRL = 0x0;
    PORTB.PIN7CTRL = 0x0;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x0;
    PORTC.PIN2CTRL = 0x0;
    PORTC.PIN3CTRL = 0x0;
    PORTC.PIN4CTRL = 0x4;
    PORTC.PIN5CTRL = 0x4;
    PORTC.PIN6CTRL = 0x4;
    PORTC.PIN7CTRL = 0x4;
    PORTD.PIN0CTRL = 0x4;
    PORTD.PIN1CTRL = 0x4;
    PORTD.PIN2CTRL = 0x4;
    PORTD.PIN3CTRL = 0x4;
    PORTD.PIN4CTRL = 0x0;
    PORTD.PIN5CTRL = 0x0;
    PORTD.PIN6CTRL = 0x0;
    PORTD.PIN7CTRL = 0x0;
    PORTE.PIN0CTRL = 0x0;
    PORTE.PIN1CTRL = 0x0;
    PORTE.PIN2CTRL = 0x0;
    PORTE.PIN3CTRL = 0x0;
    PORTE.PIN4CTRL = 0x0;
    PORTE.PIN5CTRL = 0x0;
    PORTE.PIN6CTRL = 0x0;
    PORTE.PIN7CTRL = 0x0;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x0;
    PORTF.PIN3CTRL = 0x0;
    PORTF.PIN4CTRL = 0x0;
    PORTF.PIN5CTRL = 0x0;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;

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
    AIN_0_SetInterruptHandler(AIN_0_DefaultInterruptHandler);
    AIN_1_SetInterruptHandler(AIN_1_DefaultInterruptHandler);
    AIN_2_SetInterruptHandler(AIN_2_DefaultInterruptHandler);
    AIN_3_SetInterruptHandler(AIN_3_DefaultInterruptHandler);
    CTR_0_SetInterruptHandler(CTR_0_DefaultInterruptHandler);
    CTR_1_SetInterruptHandler(CTR_1_DefaultInterruptHandler);
    CTR_2_SetInterruptHandler(CTR_2_DefaultInterruptHandler);
    CTR_3_SetInterruptHandler(CTR_3_DefaultInterruptHandler);
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
  Allows selecting an interrupt handler for AIN_0 at application runtime
*/
void AIN_0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    AIN_0_InterruptHandler = interruptHandler;
}

void AIN_0_DefaultInterruptHandler(void)
{
    // add your AIN_0 interrupt custom code
    // or set custom function using AIN_0_SetInterruptHandler()
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
  Allows selecting an interrupt handler for CTR_0 at application runtime
*/
void CTR_0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CTR_0_InterruptHandler = interruptHandler;
}

void CTR_0_DefaultInterruptHandler(void)
{
    // add your CTR_0 interrupt custom code
    // or set custom function using CTR_0_SetInterruptHandler()
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
ISR(PORTA_PORT_vect)
{ 
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
    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT4_bm)
    {
       CTR_0_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT5_bm)
    {
       CTR_1_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT6_bm)
    {
       CTR_2_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT7_bm)
    {
       CTR_3_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT0_bm)
    {
       AIN_0_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT1_bm)
    {
       AIN_1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       AIN_2_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       AIN_3_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTE_PORT_vect)
{ 
    /* Clear interrupt flags */
    VPORTE.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

/**
 End of File
*/