#ifndef TURN_H
#define TURN_H

#include "player/player.h"
#include "dice.h"
#include <memory>
#include "gameManager.h"
#include <string>
#include <iostream>

class GameManager;

class Turn {
    Player *whoseTurn;
    GameManager *gm;

    void commenceSteal(std::vector<Player *> studentVictims);

    public:
        Turn(GameManager *gm);
        void startTurn(Player *playerTurn);
        void endTurn();
        Player *getCurStudent();
        //void nextTurn(Player *);
        void help();
};

#endif





