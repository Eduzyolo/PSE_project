// #define TEST
#ifndef TEST


bool exit_mode();
#define SERIAL_DEBUG
#include <Arduino.h>
#include <encoder/include/encoder.h>

bool exit_mode(){
    // check if exit button has been pressed
    if (true)
    {
        return true;
    }
    else{
        return false;
    }
}

enum menu_state {ENCODER_READ, HOME};
typedef enum menu_state menu_state;
AMS_5600 ams5600;
menu_state current_menu = HOME;

void setup(){
    Serial.begin(115200);
    Wire.begin();
    current_menu = ENCODER_READ;
    detect_magnet(&ams5600);
}

void loop(){
    
    switch (current_menu) {
        case ENCODER_READ: {
        // Start measurement
        read_distance(&ams5600);
        break;
        }
        case HOME: {

        break;
        }
        default: {
        
        break;
        }
    }
    
    delay(100);
}

#endif