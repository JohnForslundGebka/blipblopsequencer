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

void setup() {

 Serial.begin(9600);
}

void loop() {

    uint8_t button;
    int reading = stateMachine.handleButtonPress();

    button1.update();
    buttonLadder.read();


    if(reading==9)
    {
        //sak som ska hända
    }

    if(reading==2)
    {
        //något annat händer
    }

    if (buttonLadder.onRelease(button))
    {

    }


    if(button1.isPressed()&&buttonLadder.onRelease(button))
    {

    }




}