//Ledrow.h controls the leds, changing the state of the digital ports to manipulate the flow of current
#ifndef BLIPBLOPSEQUENCER_LEDROW_H
#define BLIPBLOPSEQUENCER_LEDROW_H

#include <Arduino.h>

class LedRow {
private:
    const unsigned int m_pinA = 4;
    const unsigned int m_pinB = 7;
    const unsigned int m_pinC = 8;
    const unsigned int m_pinD = 12;
    int flickerDelay = 5;
    int flickerTime = 0;
    int lastFlickerTime = 0;
    bool toggleActiveLed = true;

public:

    //default constructor
    LedRow()= default;

    //Function that turns on the corresponding LED
    void ledOn(int ledNum);

    //function for turning on two LEDS at once
    void ledOn(int led1, int led2);
};

#endif //BLIPBLOPSEQUENCER_LEDROW_H