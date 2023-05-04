#include "Arduino.h"

// #define TEST_BUZZER 
// #define TEST_TEMP
// #define TEST_ACC
// #define TEST_OLED
#define TEST_GPS

#ifdef TEST_BUZZER
#include "Buzzer.h"
#elif defined(TEST_TEMP)
#include "Temp.h"
#elif defined(TEST_ACC)
#include "Accelerometer.h"
#elif defined(TEST_OLED)
#include "Oled.h"
#elif defined(TEST_GPS)
#include "GPS.h"
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
#elif defined(TEST_GPS)
  setup_gps();
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
#elif defined(TEST_GPS)
  loop_gps();
#endif
}