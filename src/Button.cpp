#include "button.h"


//read the state of the button
void Button::update() {
    bool reading = digitalRead(m_digitalPin);

    //checks if the state of the button has changed since last time it was checked
    //checks if the second bit is set


    //debounce logic
    if ((millis() - m_lastDebounceTime) > m_debounceTime) {                  //this checks if the first bit is set
        if (reading != ((m_status & (1 << 0)) != 0)) {
            //set the first bit to the same value as reading
            m_status = (m_status & ~(1 << 0)) | (reading << 0);

            //button state has changed, aka check if the first bit is 1
            if (((m_status & (1 << 0)) != 0)) {
                m_status |= (1 << 2); //set the third bit to 1
                m_toggleState = !m_toggleState;
            } else {
                m_status |= (1 << 3); //set the fourth bit to 1
            }
        }
    }
    m_status = (m_status & ~(1 << 1)) | (reading << 0);
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









//void Button::toggleParam(bool &param)
//{
//    bool isButtonPressed = readShortPress();
//
//    if (isButtonPressed)
//        param = !param;
//}