#ifndef __DICE_H__
#define __DICE_H__

#include <stdlib.h>
#include <ctime>
#include "board.h"

class Dice {
    bool isRandom;
    Board *board;
    int rollVal;

    public:
        Dice(Board *board);
        void roll();
        void setLoadVal(int rollChoice);
        void setDice(bool isRand);
        void setSeed(int seed);
        ~Dice();
};

#endif