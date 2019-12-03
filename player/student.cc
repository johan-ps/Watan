#include "student.h"
#include "../resources.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "../developments/criteria/criterion.h"

using namespace std;

Student::Student(std::string colour, std::vector<int> resources): Player{colour, resources} {}

Student::Student(std::string colour, std::vector<Criterion*> criteria, 
    std::vector<Goal*> goals, std::vector<int> resources):
    Player{colour, criteria, goals, resources} {}


// Trade a resource with otherPlayer
void Student::trade(Player *otherPlayer, Resource gained, Resource lost) {
    try {
        remove(lost, 1);
        
        try {
            otherPlayer->remove(gained, 1);
        } catch(InvalidTradeException &t) {
            recieve(lost, 1);
            throw t;
        }
        recieve(gained, 1);
        otherPlayer->recieve(lost, 1);
    } catch (InvalidTradeException &t) {
        throw t;
    }
}

// Steal a random resource from a victim
// Note: Should be called by a player who currently has a Geese
void Student::steal(Player *victim) {

    // Calculate randomly selected resource to be stolen

    std::string stolenResource = "CAFFEINE"; // DEFAULT PLACEHOLDER

    int totalResources = victim->getResourceCount();

    /*The probability of stealing/losing each resource is the number of the resource the student being
    stolen from has, divided by the total number of resources the student being stolen from has. */

    int resourceToBeStolen = rand() % totalResources;

    //int resourceStolen = victim->stealResource(resourceToBeStolen); // change to Resource type



    std::cout << "Student " << getColour() << " steals " << stolenResource;
    std::cout << " from student " << victim->getColour() << "." << std::endl;

}

void Student::remove(Resource type, int amount) {
    if (resources.at(type.getVal()) < amount) {
        throw InvalidTradeException{resources.at(type.getVal()), type.getName(), getColour()};
    }
    resources.at(type.getVal()) -= amount;
}

void Student::recieve(Resource type, int amount){
    resources.at(type.getVal()) += amount;
}

// Print the player's resources and owned criteria
// Should be called by either TextDisplay or main.cc (depending on implementation)
void Student::printStatus() {

    cout << getColour() << " has " << getCriteriaSize() << " course criteria, " << endl;

    unsigned int last_resource = resources.size();

    for (unsigned int i = 0; i < last_resource; ++i){
        cout << resources.at(i) << " ";

        Resource temp {i};
        if ( i == 3){
            cout << "studies," << endl;
        }
        else if (i < last_resource - 1){
            cout << temp.getName() /*getResourceName(i)*/ << "s, " << endl;
        }
        else{
            cout << temp.getName() /*getResourceName(i)*/ << "s." << endl;
        }

    }
}

void Student::purchaseCriteria(std::vector<int> cost, Criterion *newCriterion, bool improving, bool init) {
    if (init) {
        criteria.push_back(newCriterion);
        ++criteriaCompleted;
        return;
    }

    for(unsigned int i = 0; i < 5; ++i) {
        if(cost[i] > resources[i]) {
            Resource temp {i};
            throw InsufficientResourcesException {temp.getName(), getColour()};
        }
    }
    for(int j = 0; j < 5; ++j){
        resources[j] -= cost[j];
    }

    if(!improving) {
        criteria.push_back(newCriterion);
    }

    ++criteriaCompleted;
    if(criteriaCompleted >= 10){
        //end the game somehow 
        // WE SHOULD PROBABLY THROW A "GameWon" EXCEPTION AND CATCH IT ALL THE WAY BACK IN END TURN!!!
    }
}

void Student::purchaseGoal(std::vector<int> cost, Goal *newGoal, bool init) {
    if (init) {
        goals.push_back(newGoal);
        return;
    }
    for(unsigned int i = 0; i < 5; ++i) {
        if(cost[i] > resources[i]) {
            Resource temp {i};
            throw InsufficientResourcesException {temp.getName(), getColour()};
        }
    }
    for(int j = 0; j < 5; ++j){
        resources[j] -= cost[j];
    }

    goals.push_back(newGoal);
}



// Print the player's completed criterions
void Student::printCompletions(){
    cout << getColour() << " has completed:" << endl;

    for (auto criterion: criteria){
        cout << criterion->getLocationVal() << " " << criterion->getCriteriaVal() << endl;
    }

}

Student::~Student() {
    criteria.clear();
    goals.clear();
}





