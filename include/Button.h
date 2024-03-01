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
    unsigned long m_debounceDelay = 2;
public:
    Button(int unsigned digitalPin) : m_digitalPin(digitalPin) {}

    bool readButton();
};




#endif //BLIPBLOPSEQUENCER_BUTTON_H
