#include <Arduino.h>

// #define TEST_BUZZER 
// #define TEST_TEMP
// #define TEST_ACC
// #define TEST_OLED
// #define TEST_GPS
// #define TEST_LED
// #define TEST_EEPROM

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
#elif defined(TEST_LED)
#include "Led.h"
#elif defined(TEST_EEPROM)
#include "Eeprom.h"
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
#elif defined(TEST_LED)
  setup_led();
#elif defined(TEST_EEPROM)
  setup_eeprom();
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
#elif defined(TEST_LED)
  loop_led();
#elif defined(TEST_EEPROM)
  loop_eeprom();
#endif
}