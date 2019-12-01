#include "dice.h"

Dice::Dice(Board *board):
    isRandom{true}, board{board} {}

void Dice::roll() {
    if (isRandom){
        srand(time(0));
        rollVal = rand() % 6 + 1;
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
    srand(seed);
}

Dice::~Dice() {}
