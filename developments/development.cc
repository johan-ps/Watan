#include "development.h"

Development::Development(int locationVal, int criteriaVal, const std::vector<int> cost):
    locationVal {locationVal}, criteriaVal{criteriaVal}, cost{cost}, player{nullptr} {}
    
void Development::setDevelopment(Player *owner, int developmentVal){
    setOwner(owner);
    setCriteriaVal(developmentVal);
}

void Development::setOwner(Player * owner){
    player = owner;
}

int Development::getLocationVal() {
    return locationVal;
}

int Development::getCriteriaVal() {
    return criteriaVal;
}

void Development::setCriteriaVal(int newVal) {
    criteriaVal = newVal;
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

Player *Development::getOwner() {
    return player;
}

Development::~Development() {
    delete player;
}





