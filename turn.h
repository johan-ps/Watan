#ifndef TURN_H
#define TURN_H

#include "player/player.h"
#include "dice.h"

#include <string>

class Turn{
    Player* whoseTurn;
    Dice* dice;
    std::string phase;

    public:
        Turn(Player* whoseTurn, Dice* dice, std::string phase);

        void startTurn();
        Player* getCurStudent();
        void nextTurn(Player *);

        void help();



};

#endif