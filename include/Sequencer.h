#ifndef BLIPBLOPSEQUENCER_SEQUENCER_H
#define BLIPBLOPSEQUENCER_SEQUENCER_H
#include "pitches.h"
#include "LedRow.h"


class Sequencer {
private:
    const unsigned int BUZZER = 13;
    int m_stepCount = 1;


    unsigned long m_nowTime = 0;
    unsigned long m_lastTime = 0;
    int m_tempo = 300;

public:
    //starts the sequencer
    void play(LedRow &leds);

    int m_currentSeq[8]{NOTE_FS4,NOTE_A4,NOTE_CS4,NOTE_E5,NOTE_GS5,NOTE_FS5,NOTE_CS5};
    int m_scale[7] = {NOTE_FS4,NOTE_A4,NOTE_CS4,NOTE_E5,NOTE_GS5,NOTE_FS5,NOTE_CS5};

};

#endif //BLIPBLOPSEQUENCER_SEQUENCER_H
