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

Dice::~Dice() {}
