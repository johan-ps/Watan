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
class Development;

class Player {
    //std::vector<Goal*> goals;
    std::vector<int> resources;
    //Dice* dice;
    std::string colour;

    protected:
        std::vector<int> getResources();
        std::vector<Criterion*> criteria;
        int getCriteriaSize();
        //PlayerInfo getInfo();


    public:
        Player(std::string colour);

        // Public Methods
        virtual void steal(Player *) = 0;
        virtual void trade(Player *, std::string resource) = 0;
        virtual void printStatus() = 0;

        //Should possibly change to development pointer or add a purchaseGoal method
        virtual bool purchase(std::vector<int>, Development *) = 0;



        // Accessors
        std::string getColour();

        // Setters/Mutators
        //void addGoal(Goal *);

        virtual ~Player();
};

#endif
