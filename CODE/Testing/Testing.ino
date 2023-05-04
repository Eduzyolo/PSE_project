
#define TEST_BUZZER 

#ifdef TEST_BUZZER
#include "Buzzer.h"
#endif

void setup() {
#ifdef TEST_BUZZER
  setup_buzzer();
#endif
}

void loop() {
#ifdef TEST_BUZZER
  loop_buzzer();
#endif
}