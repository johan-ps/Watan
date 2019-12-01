#ifndef __DICE_H__
#define __DICE_H__

class Dice {
    bool isRandom;
    int rollVal;

    public:
        Dice();
        int roll();
        void setDice(int rollChoice);
        ~Dice();
};

#endif