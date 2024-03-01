#include <Arduino.h>
#include "pitches.h"
#include "buttonLadder.h"
#include "Button.h"

ButtonLadder buttonLadder(0);

void setup() {

 Serial.begin(9600);
}

void loop() {

  uint8_t value = buttonLadder.read();

  Serial.println(value);

  delay(100);

}