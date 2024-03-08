#include "Sequencer.h"
#include <Arduino.h>


void Sequencer::play(bool ledsOn)
{
      m_nowTime = millis();
      if(m_nowTime - m_lastTime >= m_tempo)
      {
          m_lastTime = millis();
          tone(BUZZER, m_scales[m_currentScale][m_currentSeq[m_stepCount]],200);

         if(ledsOn) m_components.leds.ledOn(m_stepCount);
          m_stepCount++;

          if (m_stepCount==8)
              m_stepCount = 0;

      }
}

void Sequencer::rec()
{
    //counter to keep track of steps
    int stepCount = 0;
    bool buttonWasReleased = false;
    uint8_t buttontest;   //dummy-variabel

    while (!buttonWasReleased)
    {
        m_components.buttonLadder.read();
        buttonWasReleased = m_components.buttonLadder.onRelease(buttontest);
        m_components.leds.ledOn(8);

    }

       m_components.buttonLadder.m_pressedButton = 0;

       while (stepCount <= 7)
       {
           uint8_t button;
           m_components.buttonLadder.read();
           m_components.leds.ledOn(stepCount,8);


               if (m_components.buttonLadder.onPress(button)) {
                   m_currentSeq[stepCount] = button;
                   tone(BUZZER, m_scales[m_currentScale][button], 200);
                   stepCount++;
               }
       }

    m_components.leds.ledOn(13);


}

void Sequencer::readPot1()
{
  m_currentScale = map(analogRead(1),0,1023,0,3);
}

void Sequencer::scaleMode(bool &isPlaying)
{
   m_components.leds.ledOn(m_currentScale,9);
   
    while (true)
    {
       if(isPlaying)
           play(false);
       
        int reading = m_components.stateMachine.handleButtonPress();

        if(reading > 0 && reading < 9)
        {
            m_currentScale = (reading - 1);

        }
         m_components.leds.ledOn(m_currentScale,9);

        if (reading==15)
            break;

        if (reading==30)
            isPlaying = !isPlaying;
    }

}