#include <Wire.h>
#include "hardware/i2c.h"

i2c_inst_t* i2c = i2c0;

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
TwoWire I2C(i2c, I2C_SDA, I2C_SCL);

int16_t read16(uint8_t addr);
void setup_accelerometer();
void loop_accelerometer();