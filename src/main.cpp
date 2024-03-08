#include <Arduino.h>
#include "pitches.h"
#include "ButtonStateMachine.h"
#include "buttonLadder.h"
#include "Button.h"
#include "LedRow.h"
#include "Sequencer.h"

int stepCount = 1;

ButtonLadder buttonLadder(0);
Button button1(2);
LedRow leds; //This class uses the digital pins 4,7,8,12
Sequencer seq;
ButtonStateMachine stateMachine;
bool isPlaying = false;

#define SHIFT_SHORT_PRESS 30


void setup() {

 Serial.begin(9600);
}

void loop() {

    button1.update();
    buttonLadder.read();
    uint8_t button;
    int reading = stateMachine.handleButtonPress();

    if(SHIFT_SHORT_PRESS==reading)
    {
        isPlaying = !isPlaying;
    }

    if(reading > 0 && reading < 9)
    {
        tone(13,seq.m_scale[reading-1],100);
    }


    if (isPlaying)
    {
        seq.play(leds);
    }

}