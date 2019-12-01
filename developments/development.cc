#include "development.h"

Development::Development(int locationVal, const std::vector<int> cost):
    locationVal {locationVal}, criteriaPoints{0}, cost{cost}, player{nullptr} {}
    
void Development::setDevelopment(Player *owner, int developmentVal){
    setOwner(owner, developmentVal);
}

void Development::setOwner(Player * owner, int developmentVal){
    player = owner;
    criteriaPoints = developmentVal;
}

int Development::getCriteriaPoints() {
    return criteriaPoints;
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

Development::~Development() {}