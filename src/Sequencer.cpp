#include "Sequencer.h"
#include <Arduino.h>

//function to play the sequence
void Sequencer::play(bool ledsOn)
{
      m_tempo = map(analogRead(1), 0, 1023, 1000, 30); //Read pot 1 and sets tempo  

      m_noteLength = map(analogRead(2), 0, 1023, 1000, 20); //Read pot 2 and sets note length 

      m_nowTime = millis();
      if(m_nowTime - m_lastTime >= m_tempo)   //if enough time has passed, play the next note
      {
          m_lastTime = millis();
          tone(BUZZER, m_scales[m_currentScale][m_currentSeq[m_stepCount]],m_noteLength);

         if(ledsOn) m_components.leds.ledOn(m_stepCount);  //turn on the corresponding LED
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
                m_currentSeq[stepCount] = button-1; //set the current seq the  value of the button (1-7)
                tone(BUZZER, m_scales[m_currentScale][button-1], 200); //play the note
                stepCount++;
                delay(100);
            }

       }

    m_components.leds.ledOn(13);  //Set all the LEDS to off

}

void Sequencer::scaleMode(bool &isPlaying)
{
    uint8_t blueLed = 9;
    //initial turn on leds (uses the currently set scale and the blue led)
    m_components.leds.ledOn(m_currentScale, blueLed);
    // inits reading as 0 (meaning no buttons pressed)
    int reading = 0;
    //counter to stop user/program from registering reading from button to fast
    unsigned int counter = 1;


    while (true)
    {
        //sets reading as currently pressed button on ladder
        reading = m_components.stateMachine.handleButtonPress();
        counter++;

        //sets play funtion to play current sequence without turning on leds 
        if(isPlaying)
           play(false);

        //sets current scale to pressed button
        if(reading > 0 && reading < 9)
        {
            m_currentScale = (reading - 1);
        }

        //turns on correct led from scale (and blue led)
        m_components.leds.ledOn(m_currentScale, blueLed);
        
        //if shift+ladder7 is pressed, turns off leds and break
        if (reading == 15 && counter > 5)
        {
            m_components.leds.ledOn(13);
            break;
        }

        //plays sequence if shift key is pressed
        if (reading == 30)
        {
            isPlaying = !isPlaying;
        }


        reading = 0;
    }
}

//function the clears the current sequence
void Sequencer::deleteMode()
{
    int buzz = 1000;
    for(int i = 0; i < 8; i++) {
        m_currentSeq[i] = 0; //set all the steps to 0
        m_components.leds.ledOn(i);
        tone(BUZZER, buzz, 100);
        buzz = buzz - 100;
        delay(150);
    }
    m_components.leds.ledOn(13); //turn off all the LEDS
}
