#ifndef MIDI_H
#define MIDI_H

#include <cstdint>

class Midi {
  public:
    void sendControlChange(uint8_t control, uint8_t value);
};

#endif // MIDI_H