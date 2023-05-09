// #include "Accelerometer.h"

// // Define a function to read a 16-bit value from two consecutive registers
// int16_t read16(uint8_t addr) {
//     Wire.beginTransmission(MMA8451Q_ADDR);
//     Wire.write(addr);
//     Wire.endTransmission(false);
//     Wire.requestFrom(MMA8451Q_ADDR, 2);
//     while (Wire.available() < 2);
//     uint8_t lsb = Wire.read();
//     uint8_t msb = Wire.read();
//     return (int16_t)((msb << 8) | lsb);
// }

// void setup_accelerometer() {
//     // Start the serial communication
//     Serial.begin(9600);

//     // Set the MMA8451Q to active mode
//     Wire.beginTransmission(MMA8451Q_ADDR);
//     Wire.write(MMA8451Q_CTRL_REG1);
//     Wire.write(0x01);
//     Wire.endTransmission();
// }

// void loop_accelerometer() {
//     // Read the X, Y, and Z values from the MMA8451Q accelerometer
//     int16_t x = read16(MMA8451Q_OUT_X_MSB);
//     int16_t y = read16(MMA8451Q_OUT_Y_MSB);
//     int16_t z = read16(MMA8451Q_OUT_Z_MSB);

//     // Print the X, Y, and Z values on the serial monitor
//     Serial.print("X: ");
//     Serial.print(x);
//     Serial.print(", Y: ");
//     Serial.print(y);
//     Serial.print(", Z: ");
//     Serial.println(z);

//     // Wait for 100 milliseconds
//     delay(100);
// }
