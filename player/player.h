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

//class Criterion;

class Player {
    //std::vector<Goal*> goals;
    std::vector<int> resources;
    //Dice* dice;
    std::string colour;

    protected:
        std::vector<int> getResources();
        std::vector<Criterion*> criteria;
        int getCriteriaSize();
        std::string getColour();
        //PlayerInfo getInfo();


    public:
        Player(std::string colour);

        // Public Methods
        virtual void steal(Player *) = 0;
        virtual void trade(Player *, Resource) = 0;
        virtual void printStatus() = 0;
        //Should possibly change to devlopment pointer or add a purchaseGoal method
        virtual bool purchase(std::vector<int>, Criterion *) = 0;



        // Accessors
        string getColour();

        // Setters/Mutators
        //void addGoal(Goal *);

        virtual ~Player();
};

#endif
