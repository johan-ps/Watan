#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

//#include "../resources.h"
//#include "../developments/criteria/criterion.h"

class Criterion;
class Goal;
class Resource;

class Player {
    std::string colour;
    //Dice* dice;

    protected:
        int criteriaCompleted;
        std::vector<Criterion*> criteria;
        std::vector<Goal*> goals;
        std::vector<int> resources;

        int getCriteriaSize();

    public:
        Player(std::string colour, std::vector<int> resources = {0, 0, 0, 0, 0});
        Player(std::string colour, std::vector<Criterion*> criteria, std::vector<Goal*> goals, std::vector<int> resources = {0, 0, 0, 0, 0});

        // Public Methods
        virtual void steal(Player *victim) = 0;
        virtual void trade(Player *otherPlayer, Resource gained, Resource lost) = 0;
        virtual void recieve(Resource type, int amount) = 0;
        virtual void remove(Resource type, int amount) = 0;
        virtual void printStatus() = 0;
        virtual void printCompletions() = 0;
        virtual std::vector<Criterion*> getCriterion();
        virtual std::vector<Goal*> getGoals();
        virtual std::vector<int> getResources();

        //Should possibly change to development pointer or add a purchaseGoal method
        virtual void purchaseCriteria(std::vector<int> cost, Criterion *newCriterion, bool improving, bool init = false) = 0;
        virtual void purchaseGoal(std::vector<int> cost, Goal *newGoal  , bool init = false) = 0;
        
        // Accessors
        std::string getColour();
        int getCompleted();

        // Setters/Mutators

        //void addGoal(Goal *);

        virtual ~Player();
};

#endif
