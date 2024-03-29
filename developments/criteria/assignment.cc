#include "assignment.h"
#include "../../resources.h"
#include <iostream>

Assignment::Assignment(int locationVal, int criteriaVal, std::vector<int> cost):
    Criterion{locationVal, criteriaVal, cost} {}

void Assignment::complete(Player *player, bool init) {
    if(!isSet()){
        try {
            player->purchaseCriteria(getCost(), this, false, init);
            setDevelopment(player, 1);
            if (player->getCompleted() == 10) {
                throw GameOverException{player->getColour()};
            }
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
        //std::cout << owner->getColour() << " recieved a " << resource.getName() << std::endl;
        owner->recieve(resource.getVal(), getCriteriaVal());
        owner->addResourceGained(resource, getCriteriaVal());
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
    } else if(currentVal == 3){
        upgradeCost = {5, 5, 5, 5, 5};
    } else {
        throw CriteriaCannotBeImprovedException{getLocationVal()};
    }
    
    try {
        player->purchaseCriteria(upgradeCost, this, true, init);
        setCriteriaVal(++currentVal);
        if (player->getCompleted() == 10) {
            throw GameOverException{player->getColour()};
        }
    } catch (InsufficientResourcesException &r) {
        throw r;
    }
}

Assignment::~Assignment() {}





