#include "student.h"
#include "../resource.h"
#include <vector>
#include <iostream>

using namespace std;

Student::Student(std::string colour, std::vector<int> resources): Player{colour, resources} {}

Student::Student(std::string colour, std::vector<Criterion*> criteria, 
    std::vector<Goal*> goals, std::vector<int> resources):
    Player{colour, criteria, goals, resources} {}


// Trade a resource with otherPlayer
void Student::trade(Player *otherPlayer, std::string resourceOffered, std::string resourceRequested) {

}

// Steal a random resource from a victim
// Note: Should be called by a player who currently has a Geese
void Student::steal(Player *victim) {

}

void Student::recieve(int resourceNum, int resourceAmount){
    resources.at(resourceNum) += resourceAmount;
}

// Print the player's resources and owned criteria
// Should be called by either TextDisplay or main.cc (depending on implementation)
void Student::printStatus() {

    cout << getColour() << " has " << getCriteriaSize() << " course criteria, " << endl;

    int last_resource = resources.size();

    for (int i = 0; i < last_resource; ++i){
        cout << resources.at(i) << " ";

        if ( i == 3){
            cout << "studies," << endl;
        }
        else if (i < last_resource - 1){
            cout << getResourceName(i) << "s, " << endl;
        }
        else{
            cout << getResourceName(i) << "s." << endl;
        }

    }
}

bool Student::purchaseCriteria(std::vector<int> cost, Criterion * newCriterion) {

    for(int i = 0; i < 6; ++i) {
        if(cost[i] > resources[i]) {
            return false;
        }
    }
    for(int j = 0; j < 6; ++j){
        resources[j] -= cost[j];
    }

    criteria.push_back(newCriterion);
    ++criteriaCompleted;
    if(criteriaCompleted >= 10){
        //end the game somehow
    }
    return true;
}

bool Student::purchaseGoal(std::vector<int> cost, Goal * newGoal) {

    for(int i = 0; i < 6; ++i) {
        if(cost[i] > resources[i]) {
            return false;
        }
    }
    for(int j = 0; j < 6; ++j){
        resources[j] -= cost[j];
    }

    goals.push_back(newGoal);
    return true;
}



// Print the player's completed criterions
void Student::printCompletions(){
    cout << getColour() << " has completed:" << endl;

//     for (auto criterion: criteria){
//         cout << criterion->getLocationVal << " " << criterion->getCriterionType << endl;
//     }

}
