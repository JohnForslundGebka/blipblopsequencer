//This headerfile contains a class for the play button
#ifndef BLIPBLOPSEQUENCER_BUTTON_H
#define BLIPBLOPSEQUENCER_BUTTON_H
#include <Arduino.h>

class Button
{
private:
    const unsigned int m_digitalPin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;

    unsigned long m_lastDebounceTime = 0;
    unsigned long m_debounceTime = 2;
public:
    //Constructor
    Button(int unsigned digitalPin) : m_digitalPin(digitalPin) {}

    //This function reads the buttons with debounce and returns true/high if pressed.
    bool readButton();
};




#endif //BLIPBLOPSEQUENCER_BUTTON_H
