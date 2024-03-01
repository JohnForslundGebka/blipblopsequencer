#include "Sequencer.h"
#include <Arduino.h>


void Sequencer::play(LedRow &leds)
{
        for (int note: m_currentSeq) {
            tone(BUZZER, m_scale[note], 500);
            leds.ledOn(m_stepCount++);
            if (9 == m_stepCount)
                m_stepCount = 1;
        }
    leds.ledOn(0);
}
