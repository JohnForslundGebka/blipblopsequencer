#include <Arduino.h>
#include "pitches.h"
#include "buttonLadder.h"
#include "Button.h"
#include "LedRow.h"
#include "Sequencer.h"

int stepCount = 1;

ButtonLadder buttonLadder(0);
Button button1(2);
LedRow leds; //This class uses the digital pins 4,7,8,12
Sequencer seq;

bool isPlaying = false;

void setup() {

 Serial.begin(9600);
}

void loop() {

    button1.update();
    buttonLadder.read();
    uint8_t button;

    // Check if a button was just pressed
    if (buttonLadder.onPress(button)) {
        Serial.print("ButtonLadderPress: ");
        Serial.println(button);
    }

    // Check if a button is currently being pressed
    if (buttonLadder.isPressed(button)) {
        Serial.print("ButtonLadderIsBeingPressed: ");
        Serial.println(button);
    }

    // Check if a button was just released
    if (buttonLadder.onRelease(button)) {
        Serial.print("ButtonLadderWasReleased: ");
        Serial.println(button);
    }


    if (button1.onPress()) {
        Serial.println("Button Pressed");
    }

    if (button1.onRelease()) {
        Serial.println("Button Released");
    }

    if (button1.isPressed()) {
        Serial.println("Button is being pressed");
    }




}