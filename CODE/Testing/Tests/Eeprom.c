#include "Eeprom.h"

void setup_eeprom() {
    // Start the serial communication
    Serial.begin(9600);

    // Start the I2C bus
    Wire.begin();
}

void loop_eeprom() {
    // Write "Hello" to the EEPROM
    EEPROM.begin(32); // Initialize the EEPROM with a size of 32 bytes
    EEPROM.write(0, 'H');
    EEPROM.write(1, 'e');
    EEPROM.write(2, 'l');
    EEPROM.write(3, 'l');
    EEPROM.write(4, 'o');
    EEPROM.end(); // Commit the changes to the EEPROM

    // Wait for 1 second
    delay(1000);

    // Write "World" to the EEPROM
    EEPROM.begin(32); // Initialize the EEPROM with a size of 32 bytes
    EEPROM.write(5, 'W');
    EEPROM.write(6, 'o');
    EEPROM.write(7, 'r');
    EEPROM.write(8, 'l');
    EEPROM.write(9, 'd');
    EEPROM.end(); // Commit the changes to the EEPROM

    // Wait for 1 second
    delay(1000);

    // Read the values from the EEPROM
    EEPROM.begin(32); // Initialize the EEPROM with a size of 32 bytes
    char hello[6];
    char world[6];
    for (int i = 0; i < 5; i++) {
        hello[i] = EEPROM.read(i);
        world[i] = EEPROM.read(i + 5);
    }
    hello[5] = '\0';
    world[5] = '\0';
    EEPROM.end(); // Release the EEPROM

    // Print the values on the serial monitor
    Serial.print("Hello: ");
    Serial.println(hello);
    Serial.print("World: ");
    Serial.println(world);
}
