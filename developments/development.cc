#include "development.h"

void Development::setDevelopment(Player *owner){
    setOwner(owner);
}

void Development::setOwner(Player * owner){
    player = owner;
}

Development::Development(int locationVal, const std::vector<int> cost):
    locationVal {locationVal}, cost{cost}, player{nullptr} {}

int Development::getLocationVal() {
    return locationVal;
}

bool Development::isSet(){
    if (player){
        return true;
    }
    else{ return false;
    }

    // return player;
}

Development::~Development() {}