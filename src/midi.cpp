#include "midi.h"
#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void Midi::sendControlChange(uint8_t control, uint8_t value) {
    MIDI.sendControlChange(control, value, 1); // Send CC on channel 1
}