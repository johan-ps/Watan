#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

#include "../resource.h"
//#include "../developments/criteria/criterion.h"

class Criterion;
class Goal;

class Player {
    std::string colour;
    //Dice* dice;

    protected:
        int criteriaCompleted;
        std::vector<int> resources;
        std::vector<Criterion*> criteria;
        std::vector<Goal*> goals;

        int getCriteriaSize();

    public:
        Player(std::string colour);

        // Public Methods
        virtual void steal(Player *) = 0;
        virtual void trade(Player *, std::string, std::string) = 0;
        virtual void recieve(int, int) = 0;
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
