#include "mcc_generated_files/system/system.h"
#define TRUNCATED_SHIFT 4
#define NUM_PINS 4



//#define TRUNCATED_SHIFT 4  /* Total number of SAMPLES accumulated are 128. Since this is truncated down to 16 bits, dividing ADC result by 16 or right shifting by 4 will give the average 12-bit ADC result */ 
#define MAX_VOLTAGE	 3.3
#define ADC_RESOLUTION 0x0FFF /* In the test setup, VDD = 3.3V, ADC ref is VDD. 12 bit ADC count is 4095 at 3.3V */

struct
{
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


void setLow(int n) {
    switch (n) {
        case 0: CTR_0_SetLow(); break;
        case 1: CTR_1_SetLow(); break;
        case 2: CTR_2_SetLow(); break;
        case 3: CTR_3_SetLow(); break;
//        case 4: CTR_4_SetLow(); break;
//        case 5: CTR_5_SetLow(); break;
//        case 6: CTR_6_SetLow(); break;
//        case 7: CTR_7_SetLow(); break;
//        case 8: CTR_8_SetLow(); break;
//        case 9: CTR_9_SetLow(); break;
        default: printf("Invalid input: %d\n", n); break;
    }
}
void setHigh(int n) {
    switch (n) {
        case 0: CTR_0_SetHigh(); break;
        case 1: CTR_1_SetHigh(); break;
        case 2: CTR_2_SetHigh(); break;
        case 3: CTR_3_SetHigh(); break;
//        case 4: CTR_4_SetHigh(); break;
//        case 5: CTR_5_SetHigh(); break;
//        case 6: CTR_6_SetHigh(); break;
//        case 7: CTR_7_SetHigh(); break;
//        case 8: CTR_8_SetHigh(); break;
//        case 9: CTR_9_SetHigh(); break;
        default: printf("Invalid input: %d\n", n); break;
    }
}
void setInput(int n) {
    switch (n) {
        case 0: CTR_0_SetDigitalInput(); break;
        case 1: CTR_1_SetDigitalInput(); break;
        case 2: CTR_2_SetDigitalInput(); break;
        case 3: CTR_3_SetDigitalInput(); break;
//        case 4: CTR_4_SetHigh(); break;
//        case 5: CTR_5_SetHigh(); break;
//        case 6: CTR_6_SetHigh(); break;
//        case 7: CTR_7_SetHigh(); break;
//        case 8: CTR_8_SetHigh(); break;
//        case 9: CTR_9_SetHigh(); break;
        default: printf("Invalid input: %d\n", n); break;
    }
}
void setOutput(int n) {
    switch (n) {
        case 0: CTR_0_SetDigitalOutput(); break;
        case 1: CTR_1_SetDigitalOutput(); break;
        case 2: CTR_2_SetDigitalOutput(); break;
        case 3: CTR_3_SetDigitalOutput(); break;
//        case 4: CTR_4_SetHigh(); break;
//        case 5: CTR_5_SetHigh(); break;
//        case 6: CTR_6_SetHigh(); break;
//        case 7: CTR_7_SetHigh(); break;
//        case 8: CTR_8_SetHigh(); break;
//        case 9: CTR_9_SetHigh(); break;
        default: printf("Invalid input: %d\n", n); break;
    }
}

float process_adc_conversion(uint8_t current_channel) {
    // Wait for the previous ADC conversion
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
    // Clear result ready flag
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    // Start ADC conversion
    ADC0_StartConversion(current_channel);
    // Wait for the conversion to complete
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
    // Get conversion result
    uint16_t result = ADC0_GetConversionResult();
    uint16_t average_result = (uint16_t)(result >> TRUNCATED_SHIFT);
    // Calculate the voltage
    float voltage = (float)(average_result * MAX_VOLTAGE) / ADC_RESOLUTION;
    // Clear all stored ADC-related data
    adc_data[current_channel].result = 0;
    adc_data[current_channel].average_result = 0;
    
    return voltage;
}

void characterize(int pin1, int pin2) {
    if (pin1 != pin2) {
        //printf("Characterizing pair %d, %d\n", pin1, pin2);
        setOutput(pin1);
        setOutput(pin2);
        //printf("Output Pins set\n");
        myArray[pin1][pin2].val_1_00 = 0;
        myArray[pin1][pin2].val_2_00 = 0;
        setHigh(pin1);
        setLow(pin2);
        //printf("High Low test set\n");
        myArray[pin1][pin2].val_1_10 = process_adc_conversion(pin1);
        myArray[pin1][pin2].val_2_10 = process_adc_conversion(pin2);

        setLow(pin1);
        setHigh(pin2);
        //printf("Low High test set\n");
        myArray[pin1][pin2].val_1_01 = process_adc_conversion(pin1);
        myArray[pin1][pin2].val_2_01 = process_adc_conversion(pin2);
                
        myArray[pin1][pin2].val_1_11 = 3.3;
        myArray[pin1][pin2].val_2_11 = 3.3;

        setInput(pin1);
        setInput(pin2);
        //printf("Input Pins set\n");
    }
}
void printArray() {
    for (int i = 0; i < NUM_PINS; i++) {
        for (int j = 0; j < NUM_PINS; j++) {
            if (i != j) {
            printf("Characterize pair %d, %d\n", i, j);
            printf("Output set to 00 :%.2f %.2f\n", 
                   myArray[i][j].val_1_00, myArray[i][j].val_2_00);
            printf("Output set to 10 :%.2f %.2f\n", 
                   myArray[i][j].val_1_10, myArray[i][j].val_2_10);
            printf("Output set to 01 :%.2f %.2f\n", 
                   myArray[i][j].val_1_01, myArray[i][j].val_2_01);
            printf("Output set to 11 :%.2f %.2f\n", 
                   myArray[i][j].val_1_11, myArray[i][j].val_2_11);
            }
        }
    }
}


int main(void) 
{   
    ADC0_SetWindowChannel(0);
    SYSTEM_Initialize();
    ADC0_EnableAutoTrigger();
    
    CTR_0_SetDigitalInput();
    CTR_1_SetDigitalInput();
    CTR_2_SetDigitalInput();
    CTR_3_SetDigitalInput();

    while(1)
    {       
        for (int i = 0; i < NUM_PINS; i++) {
            for (int j = 0; j < NUM_PINS; j++) {
                characterize(i, j);
    }
}

        printArray();
    } 
} 
