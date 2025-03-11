#include "midi.h"
#include "config.h"

// Create global MIDI interface with Serial2 on ESP32
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI_SERIAL);

// Global instance
MidiController Midi;

MidiController::MidiController() {
    _midi = &MIDI_SERIAL;
    _channel = MIDI_CHANNEL;
    _lastProgram = 0;

    // Initialize the last CC values array (for 128 possible CC numbers)
    _lastCCValues = new uint8_t[128];
    for (int i = 0; i < 128; i++) {
        _lastCCValues[i] = 255; // Initialize with invalid value to ensure first send
    }
}

MidiController::~MidiController() {
    delete[] _lastCCValues;
}

void MidiController::begin(uint8_t channel) {
    _channel = channel;
    _midi->begin(channel);

    // Optional: enable MIDI thru
    _midi->turnThruOff();

    // For ESP32, configure Serial2 pins if needed
    Serial2.begin(31250, SERIAL_8N1, 16, 17); // RX, TX pins
}

void MidiController::sendNoteOn(uint8_t note, uint8_t velocity) {
    _midi->sendNoteOn(note, velocity, _channel);
}

void MidiController::sendNoteOff(uint8_t note) {
    _midi->sendNoteOff(note, 0, _channel);
}

void MidiController::sendProgramChange(uint8_t program) {
    if (program != _lastProgram) {
        _midi->sendProgramChange(program, _channel);
        _lastProgram = program;
    }
}

void MidiController::sendControlChange(uint8_t controller, uint8_t value) {
    // Only send if the value has changed to reduce MIDI traffic
    if (_lastCCValues[controller] != value) {
        _midi->sendControlChange(controller, value, _channel);
        _lastCCValues[controller] = value;
    }
}

uint8_t MidiController::mapToMidi(int value, int minValue, int maxValue) {
    return map(constrain(value, minValue, maxValue), minValue, maxValue, 0, 127);
}

void MidiController::sendLayerChange(bool layer) {
    // Using CC 120 (undefined in standard MIDI) to indicate layer change
    // Layer A = 0, Layer B = 127
    _midi->sendControlChange(120, layer ? 127 : 0, _channel);
}

uint8_t MidiController::getChannel() {
    return _channel;
}