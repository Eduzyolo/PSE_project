#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>

// Initialize the GPS object
SFE_UBLOX_GNSS myGPS;

void setup_gps() {
    // Start the serial communication
    Serial.begin(SERIAL_BAUD_RATE);

    // Start the I2C bus
    Wire.begin();

    // Initialize the GPS
    if (myGPS.begin() == false) {
        Serial.println("GPS not detected. Check wiring.");
        while (1);
    }

    // Set the update rate to 1 second
    myGPS.setNavigationFrequency(1000);
}

void loop_gps() {
    // Update the GPS data
    if (myGPS.checkUblox() == true) {
        // Get the latitude, longitude, and altitude
        float latitude = myGPS.getLatitude();
        float longitude = myGPS.getLongitude();
        float altitude = myGPS.getAltitude();

        // Get the speed
        float speed = myGPS.getGroundSpeed();

        // Get the number of satellites
        uint8_t numSatellites = myGPS.getSIV();

        // Print the GPS data on the serial monitor
        Serial.print("Latitude: ");
        Serial.println(latitude, 6);
        Serial.print("Longitude: ");
        Serial.println(longitude, 6);
        Serial.print("Altitude: ");
        Serial.println(altitude, 2);
        Serial.print("Speed: ");
        Serial.println(speed, 2);
        Serial.print("Number of satellites: ");
        Serial.println(numSatellites);
    }
}
