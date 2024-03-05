//This headerfile contains a class for the play button
#ifndef BLIPBLOPSEQUENCER_BUTTON_H
#define BLIPBLOPSEQUENCER_BUTTON_H
#include <Arduino.h>

class Button
{
private:

    uint8_t m_staus;
    const unsigned int m_digitalPin;
    unsigned long m_lastDebounceTime = 0;
    const unsigned long m_debounceTime = 50;


public:
    //Constructor
    Button(int unsigned digitalPin) :m_staus(0), m_digitalPin(digitalPin)
    {
        pinMode(digitalPin, INPUT);
    }

    //checks the state of the button
    void update();

    //Functions that returns the state of the button
    bool isPressed();
    bool onPress();
    bool onRelease();
    void toggleParam(bool &param);
};

#endif //BLIPBLOPSEQUENCER_BUTTON_H
