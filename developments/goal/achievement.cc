#include "achievement.h"

#include <iostream>

Achievement::Achievement(int locationVal, std::vector<int> cost):
    Goal{locationVal, cost} {}

void Achievement::achieve(Player *player, bool init){

    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        if(player->purchaseGoal(getCost(), this, init)) {
            setDevelopment(player, 0);
            //alert text display of new owner/criteria type somehow
        } else {
            throw "InsufficientResourcesException";
        }
    } else {
        throw "AlreadyAchievedException";
    }

}

Achievement::~Achievement() {}
