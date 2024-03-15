//buttonladder.h
//This headerfile contains the Class ButtonLadder.
//The purpose of the class is to read the value from the resistor ladder.
//And return a byte that represents which of the buttons are being pressed.
//it also includes a function for debouncing to protect from irregular reading
#ifndef BLIPBLOPSEQUENCER_BUTTONLADDER_H
#define BLIPBLOPSEQUENCER_BUTTONLADDER_H
#include <Arduino.h>

class ButtonLadder {
private:
    const unsigned int m_pinNumber;

    uint8_t m_lastButtonState = 0;
    unsigned long m_lastDebounceTime;
    const unsigned long m_debounceTime = 30;
    // Button that has been pressed
    uint8_t m_releasedButton = 0;     // Button that has been released


public:
    //Constructor
    ButtonLadder(int analogPin) : m_pinNumber(analogPin) {}

    //A member function that reads the value from the resistor ladder and returns the button number
    //If no button is pressed, returns 0.
    uint8_t buttonLadder();

    //Member function that calls the buttonLadder function and cleans the value with a debounce.
    uint8_t read();

    bool onPress(uint8_t &button);
    bool onRelease(uint8_t &button);
    bool isPressed(uint8_t &button);

    uint8_t m_buttonState = 0;
    uint8_t m_pressedButton = 0;

    //function that resets all the status flags
    void resetFlags()
    {
        m_pressedButton = 0;
        m_releasedButton = 0;
        m_buttonState = 0;
    }

};


#endif //BLIPBLOPSEQUENCER_BUTTONLADDER_H
