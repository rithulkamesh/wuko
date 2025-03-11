#include "buttons.h"
#include "midi.h"

Buttons::Buttons(const uint8_t *buttonPins, uint8_t numButtons, uint8_t layerButtonIndex) {
    _buttonPins = buttonPins;
    _numButtons = numButtons;
    _layerButtonIndex = layerButtonIndex;
    _currentLayer = false; // Start on layer A
    _debounceDelay = BUTTON_DEBOUNCE_DELAY;

    // Allocate memory for button states
    _buttonStates = new uint8_t[numButtons];
    _buttonDebounceState = new uint8_t[numButtons];
    _lastDebounceTime = new unsigned long[numButtons];

    // Initialize all state arrays
    for (uint8_t i = 0; i < _numButtons; i++) {
        _buttonStates[i] = BUTTON_IDLE;
        _buttonDebounceState[i] = HIGH; // Assuming pull-up resistors
        _lastDebounceTime[i] = 0;
    }
}

Buttons::~Buttons() {
    delete[] _buttonStates;
    delete[] _buttonDebounceState;
    delete[] _lastDebounceTime;
}

void Buttons::init() {
    // Initialize button pins as inputs with pullup
    for (uint8_t i = 0; i < _numButtons; i++) {
        pinMode(_buttonPins[i], INPUT_PULLUP);
    }
}

void Buttons::update() {
    for (uint8_t i = 0; i < _numButtons; i++) {
        // Read the current button state
        uint8_t reading = digitalRead(_buttonPins[i]);

        // Check if the button state has changed
        if (reading != _buttonDebounceState[i]) {
            // Reset debounce timer
            _lastDebounceTime[i] = millis();
        }

        // Check if the button state has been stable long enough
        if ((millis() - _lastDebounceTime[i]) > _debounceDelay) {
            // If the button state has changed
            if (reading != _buttonDebounceState[i]) {
                _buttonDebounceState[i] = reading;

                // Update button state based on the stable reading
                if (_buttonDebounceState[i] == LOW) { // Button pressed (LOW with pull-up)
                    // Special handling for layer button
                    if (i == _layerButtonIndex) {
                        _currentLayer = !_currentLayer;
                        // Send layer change MIDI message
                        Midi.sendLayerChange(_currentLayer);
                    } else {
                        // Send program change for non-layer buttons when pressed
                        sendProgramChange(i);
                    }
                    _buttonStates[i] = BUTTON_PRESSED;
                } else {
                    _buttonStates[i] = BUTTON_RELEASED;
                }
            } else {
                // If button is still pressed after debouncing
                if (_buttonDebounceState[i] == LOW && _buttonStates[i] == BUTTON_PRESSED) {
                    _buttonStates[i] = BUTTON_HELD;
                } else if (_buttonStates[i] == BUTTON_RELEASED) {
                    _buttonStates[i] = BUTTON_IDLE;
                }
            }
        }
    }
}

bool Buttons::isPressed(uint8_t buttonIndex) {
    if (buttonIndex < _numButtons) {
        return _buttonStates[buttonIndex] == BUTTON_PRESSED;
    }
    return false;
}

bool Buttons::isReleased(uint8_t buttonIndex) {
    if (buttonIndex < _numButtons) {
        return _buttonStates[buttonIndex] == BUTTON_RELEASED;
    }
    return false;
}

bool Buttons::isHeld(uint8_t buttonIndex) {
    if (buttonIndex < _numButtons) {
        return _buttonStates[buttonIndex] == BUTTON_HELD;
    }
    return false;
}

bool Buttons::getCurrentLayer() {
    return _currentLayer;
}

uint8_t Buttons::getActivePatches() {
    // Count buttons that are currently pressed or held, excluding the layer button
    uint8_t count = 0;
    for (uint8_t i = 0; i < _numButtons; i++) {
        if (i != _layerButtonIndex &&
            (_buttonStates[i] == BUTTON_PRESSED || _buttonStates[i] == BUTTON_HELD)) {
            count++;
        }
    }
    return count;
}

void Buttons::sendProgramChange(uint8_t buttonIndex) {
    if (buttonIndex < _numButtons && buttonIndex != _layerButtonIndex) {
        // Calculate program change value based on button index and current layer
        // For 4 patch buttons (0-3), Layer A gives programs 0-3, Layer B gives programs 4-7
        uint8_t programValue;

        // Calculate the program number based on button index and current layer
        // Assuming button indices 0 to (numButtons-2) excluding layer button
        if (_currentLayer) {
            // Layer B: Programs start after the Layer A programs
            programValue = buttonIndex + (_numButtons - 1);
        } else {
            // Layer A: Programs start at 0
            programValue = buttonIndex;
        }

        // Send MIDI program change using our MIDI controller
        Midi.sendProgramChange(programValue);
    }
}