// #define TEST
#ifndef TEST
#include <Arduino.h>
#include <encoder.h>

enum menu_state {ENCODER_READ, HOME};
typedef enum menu_state menu_state;
volatile long encoderCurrentPosition;

void setup(){
    Serial.begin(115200);
    encoderCurrentPosition = 0;
}

void loop(){
    menu_state current_menu = HOME;

    switch (current_menu) {
        case ENCODER_READ: {
        // Start measurement
        float distance = CALCULATE_DISTANCE(encoderCurrentPosition);
        Serial.print("Distance ENC in cm: ");
        Serial.println(distance);
        break;
        }
        case HOME: {

        break;
        }
        default: {
        
        break;
        }
    }
    if(encoderCurrentPosition!=0 && current_menu!=ENCODER_READ){
        // if i'm not using the encoder and i've not already reset i'll reset the position
        encoderCurrentPosition = 0;
    }
    delay(100);
}

#endif