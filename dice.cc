#include "dice.h"


dice::dice():
    isRandom{false},
    rollVal{6}{} 

int dice::roll(){
    // if (isRandom){
    //     rollVal = 6;
    // }
    return(rollVal);
}

void dice::setDice(int rollChoice){
    rollVal = rollChoice;
}

dice::~dice(){}
