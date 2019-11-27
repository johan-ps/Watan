#ifndef PLAYER_H
#define PLAYER_H

#include "../resource.h"

class Player {
    //std::map<Resources><Integer> resources;
    //std::vector<Goal> goals;
    //std::map<Criterion><int> criteria;   /*** CHANGE TO VECTOR??? (Otherwise, how else to do in order of completion??)***/ 
    //std::vector<Criterion*> criteria;
    //Dice* dice;
    int resourceCount;

    protected:
    std::string colour;

    public:
    Player(std::string colour);
    virtual void trade(Player *, Resource) = 0;
    virtual void steal(Player *) = 0;
    virtual void printStatus() = 0;

    virtual ~Player();
};

#endif
