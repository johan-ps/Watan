#include "assignment.h"

Assignment::Assignment(int locationVal):
    Criterion{locationVal}{}

<<<<<<< HEAD
void Assignment::complete(Player *player) {}
=======
void Assignment::complete(Player &player) {
    player->
}
>>>>>>> 4e038ed2ceeca1e05778ec788fdd683b94249989

void Assignment::improve() {}

void Assignment::distributeResources() {}

int Assignment::getCriterionType(){
    return 1;
}
