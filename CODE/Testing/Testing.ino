#include "Arduino.h"

// #define TEST_BUZZER 
#define TEST_TEMP

#ifdef TEST_BUZZER
#include "Buzzer.h"
#elif defined(TEST_TEMP)
#include "Temp.h"
#endif

void setup() {
#ifdef TEST_BUZZER
  setup_buzzer();
#elif defined(TEST_TEMP)
  setup_temp();
#endif
}

void loop() {
#ifdef TEST_BUZZER
  loop_buzzer();
#elif defined(TEST_TEMP)
  loop_temp();
#endif
}