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
void Student::steal(Player *victim, int amount) {

    // Calculate randomly selected resource to be stolen
    Resource stolen = victim->getRandomResource();

    // NOTE: Currently if amount > 1, it would steal x amount of the same resource
    //       instead of x random resources

    victim->remove(stolen, amount);
    recieve(stolen, amount); // MAYBE CONSIDER EXCEPTIONS?

    std::cout << "Student " << getColour() << " steals " << stolen.getNameToUpper();
    std::cout << " from student " << victim->getColour() << "." << std::endl;

}

Resource Student::getRandomResource(){
    int totalResources = getResourceCount();

    int resourceNumToBeStolen = rand() % totalResources + 1;

    return findResource(resourceNumToBeStolen);
}

Resource Student::findResource(int resourceNum){
    std::vector<int> resources = getResources();

    int numResourcesSoFar = 0;
    for (int resourceType = 0; resourceType < resources.size(); ++resourceType){
        numResourcesSoFar += resources[resourceType];
        if (resourceNum <= numResourcesSoFar){
                return Resource{resourceType};
                break;
        }
    }

    // IF DESIRED RESOURCE COULD NOT BE FOUND, RETURN NETFLIX AS A "null" VALUE
    return Resource{"netflix"};
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





