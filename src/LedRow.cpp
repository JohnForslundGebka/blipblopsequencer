#include "LedRow.h"
#include <Arduino.h>

//Function that turns on the corresponding led on the sequencer. Has an int value as an argument that represents which LED turns on
//If argument is 13 all LEDS turn off
void LedRow::ledOn(int ledNum)
{
    switch (ledNum) {
        case 13:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinA, LOW);
            digitalWrite(m_pinB, LOW);
            break;

        case 0:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinA, HIGH);
            digitalWrite(m_pinB, LOW);
            break;

        case 1:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinA, LOW);
            digitalWrite(m_pinB, HIGH);
            break;

        case 2:
            pinMode(m_pinA, INPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, OUTPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinB, HIGH);
            digitalWrite(m_pinC, LOW);
            break;

        case 3:
            pinMode(m_pinA, INPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, OUTPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinB, LOW);
            digitalWrite(m_pinC, HIGH);
            break;

        case 4:
            pinMode(m_pinA, INPUT);
            pinMode(m_pinB, INPUT);
            pinMode(m_pinC, OUTPUT);
            pinMode(m_pinD, OUTPUT);
            digitalWrite(m_pinC, HIGH);
            digitalWrite(m_pinD, LOW);
            break;

        case 5:
            pinMode(m_pinA, INPUT);
            pinMode(m_pinB, INPUT);
            pinMode(m_pinC, OUTPUT);
            pinMode(m_pinD, OUTPUT);
            digitalWrite(m_pinC, LOW);
            digitalWrite(m_pinD, HIGH);
            break;

        case 6:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, INPUT);
            pinMode(m_pinC, OUTPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinA, HIGH);
            digitalWrite(m_pinC, LOW);
            break;

        case 7:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, INPUT);
            pinMode(m_pinC, OUTPUT);
            pinMode(m_pinD, INPUT);
            digitalWrite(m_pinA, LOW);
            digitalWrite(m_pinC, HIGH);
            break;

        case 8:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, INPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, OUTPUT);
            digitalWrite(m_pinA, HIGH);
            digitalWrite(m_pinD, LOW);
            break;

        case 9:
            pinMode(m_pinA, OUTPUT);
            pinMode(m_pinB, INPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, OUTPUT);
            digitalWrite(m_pinA, LOW);
            digitalWrite(m_pinD, HIGH);
            break;

        case 10:
            pinMode(m_pinA, INPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, OUTPUT);
            digitalWrite(m_pinB, HIGH);
            digitalWrite(m_pinD, LOW);
            break;

        case 11:
            pinMode(m_pinA, INPUT);
            pinMode(m_pinB, OUTPUT);
            pinMode(m_pinC, INPUT);
            pinMode(m_pinD, OUTPUT);
            digitalWrite(m_pinB, LOW);
            digitalWrite(m_pinD, HIGH);
            break;

        default:
            break;
    };
}

//overloaded function that turns on two LEDS
void LedRow::ledOn(int led1, int led2) {
    flickerTime = millis();
    if (flickerTime - lastFlickerTime > flickerDelay) {
        if (toggleActiveLed)
            ledOn(led1);
        else
            ledOn(led2);
        lastFlickerTime = flickerTime;
        toggleActiveLed = !toggleActiveLed;
    }
}