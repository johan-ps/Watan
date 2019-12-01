#include "dice.h"

Dice::Dice():
    isRandom{false}, rollVal{6} {} 

int Dice::roll(){
    // if (isRandom){
    //     rollVal = 6;
    // }
    return(rollVal);
}

void dice::setDice(int rollChoice){
    rollVal = rollChoice;
}

dice::~dice(){}
