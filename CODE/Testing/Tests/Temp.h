// Include required libraries
#include <Wire.h>

// Define the I2C address of the temperature sensor
#define SENSOR_ADDRESS 0x48

// Define constants for temperature conversion
const float VREF = 3.3;    // reference voltage of Pico
const float ADC_RES = VREF / 65535.0;   // ADC resolution of Pico
const float TC_SCALE = 100.0;   // Temperature scale factor

void setup_temp();
void loop_temp();