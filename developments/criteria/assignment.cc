#include "assignment.h"

Assignment::Assignment(int location):
    location{location}{}

void Assignment::complete(Player &player) {}

void Assignment::improve() {}

// void Assignment::distributeResources() {}

int Assignment::getCriterionType(){
    return 1;
}
