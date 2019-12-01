#include "achievement.h"

#include <iostream>

Achievement::Achievement(int locationVal, std::vector<int> cost):
    Goal{locationVal, cost} {}

void Achievement::achieve(Player *owner){

    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        
        if(player->purchase(getCost(), this)) {
            setDevelopment(owner);
            //alert text display of new owner/criteria type somehow
        } else {
            throw "InsufficientResourcesException";
        }
    } else {
        throw "AlreadyAchievedException";
    }

}