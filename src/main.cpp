#include <Arduino.h>
#include "pitches.h"
#include "Sequencer.h"
#include "HardwareComponents.h"

//flag for playing or pausing the sequence
bool isPlaying = false;

#define SHIFT_SHORT_PRESS 30
#define RECORDING_MODE 9
#define DELETE_MODE 10
#define SCALE_MODE 15

//struct that contains instances of classes that will be used
HardwareComponents components;

Sequencer seq(components);

void setup() {
}

void loop() 
{
    //functions that reads the current status of the buttons
    components.button1.update();
    components.buttonLadder.read();
    //reading will contain the value of the button that is pressed
    int reading = components.stateMachine.handleButtonPress();

    uint8_t button;

    //start/stop the sequence
    if(reading==SHIFT_SHORT_PRESS) {
        isPlaying = !isPlaying;
        components.leds.ledOn(13);
        seq.resetStepCounter();
    }

    //play a tone when pressing a button in the buttonLadder
    if(reading > 0 && reading < 9) {
        tone(13, seq.m_scales[seq.m_currentScale][reading - 1], 100);
    }

    //start playing the bool argument determinates of the leds
    if (isPlaying) {
        seq.play(true);
    }

    if (reading==RECORDING_MODE){   
        components.buttonLadder.read();
        seq.rec();
    }

    if (reading==SCALE_MODE)
        seq.scaleMode(isPlaying);

    if (reading == DELETE_MODE)
        seq.deleteMode();
}