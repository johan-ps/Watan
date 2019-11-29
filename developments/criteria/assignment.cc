#include "assignment.h"

Assignment::Assignment(int locationVal):
    Criterion{locationVal}{}

void Assignment::complete(Player *player) {}

void Assignment::improve() {}

//void Assignment::distributeResources() {}

int Assignment::getCriterionType(){
    return 1;
}
