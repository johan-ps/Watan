#include "achievement.h"

#include <iostream>

Achievement::Achievement(int locationVal, int criteriaVal, std::vector<int> cost):
    Goal{locationVal, 0, cost} {}

void Achievement::achieve(Player *player, bool init){

    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        try {
            player->purchaseGoal(getCost(), this, init);
            setDevelopment(player, 0);
        } catch (InsufficientResourcesException &r) {
            throw r;
        }
    } else {
        throw AlreadyAchievedException {getLocationVal(), getOwner()->getColour()};
    }

}

Achievement::~Achievement() {}





