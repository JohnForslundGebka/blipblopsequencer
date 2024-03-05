#include "button.h"


//read the state of the button
void Button::update()
{
    bool reading = digitalRead(m_digitalPin);

    //if enough time has passed
    if ((millis() - m_lastDebounceTime) > m_debounceTime)
    {
        // Check if the button state has changed from the last stable state
        if (reading != (m_status & 1))
        {
            m_lastDebounceTime = millis(); // Reset the debounce timer

            // Update the stable state (first bit) to the current reading
            m_status = (m_status & ~(1 << 0)) | (reading << 0);

            // Now, detect the specific transitions
            if (reading)
            {
                // Transition from not pressed to pressed
                m_status |= (1 << 2); // Set the onPress flag (third bit)
            } else {
                // Transition from pressed to not pressed
                m_status |= (1 << 3); // Set the onRelease flag (fourth bit)
            }
        }
    }
}

bool Button::isPressed() {return ((m_status & (1 << 0)) != 0); }

bool Button::onPress()
{    //if bit number two is 1
    if ((m_status & (1 << 2)) != 0)
    {
        m_status &= ~(1 << 2); //set the third bit to 0
        return true;
    }

    return false;
}

bool Button::onRelease()
{
    if ((m_status & (1 <<3 )) != 0) //check if the fourth bit is 1
    {
        m_status &= ~(1 << 3);
        return true;
    }
    return false;
}



void Button::toggleParam(bool &param)
{
    bool hasButtonBeenPressed = isPressed();

    if (hasButtonBeenPressed)
        param = !param;
}