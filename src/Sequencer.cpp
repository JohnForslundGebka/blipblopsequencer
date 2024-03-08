#include "Sequencer.h"
#include <Arduino.h>


void Sequencer::play()
{
      m_nowTime = millis();

      if(m_nowTime - m_lastTime >= m_tempo)
      {
          m_lastTime = millis();
          tone(BUZZER, m_currentSeq[m_stepCount],200);
          m_components.leds.ledOn(m_stepCount);
          m_stepCount++;

          if (m_stepCount==9)
              m_stepCount = 1;

      }
}


void Sequencer::rec()
{

    while (true)
    {
        m_components.button1.update();
        m_components.buttonLadder.read();

    }
}