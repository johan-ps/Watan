#include "dice.h"
#include <iostream>

Dice::Dice():
    isRandom{true}, isSeed{false}, isSet{false} {}

void Dice::setBoard(Board *board) {
    this->board = board;
}

void Dice::roll() {
    if (!isSet) {
        throw DiceNotSetException{};
    }
    isSet = false;
    if (isRandom){
        if (!isSeed) {
            srand(time(0));
        }
        rollVal = rand() % 10 + 2;
    }

    // Special cases to deal with, such as Geese
    if (rollVal == 7){
        return;
    }


    board->notify(rollVal);
}

void Dice::setLoadVal(int rollChoice) {
    if (rollChoice < 2 || rollChoice > 12) {
        throw DiceOutOfRangeException{};
    }
    rollVal = rollChoice;
    isRandom = false;
    isSet = true;
}

void Dice::setFair() {
    isRandom = true;
    isSet = true;
}

void Dice::setSeed(int seed) {
    isSeed = true;
    srand(seed);
}

int Dice::getRollVal(){
    return rollVal;
}

Dice::~Dice() {}





