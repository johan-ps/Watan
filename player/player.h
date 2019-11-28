#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "../resource.h"
#include "../developments/criteria/criterion.h"

class Player {
    std::vector<int> resources;
    //std::vector<Goal> goals;
    std::vector<Criterion*> criteria;
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
