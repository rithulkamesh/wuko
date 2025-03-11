#ifndef MIDI_H
#define MIDI_H

#include <Arduino.h>
#include <MIDI.h>

// Use the existing MIDI namespace from the library
using namespace midi;

class MidiController {
  private:
    MidiInterface<SerialMIDI<HardwareSerial, DefaultSerialSettings>, DefaultSettings, DefaultPlatform> *_midi;
    uint8_t _channel;

    // Store last sent values to optimize transmission
    uint8_t *_lastCCValues;
    uint8_t _lastProgram;

  public:
    MidiController();
    ~MidiController();

    void begin(uint8_t channel = MIDI_CHANNEL);

    // Basic MIDI message functions
    void sendNoteOn(uint8_t note, uint8_t velocity);
    void sendNoteOff(uint8_t note);

    // Program change for patch selection
    void sendProgramChange(uint8_t program);

    // Control change for continuous controllers (potentiometers)
    void sendControlChange(uint8_t controller, uint8_t value);

    // Maps analog read value (0-4095 on ESP32) to MIDI range (0-127)
    uint8_t mapToMidi(int value, int minValue = 0, int maxValue = 4095);

    // Layer management - optional custom messages
    void sendLayerChange(bool layer);

    // Get current channel
    uint8_t getChannel();
};

extern MidiController Midi;

#endif // MIDI_H