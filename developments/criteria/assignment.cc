#include "assignment.h"
#include "../../resource.h"
#include <iostream>

Assignment::Assignment(int locationVal, std::vector<int> cost):
    Criterion{locationVal, cost} {}

void Assignment::complete(Player *player, bool init) {
    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        try {
            player->purchaseCriteria(getCost(), this, false, init);
            setDevelopment(player, 1);
        } catch (InsufficientResourcesException &r) {
            throw r;
        }
    } else {
        throw AlreadyCompletedException{getLocationVal(), getOwner()->getColour()};
    }
}

void Assignment::notify() {}

void Assignment::distributeResources(Resource resource) {
    Player *owner = getOwner();
    if(owner) {
        owner->recieve(resource.getVal(), getCriteriaVal());
    }
}


void Assignment::improve(Player* player, bool init) {
    std::vector<int> upgradeCost;
    int currentVal = getCriteriaVal();

    if (!getOwner()) {
        throw InvalidCriteriaException{getLocationVal(), player->getColour()};
    }

    if(currentVal == 1){
        upgradeCost = { 0, 0, 2, 3, 0};
    } else if (currentVal == 2){
        upgradeCost = { 3, 2, 2, 2, 1};
    } else {
        throw CriteriaCannotBeImprovedException{getLocationVal()};
    }
    
    try {
        player->purchaseCriteria(upgradeCost, this, true, init);
        setCriteriaVal(++currentVal);
    } catch (InsufficientResourcesException &r) {
        throw r;
    }
}

Assignment::~Assignment() {}





