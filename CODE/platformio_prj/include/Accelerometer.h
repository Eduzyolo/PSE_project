
#include <Arduino.h>
#include <Wire.h>

// Define the I2C address of the MMA8451Q accelerometer
#define MMA8451Q_ADDR   0x1D

// Define the addresses of the MMA8451Q registers
#define MMA8451Q_CTRL_REG1      0x2A
#define MMA8451Q_OUT_X_MSB      0x01
#define MMA8451Q_OUT_Y_MSB      0x03
#define MMA8451Q_OUT_Z_MSB      0x05

// Initialize the I2C bus
#define I2C_SDA 0
#define I2C_SCL 1

int16_t read16(uint8_t addr);
void setup_accelerometer();
void loop_accelerometer();


// Define a function to read a 16-bit value from two consecutive registers
int16_t read16(uint8_t addr) {
    Wire.beginTransmission(MMA8451Q_ADDR);
    Wire.write(addr);
    Wire.endTransmission(false);
    Wire.requestFrom(MMA8451Q_ADDR, 2);
    while (Wire.available() < 2);
    uint8_t lsb = Wire.read();
    uint8_t msb = Wire.read();
    return (int16_t)((msb << 8) | lsb);
}

void setup_accelerometer() {
    // Start the serial communication
    Serial.begin(9600);

    // Set the MMA8451Q to active mode
    Wire.beginTransmission(MMA8451Q_ADDR);
    Wire.write(MMA8451Q_CTRL_REG1);
    Wire.write(0x01);
    Wire.endTransmission();
}

void loop_accelerometer() {
    // Read the X, Y, and Z values from the MMA8451Q accelerometer
    int16_t x = read16(MMA8451Q_OUT_X_MSB);
    int16_t y = read16(MMA8451Q_OUT_Y_MSB);
    int16_t z = read16(MMA8451Q_OUT_Z_MSB);

    // Print the X, Y, and Z values on the serial monitor
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(", Y: ");
    Serial.print(y);
    Serial.print(", Z: ");
    Serial.println(z);

    // Wait for 100 milliseconds
    delay(100);
}