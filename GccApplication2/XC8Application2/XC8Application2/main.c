/*
 * MAIN Generated Driver File
 */

#include "mcc_generated_files/system/system.h"
#include <math.h>
#include <util/delay.h>

#define TRUNCATED_SHIFT 4
#define NUM_PINS 20
#define MAX_VOLTAGE 3.3
#define ADC_RESOLUTION 4095.0f

struct {
	uint32_t result;
	uint16_t average_result;
} adc_data[NUM_PINS];

float voltage;

typedef struct {
	float val_1_00;
	float val_1_01;
	float val_1_10;
	float val_1_11;
	float val_2_00;
	float val_2_01;
	float val_2_10;
	float val_2_11;
} DataStruct;

DataStruct myArray[NUM_PINS][NUM_PINS] = {0};

// Map ADC channel to correct MUXPOS input
uint8_t adc_channel_map[NUM_PINS] = {
	ADC_MUXPOS_AIN0_gc, ADC_MUXPOS_AIN1_gc, ADC_MUXPOS_AIN2_gc, ADC_MUXPOS_AIN3_gc,
	ADC_MUXPOS_AIN4_gc, ADC_MUXPOS_AIN5_gc, ADC_MUXPOS_AIN6_gc, ADC_MUXPOS_AIN7_gc,
	ADC_MUXPOS_AIN8_gc, ADC_MUXPOS_AIN9_gc, ADC_MUXPOS_AIN10_gc, ADC_MUXPOS_AIN11_gc,
	ADC_MUXPOS_AIN12_gc, ADC_MUXPOS_AIN13_gc, ADC_MUXPOS_AIN14_gc, ADC_MUXPOS_AIN15_gc,
	ADC_MUXPOS_AIN18_gc, ADC_MUXPOS_AIN19_gc, ADC_MUXPOS_AIN20_gc, ADC_MUXPOS_AIN21_gc
};

float process_adc_conversion(uint8_t current_channel) {
	ADC0.MUXPOS = adc_channel_map[current_channel];
	ADC0.COMMAND = ADC_STCONV_bm;
	while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
	ADC0.INTFLAGS = ADC_RESRDY_bm;
	uint16_t result = ADC0.RES;
	float voltage = (result * MAX_VOLTAGE) / ADC_RESOLUTION;
	return voltage;
}

void setOutput(int n); void setInput(int n); void setHigh(int n); void setLow(int n);

void characterize(int pin1, int pin2) {
	if (pin1 != pin2) {
		setOutput(pin1);
		setOutput(pin2);
		setHigh(pin1);
		setLow(pin2);
		myArray[pin1][pin2].val_1_10 = process_adc_conversion(pin1);
		myArray[pin1][pin2].val_2_10 = process_adc_conversion(pin2);
		setLow(pin1);
		setHigh(pin2);
		myArray[pin1][pin2].val_1_01 = process_adc_conversion(pin1);
		myArray[pin1][pin2].val_2_01 = process_adc_conversion(pin2);
		myArray[pin1][pin2].val_1_11 = 3.3;
		myArray[pin1][pin2].val_2_11 = 3.3;
		setInput(pin1);
		setInput(pin2);
	}
}

bool check_adc_within_range(int pin1, int pin2) {
	setOutput(pin1);
	setOutput(pin2);
	setHigh(pin1);
	setLow(pin2);
	if (fabs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_10) > 0.1 ||
		fabs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_10) > 0.1)
		return false;
	setLow(pin1);
	setHigh(pin2);
	if (fabs(process_adc_conversion(pin1) - myArray[pin1][pin2].val_1_01) > 0.1 ||
		fabs(process_adc_conversion(pin2) - myArray[pin1][pin2].val_2_01) > 0.1)
		return false;
	setInput(pin1);
	setInput(pin2);
	return true;
}

void relay_init() {
	PORTG.DIRSET = PIN0_bm;
	PORTG.OUTSET = PIN0_bm;
}

void setOutput(int n) {
	switch (n) {
		case 0: PORTA.DIRSET = PIN7_bm; break;
		case 1 ... 6: PORTB.DIRSET = (1 << (n + 1)); break;
		case 7 ... 12: PORTC.DIRSET = (1 << (n - 5)); break;
		case 13 ... 19: PORTG.DIRSET = (1 << (n - 12)); break;
	}
}

void setInput(int n) {
	switch (n) {
		case 0: PORTA.DIRCLR = PIN7_bm; break;
		case 1 ... 6: PORTB.DIRCLR = (1 << (n + 1)); break;
		case 7 ... 12: PORTC.DIRCLR = (1 << (n - 5)); break;
		case 13 ... 19: PORTG.DIRCLR = (1 << (n - 12)); break;
	}
}

void setHigh(int n) {
	switch (n) {
		case 0: PORTA.OUTSET = PIN7_bm; break;
		case 1 ... 6: PORTB.OUTSET = (1 << (n + 1)); break;
		case 7 ... 12: PORTC.OUTSET = (1 << (n - 5)); break;
		case 13 ... 19: PORTG.OUTSET = (1 << (n - 12)); break;
	}
}

void setLow(int n) {
	switch (n) {
		case 0: PORTA.OUTCLR = PIN7_bm; break;
		case 1 ... 6: PORTB.OUTCLR = (1 << (n + 1)); break;
		case 7 ... 12: PORTC.OUTCLR = (1 << (n - 5)); break;
		case 13 ... 19: PORTG.OUTCLR = (1 << (n - 12)); break;
	}
}

int main(void) {
	SYSTEM_Initialize();
	relay_init();
	for (int i = 0; i < NUM_PINS; i++) {
		setOutput(i);
		setHigh(i);
	}
	while (1) {
		if (process_adc_conversion(0) > 3) {
			PORTG.OUTSET = PIN0_bm;
			_delay_ms(1000);
			PORTG.OUTCLR = PIN0_bm;
			_delay_ms(1000);
		} else {
			PORTG.OUTSET = PIN0_bm;
			_delay_ms(200);
			PORTG.OUTCLR = PIN0_bm;
			_delay_ms(200);
		}
	}
}