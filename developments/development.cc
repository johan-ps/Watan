#include "development.h"

void Development::setOwner(Player * owner){
    player = owner;
}

Development::Development(int locationVal):
    locationVal {locationVal} {}

int Development::getLocationVal() {
    return locationVal;
}

Development::~Development() {}