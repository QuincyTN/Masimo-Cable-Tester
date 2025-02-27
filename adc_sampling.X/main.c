//TO DO 
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
    // Wait for the previous ADC conversion to complete
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
    // Clear the result ready flag
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    // Start ADC conversion
    ADC0_StartConversion(current_channel);
    // Wait for the conversion to complete
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));
    // Get the conversion result and store it temporarily
    uint16_t result = ADC0_GetConversionResult();
    uint16_t average_result = (uint16_t)(result >> TRUNCATED_SHIFT);
    // Calculate the voltage
    float voltage = (float)(average_result * MAX_VOLTAGE) / ADC_RESOLUTION;
    // Clear all stored ADC-related data for this channel
    adc_data[current_channel].result = 0;
    adc_data[current_channel].average_result = 0;
    
    return voltage;
}

void characterize(int pin1, int pin2) {
    float test_a;
    float test_b;
    float resistance;
    int connection_type;
    int confirm;
    if (pin1 != pin2) {
        setOutput(pin1);
        setOutput(pin2);
        printf("Check for pair %d, %d\n\n", pin1, pin2);
        // Test 1: i High, j Low
        setHigh(pin1);
        setLow(pin2);
        test_a = process_adc_conversion(pin1);
        test_b = process_adc_conversion(pin2);
        printf("A High, B Low\nPin %d Voltage:  %.3f\nPin %d Voltage:  %.3f\n", pin1, test_a, pin2, test_b);
        if (test_a > (MAX_VOLTAGE - 0.1) && test_b < 0.10) {
            connection_type = 0;
        } 
        else if ((test_b > ((MAX_VOLTAGE / 2) - 0.1) && test_a < ((MAX_VOLTAGE / 2) + 0.1)) && (test_a > ((MAX_VOLTAGE / 2) - 0.1) && test_a < ((MAX_VOLTAGE / 2) + 0.1))) {
            // short test
            connection_type = 1;
        } 
        else if (test_a < 0.10 && test_b < 0.10) {
            // diode test
            connection_type = 2;
        }
        else {
            connection_type = 3;
        }
        // Test 2: i Low, j High
        setLow(pin1);
        setHigh(pin2);
        test_a = process_adc_conversion(pin1);
        test_b = process_adc_conversion(pin2);
        printf("A Low, B High\nPin %d Voltage:  %.3f\nPin %d Voltage:  %.3f\n\n", pin1, test_a, pin2, test_b);
        if (test_b > (MAX_VOLTAGE - 0.1) && test_a < 0.10) {
            confirm = 0;
        } 
        else if ((test_b > ((MAX_VOLTAGE / 2) - 0.1) && test_b < ((MAX_VOLTAGE / 2) + 0.1)) && (test_a > ((MAX_VOLTAGE / 2) - 0.1) && test_a < ((MAX_VOLTAGE / 2) + 0.1))) {
            // short test 
            confirm = 1;
        } 
        else if (test_a > (MAX_VOLTAGE - 0.1) && test_b > (MAX_VOLTAGE - 0.1)) {
            // diode test
            confirm = 2;
        }
        else {
            confirm = 3;
            resistance = (3.3/test_a) - 2;
            
        }
        if (confirm == connection_type) {
            
        switch (confirm) {
            case 0:
                printf("Connection Type for pair %d %d: Open Circuit\n\n", pin1, pin2);
                break;
            case 1:
                printf("Connection Type for pair %d %d: Short\n\n", pin1, pin2);
                break;
            case 2:
                printf("Connection Type for pair %d %d: Diode\n\n", pin1, pin2);
                break;
            case 3:
                printf("Connection Type for pair %d %d: Resistor: %.2fk\n\n", pin1, pin2, resistance);
                break;

}
        }
        else {
            printf("Error");
        }
        setInput(pin1);
        setInput(pin2);
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
    int i;
    int j;
    while(1)
    {       
    for (i = 0; i < NUM_PINS; i++) {
        for (j = 0; j < NUM_PINS; j++) {                  
            characterize(i, j);        
        }    
    }
    printf("Full Test Complete!!!!!!!!!!!\n\n");
    }
}