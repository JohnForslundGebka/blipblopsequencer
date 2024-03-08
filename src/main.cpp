#include <Arduino.h>
#include "pitches.h"
#include "Sequencer.h"
#include "HardwareComponents.h"

bool isPlaying = false;

#define SHIFT_SHORT_PRESS 30

HardwareComponents components;
Sequencer seq(components);


void setup() {

 Serial.begin(9600);
}

void loop() {

    // Correct syntax to access and use the members
    components.button1.update();
    components.buttonLadder.read();
    uint8_t button;
    int reading = components.stateMachine.handleButtonPress();

    Serial.println(reading);

    if(SHIFT_SHORT_PRESS == reading) {
        isPlaying = !isPlaying;
    }

    if(reading > 0 && reading < 9) {
        tone(13, seq.m_scale[reading - 1], 100);
    }

    if (isPlaying) {
        seq.play();
    }

  //  seq.rec();
}