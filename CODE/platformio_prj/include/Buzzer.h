#include <Arduino.h>

// Define the pin connected to the buzzer
const int BUZZER_PIN = 18;

// Define the frequency of each note
const int tone_G4 = 391;
const int tone_E4 = 329;
const int tone_C5 = 523;
const int tone_D5 = 587;
const int tone_E5 = 659;

// Define the duration of each note
const int QUARTER_NOTE = 500;

// Define the melody as an array of notes
const int melody[] = {
    tone_G4, tone_E4, tone_C5, tone_D5,
    tone_E5, tone_G4, tone_E4, tone_C5,
    tone_D5, tone_E5, tone_G4, tone_E4,
    tone_C5, tone_D5, tone_E5, 0 // the 0 denotes a pause in the melody
};

// void setup_buzzer();
// void loop_buzzer();

void setup_buzzer() {
    // Initialize the buzzer pin as an output
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop_buzzer() {
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