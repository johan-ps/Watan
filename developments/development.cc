#include "development.h"

Development::Development(int locationVal):
    locationVal {locationVal} {}

int Development::getLocationVal() {
    return locationVal;
}

Development::~Development() {}