#ifndef GAMESOUND_H_INCLUDED
#define GAMESOUND_H_INCLUDED

#include "Header.h"

class Sound {
    bool soundEnabled = true;

public:
    bool isSoundEnabled();
    void setSoundEnabled(bool);

    void playBackgroundSound(bool);
    void endGameSound();
    void playPlayerMoveSound();
    void playSuccessSound();
    void playWinSound();
    void playLoseSound();
};

#endif
