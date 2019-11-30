#include "assignment.h"

Assignment::Assignment(int locationVal, std::vector<int> cost):
    Criterion{locationVal, cost} {}

void Assignment::notify() {}

void Assignment::complete(Player *player) {}

void Assignment::improve() {}

void Assignment::distributeResources() {}

int Assignment::getCriterionType() {
    return 1;
}
