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

    if (button1.onPress()) {
        Serial.println("Button Pressed");
    }

    if (button1.onRelease()) {
        Serial.println("Button Released");
    }

    if (button1.isPressed()) {
        Serial.println("Button is being pressed"); // Uncomment to see continuous press
    }




}