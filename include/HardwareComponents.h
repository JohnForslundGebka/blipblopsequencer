#ifndef BLIPBLOPSEQUENCER_HARDWARECOMPONENTS_H
#define BLIPBLOPSEQUENCER_HARDWARECOMPONENTS_H
#include "ButtonStateMachine.h"
#include "buttonLadder.h"
#include "Button.h"
#include "LedRow.h"

//struct that contains all the instances of the classes being used
struct HardwareComponents {
    ButtonLadder buttonLadder;
    Button button1;
    LedRow leds; // Uses digital pins 4,7,8,12
    ButtonStateMachine stateMachine;

    // Constructor to initialize members
    HardwareComponents() : buttonLadder(0), button1(2) {}
};


#endif //BLIPBLOPSEQUENCER_HARDWARECOMPONENTS_H
