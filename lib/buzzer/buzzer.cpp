#include <Arduino.h>

#include "buzzer.h"

#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494

// Define the duration of each note (in milliseconds)
#define DURATION_QUARTER 250
#define DURATION_HALF 500

// Define the melody
int melody[] = {
    NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4};

// Define the note durations
int noteDurations[] = {
    DURATION_QUARTER, DURATION_QUARTER, DURATION_QUARTER, DURATION_QUARTER,
    DURATION_QUARTER, DURATION_QUARTER, DURATION_HALF};

void melody1 (int BUZZER_PIN)
{
    // Iterate over the notes of the melody
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++)
    {
        int noteDuration = noteDurations[i];
        tone(BUZZER_PIN, melody[i], noteDuration);
        delay(noteDuration * 1.1); 
    }
    noTone(BUZZER_PIN);
}
