#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

//#include "../resource.h"
//#include "../developments/criteria/criterion.h"

// struct PlayerInfo {
//     std::vector<int> resources;
//     std::vector<Criterion*> criteria;
//     std::string colour;
// };

class Criterion;
class Goal;
//class Development;

class Player {
    std::vector<int> resources;
    std::string colour;
    //Dice* dice;

    protected:
        int criteriaCompleted;
        std::vector<int> getResources();
        std::vector<Criterion*> criteria;
        std::vector<Goal*> goals;

        int getCriteriaSize();
        //PlayerInfo getInfo();


    public:
        Player(std::string colour);

        // Public Methods
        virtual void steal(Player *) = 0;
        virtual void trade(Player *, std::string resource) = 0;
        virtual void printStatus() = 0;
        virtual void printCompletions() = 0;

        //Should possibly change to development pointer or add a purchaseGoal method
        virtual bool purchaseCriteria(std::vector<int>, Criterion *) = 0;
        virtual bool purchaseGoal(std::vector<int>, Goal *) = 0;




        // Accessors
        std::string getColour();

        // Setters/Mutators
        //void addGoal(Goal *);

        virtual ~Player();
};

#endif
