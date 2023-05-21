#include <Arduino.h>
#include <Debounce.h>

#define BUTTON_UP_Idx 0
#define BUTTON_DOWN_Idx 1
#define BUTTON_RIGHT_Idx 2
#define BUTTON_LEFT_Idx 3

Debounce ButtonUp(BUTTON_UP, 50);
Debounce ButtonDown(BUTTON_DOWN, 50);
Debounce ButtonRight(BUTTON_RIGHT, 50);
Debounce ButtonLeft(BUTTON_LEFT, 50);

void setup_btns() {
  pinMode(LED_ALIVE, OUTPUT);
  digitalWrite(LED_ALIVE, HIGH);
}

bool button_pressed(Debounce* button){
    if(button->count() == 1){
        button->resetCount();
        return true;
    }
    return false;
}

void loop_btns() {
    if(button_pressed(&ButtonDown)){
        digitalWrite(LED_ALIVE, HIGH);
    }
    else if (button_pressed(&ButtonUp)){
        digitalWrite(LED_ALIVE, HIGH);
    }
    else if (button_pressed(&ButtonRight)){
        digitalWrite(LED_ALIVE, LOW);
    }
    else if (button_pressed(&ButtonLeft)){
        digitalWrite(LED_ALIVE, LOW);
    }
    delay(10);
}