#include "player.h"
#include "student.h"

#include "../developments/criteria/assignment.h"
#include "../developments/goal/achievement.h"

class Assignment;
class Achievement;

#include <iostream>

// This is just to test files in the "player" folder

using namespace std;

int main (int argc, char *argv[]){

    Student s {"Blue", 
    {new Assignment{99, {1,5, 1, 90, 4}}},
    {new Achievement{15, {14, 91, 46, 4, 1}}},
    {99,99,99,99,99}};

    //Player *pp = &s;
    
    cout << s.getColour() << endl;
    s.printStatus();
    s.printCompletions();
    

}