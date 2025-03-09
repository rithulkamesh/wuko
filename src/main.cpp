#include "buttons.h"
#include "midi.h"
#include "potentiometer.h"
#include <Adafruit_SH110X.h>
#include <Arduino.h>
#include <Wire.h>

#define MIDI_CHANNEL 1
#define MOD_WHEEL_CC 1

#define POTENTIOMETER_PIN A0
#define POTENTIOMETER_MAX_VALUE 1023
#define POTENTIOMETER_MIN_VALUE 0

#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3

Buttons buttons(BUTTON_PIN_1, BUTTON_PIN_2);
Potentiometer potentiometer(POTENTIOMETER_PIN);
Midi midi;

void setup() {
    Serial.begin(115200);
    buttons.init();
    potentiometer.init();
}

void loop() {
    buttons.checkButtons();
    int potValue = potentiometer.readValue();
    midi.sendControlChange(1, potValue);
    delay(100);
}