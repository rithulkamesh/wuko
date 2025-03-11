#ifndef BUTTONS_H
#define BUTTONS_H

#include "config.h"
#include <Arduino.h>

// Button states
#define BUTTON_IDLE 0
#define BUTTON_PRESSED 1
#define BUTTON_RELEASED 2
#define BUTTON_HELD 3

class Buttons {
  private:
    // Button pins from config.h
    const uint8_t *_buttonPins;
    uint8_t _numButtons;

    // Internal state tracking
    uint8_t *_buttonStates;
    uint8_t *_buttonDebounceState;
    unsigned long *_lastDebounceTime;
    bool _currentLayer; // false = layer A, true = layer B
    uint8_t _layerButtonIndex;

    // Debounce management
    unsigned long _debounceDelay;

  public:
    Buttons(const uint8_t *buttonPins, uint8_t numButtons, uint8_t layerButtonIndex);
    ~Buttons();

    void init();
    void update();

    // Button state getters
    bool isPressed(uint8_t buttonIndex);
    bool isReleased(uint8_t buttonIndex);
    bool isHeld(uint8_t buttonIndex);

    // Layer management
    bool getCurrentLayer();
    uint8_t getActivePatches();

    // MIDI functionality
    void sendProgramChange(uint8_t buttonIndex);
};

#endif // BUTTONS_H