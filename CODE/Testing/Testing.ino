#include "Arduino.h"

// #define TEST_BUZZER 
// #define TEST_TEMP
// #define TEST_ACC
#define TEST_OLED

#ifdef TEST_BUZZER
#include "Buzzer.h"
#elif defined(TEST_TEMP)
#include "Temp.h"
#elif defined(TEST_ACC)
#include "Accelerometer.h"
#elif defined(TEST_OLED)
#include "Oled.h"
#endif

void setup() {
#ifdef TEST_BUZZER
  setup_buzzer();
#elif defined(TEST_TEMP)
  setup_temp();
#elif defined(TEST_ACC)
  setup_accelerometer();
#elif defined(TEST_OLED)
  setup_oled();
#endif
}

void loop() {
#ifdef TEST_BUZZER
  loop_buzzer();
#elif defined(TEST_TEMP)
  loop_temp();
#elif defined(TEST_ACC)
  loop_accelerometer();
#elif defined(TEST_OLED)
  loop_oled();
#endif
}