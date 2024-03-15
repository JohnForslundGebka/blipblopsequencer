#ifndef BLIPBLOPSEQUENCER_SEQUENCER_H
#define BLIPBLOPSEQUENCER_SEQUENCER_H
#include "pitches.h"
#include "HardwareComponents.h"



class Sequencer {
private:
    const unsigned int BUZZER = 13;
    int m_stepCount = 1;


    unsigned long m_nowTime = 0;
    unsigned long m_lastTime = 0;
    int m_tempo = 100;
    HardwareComponents m_components;


public:
    int m_currentScale = 3;
    Sequencer(HardwareComponents &comp): m_components(comp){}

    //starts the sequencer
    void play(bool ledsOn);

    int m_currentSeq[8]{0,1,2,3,4,5,6,7};

    int m_scales[7][7] = {
            // C Major: C, D, E, F, G, A, B
            {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4},
            // G Major: G, A, B, C, D, E, F#
            {NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_FS5},
            // D Minor (Natural): D, E, F, G, A, Bb, C
            {NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_C5},
            // A Harmonic Minor: A, B, C, D, E, F, G#
            {NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_GS5},
            // E Phrygian: E, F, G, A, B, C, D
            {NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5},
            // Bb Melodic Minor (Ascending): Bb, C, Db, Eb, F, G, A
            {NOTE_AS4, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_A5},
            // F# Mixolydian: F#, G#, A#, B, C#, D#, E
            {NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_B4, NOTE_CS5, NOTE_DS5, NOTE_E5},
    };

    void rec();

    void resetStepCounter() {m_stepCount = 0;}

    void readPot1();

    void scaleMode(bool &isPlaying);


};

#endif //BLIPBLOPSEQUENCER_SEQUENCER_H
