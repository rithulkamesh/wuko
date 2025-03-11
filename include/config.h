#ifndef CONFIG_H
#define CONFIG_H

// MIDI configuration
#define MIDI_CHANNEL 0
#define MOD_WHEEL_CC 1
#define EXPRESSION_CC 11

// Button configuration
#define NUM_BUTTONS 5
#define BUTTON_DEBOUNCE_DELAY 50
#define LAYER_BUTTON_INDEX 4 // The index of the layer toggle button

// Button pin definitions
const uint8_t BUTTON_PINS[NUM_BUTTONS] = {12, 14, 27, 26, 25}; // Adjust these to your actual pins

// Display configuration
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define DISPLAY_ADDRESS 0x3C

// Potentiometer pin configuration
#define MOD_WHEEL_PIN 32
#define EXPRESSION_PIN 33

#endif // CONFIG_H