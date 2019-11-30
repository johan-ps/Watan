#include "achievement.h"

Achievement::Achievement(int locationVal, const std::vector<int> cost):
    Goal{locationVal, cost} {}

void Achievement::achieve(Player * owner){
    ////////////////////
    // NEED TO CHECK IF ADJACENT CRITERIA/GOALS SET; WHO WILL DO THAT, WHERE AND HOW??
    ////////////////////


    if (isSet()){
        throw "AlreadyAchievedException"; // TODO Implement actual Exception
    }

    if ("!playerHasEnoughResources: payment != cost"){ // TODO do actual check on player
        throw "InsufficientResourcesException"; // TODO Implement actual Exception
        }
    else {
        setDevelopment(owner);
        //owner->addGoal(this); // TODO Refactor this using Visitor Pattern
    }

    ///////////////////////////////////////////////////////////////////////////
    // SOMEBODY NEEDS TO NOTIFY TEXTDISPLAY TO UPDATE ITS DISPLAY FOR THAT GOAL
    ///////////////////////////////////////////////////////////////////////////
}