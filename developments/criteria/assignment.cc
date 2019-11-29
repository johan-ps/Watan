#include "assignment.h"

Assignment::Assignment(int locationVal): 
    Criterion{locationVal}{}


void Assignment::complete(Player* player) {
    for(int i = 0; i < 6; ++i){
    
    }
}

void Assignment::improve() {}

void Assignment::distributeResources() {}

int Assignment::getCriterionType(){
    return 1;
}
