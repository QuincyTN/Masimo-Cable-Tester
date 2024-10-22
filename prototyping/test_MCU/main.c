/*
 * test_MCU.c
 *
 * Created: 10/22/2024 1:53:39 PM
 * Purpose: learn GPIO and pins of the AVR128DB48 Curiosity Nano
 * MCU: AVR128DB48 Curiosity Nano 24MHz
 */ 

//#define F_CPU 24000000UL //CPU frequency is 24MHz
#define F_CPU 4000000UL //running at 4MHz make delay function work??
#include <avr/io.h>
#include <util/delay.h>

void port_init(){
	/*
	Purpose: initialize port and pin directions (as input/output)
	PORTx.DIRSET is the register to set port x's pin directions
	x can be A,B,C,D,E,F with register sizes PA[7:0], PB[5:0], PC[7:0], PD[7:0], PE[3:0], PF[6:0]
	*/
	PORTB.DIRSET |= (1<<3);		//set 3rd pin of PORTB to output, LED on board
}

void blink_LED(){
	//Flash LED with 2s period
	PORTB.OUT |= (1<<3);	//turn LED on
	_delay_ms(1000);
	PORTB.OUT &= ~(1<<3);	//turn LED off
	_delay_ms(1000);
}

int main(void)
{
	port_init();	

    while (1) 
    {
		blink_LED();
    }
}

