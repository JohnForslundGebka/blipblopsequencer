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




