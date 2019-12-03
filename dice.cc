#include "dice.h"
#include <iostream>

Dice::Dice():
    isRandom{true}, isSeed{false} {}

void Dice::setBoard(Board *board) {
    this->board = board;
}

void Dice::roll() {
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
    rollVal = rollChoice;
}

void Dice::setDice(bool isRand) {
    isRandom = isRand;
}

void Dice::setSeed(int seed) {
    isSeed = true;
    srand(seed);
}

int Dice::getRollVal(){
    return rollVal;
}

Dice::~Dice() {}
