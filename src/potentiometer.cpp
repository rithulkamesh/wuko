#include "potentiometer.h"
#include <Arduino.h>
#include <MIDI.h>

Potentiometer::Potentiometer(int pin) : pin(pin) {
}

void Potentiometer::init() {
    pinMode(pin, INPUT);
}

int Potentiometer::readValue() {
    int value = analogRead(pin);
    // Map the potentiometer value to MIDI Control Change range (0-127)
    return map(value, 0, 1023, 0, 127);
}

void Potentiometer::sendControlChange(Midi &midi) {
    int ccValue = readValue();
    midi.sendControlChange(1, ccValue); // Send CC on channel 1 for mod wheel
}