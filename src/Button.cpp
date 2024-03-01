#include "button.h"
// Function to read the button with debounce
bool Button::readButton()
{
    bool reading = digitalRead(m_digitalPin);
    bool isValidPress = false;

    if (reading != m_lastButtonState){
        m_lastDebounceTime = millis();
    }

    if ((millis() - m_lastDebounceTime) > m_debounceTime) {
        if (reading != m_buttonState)
        {
            m_buttonState = reading;
            if(m_buttonState==HIGH)
            {
                isValidPress = true;
            }
        }
    }

    m_lastButtonState = reading;
    return isValidPress;
}


void Button::toggleParam(bool &param)
{
    bool isButtonPressed = readButton();

    if (isButtonPressed)
        param = !param;
}