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

bool Button::readShortPress() {
    bool reading = digitalRead(m_digitalPin);

    if (reading != m_lastButtonState) {
        m_lastDebounceTime = millis();
    }

    if ((millis() - m_lastDebounceTime) > m_debounceTime) {
        if (reading != m_buttonState) {
            m_buttonState = reading;

            // Button is pressed
            if (m_buttonState == HIGH) {
                m_buttonPressTime = millis();
            } 
            // Button is released
            else {
                // Check if it was a short press within the specified interval
                unsigned int pressDuration = millis() - m_buttonPressTime;
                if (pressDuration >= SHORT_PRESS_MIN && pressDuration <= SHORT_PRESS_MAX) {
                    return true; // Short press detected
                }
            }
        }
    }

    m_lastButtonState = reading;
    return false; // No short press detected
}

void Button::toggleParam(bool &param)
{
    bool isButtonPressed = readShortPress();

    if (isButtonPressed)
        param = !param;
}