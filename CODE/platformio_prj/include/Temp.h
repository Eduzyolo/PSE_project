#include <Wire.h>

// Define the I2C address of the temperature sensor
#define SENSOR_ADDRESS 0x48

// Define constants for temperature conversion
const float VREF = 3.3;    // reference voltage of Pico
const float ADC_RES = VREF / 65535.0;   // ADC resolution of Pico
const float TC_SCALE = 100.0;   // Temperature scale factor

void setup_temp();
void loop_temp();


void setup_temp() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize I2C communication
  Wire.begin();
}

void loop_temp() {
  // Read the analog voltage from the temperature sensor
  Wire.beginTransmission(SENSOR_ADDRESS);
  Wire.write(0x00);  // Select temperature register
  Wire.endTransmission();
  Wire.requestFrom(SENSOR_ADDRESS, 2);
  uint16_t adc_value = Wire.read() << 8 | Wire.read();
  
  // Convert the analog voltage to temperature in Celsius
  float voltage = adc_value * ADC_RES;
  float temperature_c = (voltage - 0.5) * TC_SCALE;
  
  // Convert the temperature to Kelvin and Fahrenheit
  float temperature_k = temperature_c + 273.15;
  float temperature_f = temperature_c * 9.0 / 5.0 + 32.0;
  
  // Print the temperatures on the serial monitor
  Serial.print("Temperature in Celsius: ");
  Serial.println(temperature_c);
  Serial.print("Temperature in Kelvin: ");
  Serial.println(temperature_k);
  Serial.print("Temperature in Fahrenheit: ");
  Serial.println(temperature_f);
  
  // Wait for 1 second before taking the next reading
  delay(1000);
}
