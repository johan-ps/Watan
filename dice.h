#ifndef __DICE_H__
#define __DICE_H__

class dice {
    bool isRandom;
    int rollVal;

    public:
    dice();
    int roll();
    void setDice(int rollChoice);
    ~dice();
};

#endif