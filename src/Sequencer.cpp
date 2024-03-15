#include "Sequencer.h"
#include <Arduino.h>


void Sequencer::play(bool ledsOn)
{
      m_tempo = map(analogRead(1), 0, 1023, 1000, 30); //Read pot 1 and sets tempo  

      m_noteLength = map(analogRead(2), 0, 1023, 1000, 20); //Read pot 2 and sets note length 

      m_nowTime = millis();
      if(m_nowTime - m_lastTime >= m_tempo)
      {
          m_lastTime = millis();
          tone(BUZZER, m_scales[m_currentScale][m_currentSeq[m_stepCount]],m_noteLength);

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
    uint8_t dummy;   //dummy-variabel

    //loop that runs until the button is released
    //this is the stop the program from setting the first steps of the sequencer by itself
    while (!buttonWasReleased)
    {
        m_components.buttonLadder.read();
        buttonWasReleased = m_components.buttonLadder.onRelease(dummy);
        m_components.leds.ledOn(8);

    }

       m_components.buttonLadder.m_pressedButton = 0; //manually sets the button to not pressed

       while (stepCount <= 7)
       {
            uint8_t button;
            //read the status of the buttons
            m_components.buttonLadder.read();
            m_components.leds.ledOn(stepCount,8);

            int reading = m_components.stateMachine.handleButtonPress();
            
            if (reading == 10) 
            {
                m_currentSeq[stepCount] = 7;
                stepCount++;
                delay(100);
                m_components.buttonLadder.m_pressedButton = 0; //manually sets the button to not pressed    
            }
            else if (m_components.buttonLadder.onPress(button) && reading > 0 && reading < 9)
            {
                m_currentSeq[stepCount] = button; //set the current seq the  value of the button (1-7)
                tone(BUZZER, m_scales[m_currentScale][button], 200); //play the note
                stepCount++;
                delay(100);
            }

       }

    m_components.leds.ledOn(13);  //Set all the LEDS to off

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

