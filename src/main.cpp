#include <Arduino.h>
#include "pitches.h"
#include "ButtonStateMachine.h"
#include "buttonLadder.h"
#include "Button.h"
#include "LedRow.h"
#include "Sequencer.h"


Sequencer seq;
bool isPlaying = false;

#define SHIFT_SHORT_PRESS 30

struct HardwareComponents {
    ButtonLadder buttonLadder;
    Button button1;
    LedRow leds; // Uses digital pins 4,7,8,12
    ButtonStateMachine stateMachine;

    // Constructor to initialize members
    HardwareComponents() : buttonLadder(0), button1(2) {}
};


void setup() {

 Serial.begin(9600);
}

void loop() {
    HardwareComponents components;

    // Correct syntax to access and use the members
    components.button1.update();
    components.buttonLadder.read();
    uint8_t button;
    int reading = components.stateMachine.handleButtonPress();

    if(SHIFT_SHORT_PRESS == reading) {
        isPlaying = !isPlaying;
    }

    if(reading > 0 && reading < 9) {
        tone(13, seq.m_scale[reading - 1], 100);
    }

    if (isPlaying) {
        seq.play(components.leds);
    }
}