#include "ButtonLadder.h"
#include <Arduino.h>


uint8_t ButtonLadder::buttonLadder()
{

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



