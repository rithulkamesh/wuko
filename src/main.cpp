#include "config.h"
#include "midi.h"
#include <Adafruit_SH110X.h>
#include <Arduino.h>
#include <Wire.h>

void setup() {
    Midi.begin(1);
    Serial.begin(115200);
}

void loop() {
    delay(100);
}