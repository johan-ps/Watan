#ifndef __DICE_H__
#define __DICE_H__

#include <stdlib.h>
#include <ctime>
#include "board.h"

class Dice {
    bool isRandom;
    bool isSeed;
    Board *board;
    int rollVal;

    public:
        Dice();
        void setBoard(Board *board);
        void roll();
        void setLoadVal(int rollChoice);
        void setDice(bool isRand);
        void setSeed(int seed);
        ~Dice();
};

#endif