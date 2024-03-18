//button.h
//This header file contains the Class Button.
//It reads the status of the shift button and updates the corresponding bit (isPressed, onRelease and so on)
//it also includes a function for debouncing to protect from irregular reading
#ifndef BLIPBLOPSEQUENCER_BUTTON_H
#define BLIPBLOPSEQUENCER_BUTTON_H
#include <Arduino.h>

class Button
{
private:

    //member variables
    uint8_t m_status;  // 00000000
    const unsigned int m_digitalPin;
    unsigned long m_lastDebounceTime = 0;
    const unsigned long m_debounceTime = 50;


public:
    //Constructor
    Button(int unsigned digitalPin) :m_status(0), m_digitalPin(digitalPin)
    {
        pinMode(digitalPin, INPUT);
    }

    //checks the state of the button
    void update();

    //Functions that returns the state of the button
    bool isPressed();
    bool onPress();
    bool onRelease();

    bool m_toggleState = false;
};

#endif //BLIPBLOPSEQUENCER_BUTTON_H
