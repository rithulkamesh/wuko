#include "../src/buttons.h"
#include "../src/midi.h"
#include "../src/potentiometer.h"
#include <Arduino.h>

Buttons buttons;
Potentiometer potentiometer;
Midi midi;

void setUp() {
    buttons.init();
    potentiometer.init();
    midi.init();
}

void tearDown() {
    // Clean up code if necessary
}

void test_buttonPress() {
    // Simulate button press and check the expected behavior
    buttons.checkButtons();
    TEST_ASSERT_TRUE(buttons.isButtonPressed());
}

void test_potentiometerRead() {
    // Test reading the potentiometer value
    int value = potentiometer.readValue();
    TEST_ASSERT_GREATER_THAN(0, value);
}

void test_midiSend() {
    // Test sending a MIDI Control Change message
    midi.sendControlChange(1, 127); // Channel 1, max value
    TEST_ASSERT_TRUE(midi.isMessageSent());
}

void loop() {
    UNITY_BEGIN();
    RUN_TEST(test_buttonPress);
    RUN_TEST(test_potentiometerRead);
    RUN_TEST(test_midiSend);
    UNITY_END();
}