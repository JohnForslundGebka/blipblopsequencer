#include "button.h"
// Function to read the button with debounce
bool Button::readButton()
{
    bool reading = digitalRead(m_digitalPin);

    if (reading != m_lastButtonState){
        m_lastDebounceTime = millis();
    }

    if ((millis() - m_lastDebounceTime) > m_debounceTime) {
        if (reading != m_buttonState) {
            m_buttonState = reading;
        }
    }

    m_lastButtonState = reading;
    return m_buttonState;
}