/*
 * req_res_prototype.c
 *
 * Purpose: Develop request and response protocols for the MCU (AVR128DB48) and HMI (NX4827P043-011C)
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>
#include <inttypes.h>
#include <util/delay.h>

#include "Headers/global_consts_vars.h"
#include "Headers/hmi_mcu_com.h"
#include "Headers/debug_term_mcu_com.h"


void portInit(){
	/*
	Purpose: initialize port and pin directions (as input/output)
	PORTx.DIRSET is the register to set port x's pin directions
	x can be A,B,C,D,E,F with register sizes PA[7:0], PB[5:0], PC[7:0], PD[7:0], PE[3:0], PF[6:0]
	*/
	PORTB.DIRSET = (1<<3);		//set 3rd pin of PORTB to output, LED on board
	PORTB.OUT |= (1<<3);		//turn LED off
}

void initTimer1s() {
	//Set the period for 1 second
	TCA0.SINGLE.PER = (F_CPU / PRESCALER) - 1; // 23437 for 1s

	//Enable overflow interrupt
	TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;

	//Set prescaler to 1024 and enable timer
	TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1024_gc | TCA_SINGLE_ENABLE_bm;
}

ISR(TCA0_OVF_vect) {
	//get a value every second
	/*
	switch((timerFlag++)%4){
		case 0: transmitHmi(PAGE_MCU,N0,VAL,NULL, 1); break;
		case 1: transmitHmi(PAGE_MCU,N1,VAL,NULL, 1); break;
		case 2: transmitHmi(PAGE_MCU,T2,TXT,NULL, 1); break;
		case 3: transmitHmi(PAGE_MCU,T3,TXT,NULL, 1); break;
		default: transmitHmi(PAGE_MCU,N0,VAL,NULL, 1); break;
	}
	*/
	TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;	//reset overflow flag
}


int main(void)
{
    ccp_write_io(&(CLKCTRL.OSCHFCTRLA),CLKCTRL_FRQSEL_24M_gc);	//set main clock to 24MHz
	portInit();
    initUSART3();	//initialize USART3 to display information received from HMI
    initUSART2();	//initialize USART2 to transmit and receive from HMI
	//initTimer1s();	//initialize 1s timer
    sei();			//turn on global interrupts
	
	transmitTerminal(helpMenu);
    while (1) 
    {
		//Display the message on the terminal using USART3
		if(newHmiMessage){
			parseHmiData(hmiBuffer);
			newHmiMessage = 0;	//reset flag
		}
		if(newTerminalMessage){
			parseTerminalData(terminalBuffer);
			//transmitHmi("page0", "c0", NULL, terminalBuffer, 0);
			newTerminalMessage = 0;	//reset flag
		}
		if(testingStart){
			//Happens continuously while flag is set
			//TODO: add testing function 
			//Testing function should set a fault flag when it is detected
		}
    }
}

