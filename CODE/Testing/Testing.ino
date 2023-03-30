
// #define MAIN_FLOW
#define TEST_BUZZER

#ifdef TEST_BUZZER
#include <Arduino.h>
#include "Buzzer.h"
#endif

#ifdef MAIN_FLOW
void setup() {}
void loop() {}
#endif
