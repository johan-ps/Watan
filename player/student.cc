#include "student.h"
#include "../resource.h"
#include <vector>
#include <iostream>

using namespace std;

Student::Student(std::string colour):
    Player{colour} {}


// Trade a resource with otherPlayer
void Student::trade(Player *otherPlayer, Resource resource) {

}

// Steal a random resource from a victim
// Note: Should be called by a player who currently has a Geese
void Student::steal(Player *victim) {

}

// Print the player's resources and owned criteria
// Should be called by either TextDisplay or main.cc (depending on implementation)
void Student::printStatus() {

    vector<int> resources = getResources();

    cout << getColour() << " has " << getCriteriaSize() << "course criteria, " << endl;
    // cout << resources.at(Resource::caffeine) << " caffeines" << endl;
    // cout << resources.at(Resource::lab) << " labs" << endl;
    // cout << resources.at(Resource::lecture) << " lectures" << endl;
    // cout << resources.at(Resource::study) << " studies" << endl;
    // cout << resources.at(Resource::tutorial) << " tutorials" << endl;

    cout << resources.at(0) << " caffeines" << endl;
    cout << resources.at(1) << " labs" << endl;
    cout << resources.at(2) << " lectures" << endl;
    cout << resources.at(3) << " studies" << endl;
    cout << resources.at(4) << " tutorials" << endl;

    //for (auto resource: Resource::resourceType){
    //
    //}
}

bool Student::purchase(std::vector<int> cost, Development * development) {
    vector<int> resources = getResources();

    for(int i = 0; i < 6; ++i) {
        if(cost[i] > resources[i]) {
            return false;
        }
    }
    for(int j = 0; j < 6; ++j){
        resources[j] -= cost[j];
    }

    //criteria.push_back(development);
    return true;
}


// Print the player's completed criterions
// void Student::printCompletions(){
//     cout << colour << " has completed:" << endl;

//     for (auto criterion: criteria){
//         cout << criterion->getLocationVal << " " << criterion->getCriterionType << endl;
//     }
    
// }
