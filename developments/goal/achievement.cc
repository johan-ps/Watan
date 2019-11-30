#include "achievement.h"

Achievement::Achievement(int locationVal):
    Goal{locationVal} {}

void Achievement::achieve(Player * owner){
    if ("playerHasEnough"){
        setOwner(owner);
        //owner->addGoal(this); // Refactor this using Visitor Pattern
    }
    else {
        throw "InsufficientResourcesException"; // TODO Implement actual Exception
    }

}