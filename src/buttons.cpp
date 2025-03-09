#include "buttons.h"
#include <Arduino.h>

Buttons::Buttons(int buttonPin1, int buttonPin2) {
    buttonPin1, buttonPin2 = buttonPin1, buttonPin2;
}

void Buttons::init() {
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
}

void handleButton1Press() {
    // Action for button 1 press
}

void handleButton2Press() {
    // Action for button 2 press
}

void Buttons::checkButtons() {
    // Read button states
    int state1 = digitalRead(buttonPin1);
    int state2 = digitalRead(buttonPin2);

    // Check if button 1 is pressed
    if (state1 == LOW) {
        // Trigger action for button 1
        handleButton1Press();
    }

    // Check if button 2 is pressed
    if (state2 == LOW) {
        // Trigger action for button 2
        handleButton2Press();
    }
}
