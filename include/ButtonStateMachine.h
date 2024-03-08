//State machine class for handling combinations of button presses.
#include <Arduino.h>
#include <ButtonLadder.h>
class ButtonHandler {
public:
    //This variables is the pin number of the play/shift button.
    int m_shiftButtonPin = 2;
    // Declaring an object of ButtonLadder. 
    ButtonLadder buttonLadder;

    //This sets the maximum time of what is a valid short press of the play/shift button. 
    int m_shortPressMax = 250;
    
    // State variables
    enum State {
        IDLE,
        SHIFT_PRESSED,
        BUTTON_PRESSED
    };
    
    State currentState = IDLE;      //Default state
    unsigned long pressStartTime = 0; //Timer for press time.

    // Constructor with member initializer list
    ButtonHandler() : buttonLadder(0) {}

    uint8_t handleButtonPress() {
        int shiftButtonState = digitalRead(m_shiftButtonPin);
        uint8_t ladderButtonValue = buttonLadder.buttonLadder();

        switch (currentState) {
            case IDLE:
                if (shiftButtonState) {
                    currentState = SHIFT_PRESSED; //Goes to next state
                    pressStartTime = millis();  //Staring timer when shift/play button is pressed
                } else if (ladderButtonValue > 0) {
                    // Continuously return the ladder button value when pressed and shift is not pressed
                    return ladderButtonValue;
                }
                break;

            case SHIFT_PRESSED:
                // If shift/play button is released it checks if it's released within the short press time.
                // If it is value 30 is returned. If released after short press max time 0 is returned and state goes to IDLE again.
                if (!shiftButtonState) {
                    if (millis() - pressStartTime < m_shortPressMax) {
                        currentState = IDLE;
                        return 30;  // Return 30 if shiftButton pressed and released quickly
                    } else {
                        currentState = IDLE;
                        return 0;   // Return 0 if shiftButton pressed and released after m_shortPressMax
                    }

                // If play/shift button is still pressed AND button ladder is pressed value 9-16 is returned and goes to next state.
                } else if (ladderButtonValue > 0) {
                    currentState = BUTTON_PRESSED;
                    return ladderButtonValue + 8;
                }
                break;
            // We stay in this state until the play/shift button is released and we go back to IDLE state again. 
            case BUTTON_PRESSED:
                if (!shiftButtonState) {
                    currentState = IDLE;
                }
                break;

            default:
                break;
        }

        return 0;  // Default: no valid button press
    }   
};