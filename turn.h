#ifndef TURN_H
#define TURN_H

#include "player/player.h"
#include "dice.h"
#include <memory>

#include <string>
#include <iostream>

class Turn{
    Player *whoseTurn;
    Dice *dice;

    public:
        Turn(Dice *dice);

        void startTurn(Player *playerTurn);
        void endTurn();
        Player *getCurStudent();
        //void nextTurn(Player *);
        void help();



};

#endif