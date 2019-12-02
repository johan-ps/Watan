#include "assignment.h"
#include "../../resource.h"
#include <iostream>

Assignment::Assignment(int locationVal, std::vector<int> cost):
    Criterion{locationVal, cost} {}

void Assignment::complete(Player *player, bool init) {
    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        if (init) {
            setDevelopment(player, 1);
        } else if(player->purchaseCriteria(getCost(), this, false)) {
            setDevelopment(player, 1);
            //alert text display of new owner/criteria type somehow
        } else {
            throw "InsufficientResourcesException";
        }
    } else {
        throw "AlreadyAchievedException";
    }
}

void Assignment::notify() {}

void Assignment::distributeResources(std::string resource) {
    Player * owner = getOwner();
    if(owner) {
        int resourceNum = getResourceNum(resource);
        owner->recieve(resourceNum, getCriteriaVal());
    }
}


void Assignment::improve(Player* player) {
    std::vector<int> upgradeCost;
    int currentVal = getCriteriaVal();

    if(currentVal == 1){
        upgradeCost = { 0, 0, 2, 3, 0};
    } else if (currentVal == 2){
        upgradeCost = { 3, 2, 2, 2, 1};
    } else {
        throw "CriteriaCannotBeImprovedException";
    }

    if(player->purchaseCriteria(upgradeCost, this, true)){
        setCriteriaVal(++currentVal);
    } else {
        throw "NotEnoughResourcesToImproveException";
    }
}
