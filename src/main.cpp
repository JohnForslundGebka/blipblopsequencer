#include <Arduino.h>
#include "pitches.h"
#include "buttonLadder.h"
#include "Button.h"
#include "LedRow.h"

ButtonLadder buttonLadder(0);
Button button1(2);
LedRow leds; //This class uses the digital pins 4,7,8,12

void setup() {

 Serial.begin(9600);
}

void loop() {

  uint8_t value = buttonLadder.read();

  leds.ledOn(value);


  delay(100);

}