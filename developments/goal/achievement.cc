#include "achievement.h"

#include <iostream>

Achievement::Achievement(int locationVal, std::vector<int> cost):
    Goal{locationVal, cost} {}

void Achievement::achieve(Player *owner){
    ////////////////////
    // NEED TO CHECK IF ADJACENT CRITERIA/GOALS SET; WHO WILL DO THAT, WHERE AND HOW??
    ////////////////////

    std::cout << "entered achieve fnc" << std::endl;
    if (isSet()){
        std::cout << "ENTERED isSet() FUNCTION" << std::endl;
        throw "AlreadyAchievedException"; // TODO Implement actual Exception
    }

    if (false){ // TODO do actual check on player ("!playerHasEnoughResources: payment != cost")
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