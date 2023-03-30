#ifdef TEST_BUZZER

#include "Buzzer.h"

void setup() {
    // Initialize the buzzer pin as an output
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    // Play the melody
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        if (melody[i] == 0) {
            // Pause for the duration of a quarter note
            delay(QUARTER_NOTE);
        } else {
            // Play the note for the duration of a quarter note
            tone(BUZZER_PIN, melody[i], QUARTER_NOTE);
            delay(QUARTER_NOTE);
            noTone(BUZZER_PIN);
        }
    }
}
#endif