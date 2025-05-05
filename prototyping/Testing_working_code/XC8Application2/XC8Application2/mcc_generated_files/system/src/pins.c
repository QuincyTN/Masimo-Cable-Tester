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

static void (*CTR_0_InterruptHandler)(void);
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
static void (*ADC_0_InterruptHandler)(void);
static void (*ADC_1_InterruptHandler)(void);
static void (*ADC_2_InterruptHandler)(void);
static void (*ADC_3_InterruptHandler)(void);
static void (*ADC_4_InterruptHandler)(void);
static void (*ADC_5_InterruptHandler)(void);
static void (*ADC_6_InterruptHandler)(void);
static void (*ADC_7_InterruptHandler)(void);
static void (*ADC_8_InterruptHandler)(void);
static void (*ADC_9_InterruptHandler)(void);
static void (*ADC_10_InterruptHandler)(void);
static void (*ADC_11_InterruptHandler)(void);
static void (*ADC_12_InterruptHandler)(void);
static void (*ADC_13_InterruptHandler)(void);
static void (*ADC_14_InterruptHandler)(void);
static void (*ADC_15_InterruptHandler)(void);
static void (*ADC_16_InterruptHandler)(void);
static void (*ADC_17_InterruptHandler)(void);
static void (*ADC_18_InterruptHandler)(void);
static void (*ADC_19_InterruptHandler)(void);
static void (*CTR_13_InterruptHandler)(void);
static void (*CTR_14_InterruptHandler)(void);
static void (*CTR_15_InterruptHandler)(void);
static void (*CTR_16_InterruptHandler)(void);
static void (*CTR_17_InterruptHandler)(void);
static void (*CTR_18_InterruptHandler)(void);
static void (*CTR_19_InterruptHandler)(void);

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
    PORTB.DIR = 0xFC;
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
  ///*
    CTR_0_SetInterruptHandler(CTR_0_DefaultInterruptHandler);
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
    ADC_0_SetInterruptHandler(ADC_0_DefaultInterruptHandler);
    ADC_1_SetInterruptHandler(ADC_1_DefaultInterruptHandler);
    ADC_2_SetInterruptHandler(ADC_2_DefaultInterruptHandler);
    ADC_3_SetInterruptHandler(ADC_3_DefaultInterruptHandler);
    ADC_4_SetInterruptHandler(ADC_4_DefaultInterruptHandler);
    ADC_5_SetInterruptHandler(ADC_5_DefaultInterruptHandler);
    ADC_6_SetInterruptHandler(ADC_6_DefaultInterruptHandler);
    ADC_7_SetInterruptHandler(ADC_7_DefaultInterruptHandler);
    ADC_8_SetInterruptHandler(ADC_8_DefaultInterruptHandler);
    ADC_9_SetInterruptHandler(ADC_9_DefaultInterruptHandler);
    ADC_10_SetInterruptHandler(ADC_10_DefaultInterruptHandler);
    ADC_11_SetInterruptHandler(ADC_11_DefaultInterruptHandler);
    ADC_12_SetInterruptHandler(ADC_12_DefaultInterruptHandler);
    ADC_13_SetInterruptHandler(ADC_13_DefaultInterruptHandler);
    ADC_14_SetInterruptHandler(ADC_14_DefaultInterruptHandler);
    ADC_15_SetInterruptHandler(ADC_15_DefaultInterruptHandler);
    ADC_16_SetInterruptHandler(ADC_16_DefaultInterruptHandler);
    ADC_17_SetInterruptHandler(ADC_17_DefaultInterruptHandler);
    ADC_18_SetInterruptHandler(ADC_18_DefaultInterruptHandler);
    ADC_19_SetInterruptHandler(ADC_19_DefaultInterruptHandler);
    CTR_13_SetInterruptHandler(CTR_13_DefaultInterruptHandler);
    CTR_14_SetInterruptHandler(CTR_14_DefaultInterruptHandler);
    CTR_15_SetInterruptHandler(CTR_15_DefaultInterruptHandler);
    CTR_16_SetInterruptHandler(CTR_16_DefaultInterruptHandler);
    CTR_17_SetInterruptHandler(CTR_17_DefaultInterruptHandler);
    CTR_18_SetInterruptHandler(CTR_18_DefaultInterruptHandler);
    CTR_19_SetInterruptHandler(CTR_19_DefaultInterruptHandler);
	//*/
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
  Allows selecting an interrupt handler for ADC_0 at application runtime
*/
void ADC_0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_0_InterruptHandler = interruptHandler;
}

void ADC_0_DefaultInterruptHandler(void)
{
    // add your ADC_0 interrupt custom code
    // or set custom function using ADC_0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_1 at application runtime
*/
void ADC_1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_1_InterruptHandler = interruptHandler;
}

void ADC_1_DefaultInterruptHandler(void)
{
    // add your ADC_1 interrupt custom code
    // or set custom function using ADC_1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_2 at application runtime
*/
void ADC_2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_2_InterruptHandler = interruptHandler;
}

void ADC_2_DefaultInterruptHandler(void)
{
    // add your ADC_2 interrupt custom code
    // or set custom function using ADC_2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_3 at application runtime
*/
void ADC_3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_3_InterruptHandler = interruptHandler;
}

void ADC_3_DefaultInterruptHandler(void)
{
    // add your ADC_3 interrupt custom code
    // or set custom function using ADC_3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_4 at application runtime
*/
void ADC_4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_4_InterruptHandler = interruptHandler;
}

void ADC_4_DefaultInterruptHandler(void)
{
    // add your ADC_4 interrupt custom code
    // or set custom function using ADC_4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_5 at application runtime
*/
void ADC_5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_5_InterruptHandler = interruptHandler;
}

void ADC_5_DefaultInterruptHandler(void)
{
    // add your ADC_5 interrupt custom code
    // or set custom function using ADC_5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_6 at application runtime
*/
void ADC_6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_6_InterruptHandler = interruptHandler;
}

void ADC_6_DefaultInterruptHandler(void)
{
    // add your ADC_6 interrupt custom code
    // or set custom function using ADC_6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_7 at application runtime
*/
void ADC_7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_7_InterruptHandler = interruptHandler;
}

void ADC_7_DefaultInterruptHandler(void)
{
    // add your ADC_7 interrupt custom code
    // or set custom function using ADC_7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_8 at application runtime
*/
void ADC_8_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_8_InterruptHandler = interruptHandler;
}

void ADC_8_DefaultInterruptHandler(void)
{
    // add your ADC_8 interrupt custom code
    // or set custom function using ADC_8_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_9 at application runtime
*/
void ADC_9_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_9_InterruptHandler = interruptHandler;
}

void ADC_9_DefaultInterruptHandler(void)
{
    // add your ADC_9 interrupt custom code
    // or set custom function using ADC_9_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_10 at application runtime
*/
void ADC_10_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_10_InterruptHandler = interruptHandler;
}

void ADC_10_DefaultInterruptHandler(void)
{
    // add your ADC_10 interrupt custom code
    // or set custom function using ADC_10_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_11 at application runtime
*/
void ADC_11_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_11_InterruptHandler = interruptHandler;
}

void ADC_11_DefaultInterruptHandler(void)
{
    // add your ADC_11 interrupt custom code
    // or set custom function using ADC_11_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_12 at application runtime
*/
void ADC_12_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_12_InterruptHandler = interruptHandler;
}

void ADC_12_DefaultInterruptHandler(void)
{
    // add your ADC_12 interrupt custom code
    // or set custom function using ADC_12_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_13 at application runtime
*/
void ADC_13_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_13_InterruptHandler = interruptHandler;
}

void ADC_13_DefaultInterruptHandler(void)
{
    // add your ADC_13 interrupt custom code
    // or set custom function using ADC_13_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_14 at application runtime
*/
void ADC_14_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_14_InterruptHandler = interruptHandler;
}

void ADC_14_DefaultInterruptHandler(void)
{
    // add your ADC_14 interrupt custom code
    // or set custom function using ADC_14_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_15 at application runtime
*/
void ADC_15_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_15_InterruptHandler = interruptHandler;
}

void ADC_15_DefaultInterruptHandler(void)
{
    // add your ADC_15 interrupt custom code
    // or set custom function using ADC_15_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_16 at application runtime
*/
void ADC_16_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_16_InterruptHandler = interruptHandler;
}

void ADC_16_DefaultInterruptHandler(void)
{
    // add your ADC_16 interrupt custom code
    // or set custom function using ADC_16_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_17 at application runtime
*/
void ADC_17_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_17_InterruptHandler = interruptHandler;
}

void ADC_17_DefaultInterruptHandler(void)
{
    // add your ADC_17 interrupt custom code
    // or set custom function using ADC_17_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_18 at application runtime
*/
void ADC_18_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_18_InterruptHandler = interruptHandler;
}

void ADC_18_DefaultInterruptHandler(void)
{
    // add your ADC_18 interrupt custom code
    // or set custom function using ADC_18_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADC_19 at application runtime
*/
void ADC_19_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADC_19_InterruptHandler = interruptHandler;
}

void ADC_19_DefaultInterruptHandler(void)
{
    // add your ADC_19 interrupt custom code
    // or set custom function using ADC_19_SetInterruptHandler()
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
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT7_bm)
    {
       CTR_0_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTB_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTB.INTFLAGS & PORT_INT2_bm)
    {
       CTR_1_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT3_bm)
    {
       CTR_2_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT4_bm)
    {
       CTR_3_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT5_bm)
    {
       CTR_4_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT6_bm)
    {
       CTR_5_InterruptHandler(); 
    }
    if(VPORTB.INTFLAGS & PORT_INT7_bm)
    {
       CTR_6_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       CTR_7_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       CTR_8_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT4_bm)
    {
       CTR_9_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT5_bm)
    {
       CTR_10_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT6_bm)
    {
       CTR_11_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT7_bm)
    {
       CTR_12_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT0_bm)
    {
       ADC_9_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT1_bm)
    {
       ADC_8_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       ADC_7_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       ADC_6_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       ADC_5_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       ADC_4_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       ADC_3_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       ADC_2_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTE_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTE.INTFLAGS & PORT_INT0_bm)
    {
       ADC_1_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT1_bm)
    {
       ADC_0_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT2_bm)
    {
       ADC_10_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT3_bm)
    {
       ADC_11_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT4_bm)
    {
       ADC_12_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT5_bm)
    {
       ADC_13_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT6_bm)
    {
       ADC_14_InterruptHandler(); 
    }
    if(VPORTE.INTFLAGS & PORT_INT7_bm)
    {
       ADC_15_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTE.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT2_bm)
    {
       ADC_16_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT3_bm)
    {
       ADC_17_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT4_bm)
    {
       ADC_18_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT5_bm)
    {
       ADC_19_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

ISR(PORTG_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTG.INTFLAGS & PORT_INT1_bm)
    {
       CTR_13_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT2_bm)
    {
       CTR_14_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT3_bm)
    {
       CTR_15_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT4_bm)
    {
       CTR_16_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT5_bm)
    {
       CTR_17_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT6_bm)
    {
       CTR_18_InterruptHandler(); 
    }
    if(VPORTG.INTFLAGS & PORT_INT7_bm)
    {
       CTR_19_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTG.INTFLAGS = 0xff;
}

/**
 End of File
*/