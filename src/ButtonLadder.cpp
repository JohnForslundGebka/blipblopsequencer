#include "ButtonLadder.h"
#include <Arduino.h>


uint8_t ButtonLadder::buttonLadder()
{
    //reads value from the resistor ladder, only used privately for the read() function.
    int buttonReadValue = analogRead(m_pinNumber);


    if (buttonReadValue > 100) {
        if (buttonReadValue < 200) return 1;
        else if (buttonReadValue < 300) return 2;
        else if (buttonReadValue < 450) return 3;
        else if (buttonReadValue < 600) return 4;
        else if (buttonReadValue < 800) return 5;
        else if (buttonReadValue < 900) return 6;
        else if (buttonReadValue > 1000) return 7;
    }
    return 0;
    
}

//Reads the button ladder with debounce and returns the button number. No button pressed returns 0.
uint8_t ButtonLadder::read()
{
   uint8_t reading = buttonLadder();

    if ((millis() - m_lastDebounceTime) > m_debounceTime)
    {
        if (reading != m_buttonState)
        {
            m_lastDebounceTime = millis();
            // Update last state to current state before changing
            m_lastButtonState = m_buttonState;
            m_buttonState = reading;

            if (reading != 0)
            {
                m_pressedButton = reading;
            } else
            {
                m_releasedButton = m_lastButtonState;
            }
        }
    }

    // Reset lastButtonState to current reading for next cycle
    m_lastButtonState = reading;
    return m_buttonState;
}

//function that detects a buttonpress. Also changed the argument (input value)
// to the number of the button being pressed
bool ButtonLadder::onPress(uint8_t &button)
{
    if (m_pressedButton != 0)
    {
        button = m_pressedButton;
        m_pressedButton = 0;
        return true;
    }
    return false;
}

bool ButtonLadder::onRelease(uint8_t &button)
{
    if (m_releasedButton != 0)
    {
        button = m_releasedButton;
        m_releasedButton = 0;
        return true;
    }
    return false;
}

