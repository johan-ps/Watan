#include "student.h"
#include "../resource.h"

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
    cout << colour << " has " << 99 << "course criteria, " << endl;
    cout << 99 << " labs" << endl;
    cout << 99 << " lectures" << endl;
    cout << 99 << " studies" << endl;
    cout << 99 << " tutorials" << endl;
}

// void printCompletions(){
//     cout << colour << " has completed:" << endl;

//     for (auto criterion: criteria){
//         cout << criterion->getLocationVal << " " << criterion->getCriterionType << endl;
//     }
    
// }
