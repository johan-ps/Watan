#include "assignment.h"

<<<<<<< HEAD
Assignment::Assignment(int locationVal): 
    Criterion{locationVal}{}
=======
Assignment::Assignment(int locationVal, std::vector<int> cost):
    Criterion{locationVal, cost} {}
>>>>>>> c10c31d83230831e48461aa589d3c39ae8f518d9

void Assignment::notify() {}

void Assignment::complete(Player *player) {}

void Assignment::improve() {}

void Assignment::distributeResources() {}

int Assignment::getCriterionType() {
    return 1;
}
