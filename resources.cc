#include "resources.h"

Resource::Resource(std::string resourceType):
    resourceType{resourceType} {
        resourceType = getNameToLower();
        for(unsigned int i = 0; i < resourceNames.size(); ++i){
            if(resourceNames[i] == resourceType) {
                resourceVal = i;
                break;
            }
        }
    }

Resource::Resource(unsigned int resourceVal):
    resourceVal{resourceVal} {
        for(unsigned int i = 0; i < resourceNames.size(); ++i){
            if(resourceVal == i) {
                resourceType = resourceNames[i];
                break;
            }
        }
    }

std::string Resource::getName() {
    return resourceType;
}

int Resource::getVal() {
    return resourceVal;
}

std::string Resource::getNameToLower() {
    std::string nameLower = resourceType;
    for (unsigned int i = 0; i < nameLower.length(); i++) {
        nameLower[i] = std::tolower(nameLower[i]);
    }
    return nameLower;
}

std::string Resource::getNameToUpper() {
    std::string nameUpper = resourceType;
    for (unsigned int i = 0; i < nameUpper.length(); i++) {
        nameUpper[i] = std::tolower(nameUpper[i]);
    }
    return nameUpper;
}
