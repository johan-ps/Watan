#include "geese.h"
#include "resources.h"

#include <iostream>
#include <vector>


void Geese::eatResources(Player* victim){
    
    // Choose half of the victim's resources to be lost (rounded down)
    int numResourcesLost = victim->getResourceCount() / 2;

    std::vector<Resource> lostResources;

    for (int resourceNum = 0; resourceNum < numResourcesLost; ++resourceNum){
        Resource lostResource = victim->getRandomResource();
        lostResources.emplace_back(lostResource);
        victim->remove(lostResource, 1);
    }

    std::cout << "Student " << victim->getColour();
    std::cout << " loses " << numResourcesLost << "resources to the geese. They lose:" << std::endl;
    // NOTE: numResourcesLost may not always equal lostResources.size() if something unexpected happens
    //       When debugging, print both to see if that is the case.

    for (auto resourceLost: lostResources){ // SHOULD TURN INTO MAP TO PRINT # of EACH TYPE
        std::cout << resourceLost.getNameToUpper() << std::endl;
    }


    //for (auto resourceLost: lostResources){ // might have to do ++i
        //std::cout << numResource << " " << resourceName << std::endl; 
    //}

}