#include "ButtonLadder.h"
#include <Arduino.h>


uint8_t ButtonLadder::buttonLadder()
{
    //reads value from the resistor ladder, only used privately for the readButtonLadder() function.
    int buttonReadValue = analogRead(m_pinNumber);

    if (buttonReadValue > 100)
    {
        if(buttonReadValue > 100 && buttonReadValue < 250) {
            return  1;
        } else if (buttonReadValue > 250 && buttonReadValue < 350) {
            return  2;
        } else if (buttonReadValue > 350 && buttonReadValue < 450) {
            return  3;
        } else if (buttonReadValue > 450 && buttonReadValue < 550) {
            return  4;
        } else if (buttonReadValue > 550 && buttonReadValue < 650) {
            return  5;
        } else if (buttonReadValue > 650 && buttonReadValue < 750) {
            return  6;
        } else if (buttonReadValue > 750 && buttonReadValue < 850) {
            return  7;
        } else if(buttonReadValue > 850) {
            return  8;
        }
    }
    else
        return 0;
}

//Reads the button ladder with debounce and returns the button number. No button pressed returns 0.
uint8_t ButtonLadder::readButtonLadder()
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

}



