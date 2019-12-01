#include "development.h"

Development::Development(int locationVal, const std::vector<int> cost):
    locationVal {locationVal}, cost{cost}, player{nullptr} {}
    
void Development::setDevelopment(Player *owner){
    setOwner(owner);
}

void Development::setOwner(Player * owner){
    player = owner;
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