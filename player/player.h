#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "../resource.h"
#include "../developments/criteria/criterion.h"

// struct PlayerInfo {
//     std::vector<int> resources;
//     std::vector<Criterion*> criteria;
//     std::string colour;
// };


class Player {
    std::vector<int> resources;
    //std::vector<Goal*> goals;
    std::vector<Criterion*> criteria;
    //Dice* dice;
    //int resourceCount;
    std::string colour;

    protected:
        std::vector<int> getResources();
        int getCriteriaSize();
        std::string getColour();
        //PlayerInfo getInfo();


    public:
        Player(std::string colour);

        // Public Methods
        virtual void trade(Player *, Resource) = 0;
        virtual void steal(Player *) = 0;
        virtual void printStatus() = 0;

        // Accessors

        // Setters/Mutators
        //void addGoal(Goal *);

        virtual ~Player();
};

#endif
