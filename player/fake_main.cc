#include "player.h"
#include "student.h"

#include <iostream>

// This is just to test files in the "player" folder

using namespace std;

int main (int argc, char *argv[]){

    Student s {"Blue"};

    //Player *pp = &s;
    
    cout << s.getColour() << endl;
    s.printStatus();

}