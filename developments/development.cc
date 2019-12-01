#include "development.h"

Development::Development(int locationVal, const std::vector<int> cost):
    locationVal {locationVal}, criteriaVal{0}, cost{cost}, player{nullptr} {}
    
void Development::setDevelopment(Player *owner, int developmentVal){
    setOwner(owner, developmentVal);
}

void Development::setOwner(Player * owner, int developmentVal){
    player = owner;
    criteriaVal = developmentVal;
}

int Development::getCriteriaVal() {
    return criteriaVal;
}

int Development::getLocationVal() {
    return locationVal;
}

bool Development::isSet(){
    if (player){
        return true;
    } else { 
        return false;
    }

    // return player;
}

const std::vector<int> Development::getCost(){
    return cost;
}

Player * Development::getOwner() {
    return player;
}

Development::~Development() {}