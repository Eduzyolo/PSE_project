#ifdef TEST

#include <Arduino.h>
#include "Constants.h"

// #define TEST_BUZZER 
// #define TEST_TEMP
// #define TEST_ACC
// #define TEST_OLED
// #define TEST_GPS
// #define TEST_LED
// #define TEST_EEPROM
// #define TEST_ENCODER
// #define TEST_BTNS

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
#include "Eeprom_board.h"
#elif defined(TEST_ENCODER)
#include "Encoder.h"
#elif defined(TEST_BTNS)
#include "Buttons.h"
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
#elif defined(TEST_ENCODER)
  setup_encoder();
#elif defined(TEST_BTNS)
  setup_btns();
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
#elif defined(TEST_ENCODER)
  loop_encoder();
#elif defined(TEST_BTNS)
  loop_btns();
#endif
}

#endif