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
    unsigned long m_debounceTime = 10;

    // Define the interval for a short press
    const unsigned int SHORT_PRESS_MIN = 10;  // Minimum time for short press in milliseconds
    const unsigned int SHORT_PRESS_MAX = 400; // Maximum time for short press in milliseconds
    unsigned int m_buttonPressTime;
public:
    //Constructor
    Button(int unsigned digitalPin) : m_digitalPin(digitalPin)
    {
        pinMode(digitalPin, INPUT);
    }

    //This function reads the buttons with debounce and returns true/high if pressed.
    bool readButton();

    bool readShortPress();

    void toggleParam(bool &param);
};




#endif //BLIPBLOPSEQUENCER_BUTTON_H
