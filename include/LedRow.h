//Ledrow.h controls the leds, changing the state of the digital ports to manipulate the flow of current

#ifndef BLIPBLOPSEQUENCER_LEDROW_H
#define BLIPBLOPSEQUENCER_LEDROW_H


class LedRow {
private:
    const unsigned int m_pinA = 4;
    const unsigned int m_pinB = 7;
    const unsigned int m_pinC = 8;
    const unsigned int m_pinD = 12;

public:

    //default constructor
    LedRow();

    //Function that turns on the corresponding LED
    void led_on(int ledNum);

};


#endif //BLIPBLOPSEQUENCER_LEDROW_H
