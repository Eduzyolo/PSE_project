#include "Arduino.h"

// #define TEST_BUZZER 
// #define TEST_TEMP
#define TEST_ACC

#ifdef TEST_BUZZER
#include "Buzzer.h"
#elif defined(TEST_TEMP)
#include "Temp.h"
#elif defined(TEST_ACC)
#include "Accelerometer.h"
#endif

void setup() {
#ifdef TEST_BUZZER
  setup_buzzer();
#elif defined(TEST_TEMP)
  setup_temp();
#elif defined(TEST_ACC)
  setup_accelerometer();
#endif
}

void loop() {
#ifdef TEST_BUZZER
  loop_buzzer();
#elif defined(TEST_TEMP)
  loop_temp();
#elif defined(TEST_ACC)
  loop_accelerometer();
#endif
}