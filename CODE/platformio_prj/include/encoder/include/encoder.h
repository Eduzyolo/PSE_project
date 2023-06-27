#ifndef MAGNETIC_ENCODER_H
#define MAGNETIC_ENCODER_H

#include <Wire.h>
#include <AS5600.h>
#include <Constants.h>

// Macros for setup values
#define DIAMETER 10.0

// Macro to calculate the distance
#define CALCULATE_DISTANCE(degree) \
  ((degree/365) * (PI * DIAMETER))

void detect_magnet(AMS_5600* ams5600);
void read_distance(AMS_5600* ams5600);
float convertRawAngleToDegrees(word newAngle);

void detect_magnet(AMS_5600* ams5600){
    if(ams5600->detectMagnet() == 0 ){
    while(1){
        if(ams5600->detectMagnet() == 1 ){
            #ifdef SERIAL_DEBUG
            Serial.print("Current Magnitude: ");
            Serial.println(ams5600->getMagnitude());
            #endif
            break;
        }
        else{
            #ifdef SERIAL_DEBUG
            Serial.println("Can not detect magnet");
            #endif
        }
        delay(1000);
    }
  }
}
  
void read_distance(AMS_5600* ams5600){
    int degreeCounter = 0;
    float distance = 0;
    while(exit_mode()){
        degreeCounter += convertRawAngleToDegrees(ams5600->getRawAngle());
        distance = CALCULATE_DISTANCE(degreeCounter);
        #ifdef SERIAL_DEBUG
        Serial.print("Distance in CM: ");
        Serial.println(distance);
        #endif
    }
}

float convertRawAngleToDegrees(word newAngle)
{
  /* Raw data reports 0 - 4095 segments, which is 0.087890625 of a degree */
  float retVal = newAngle * 0.087890625;
  return retVal;
}

#endif // MAGNETIC_ENCODER_H

