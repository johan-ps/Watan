#include "geese.h"
#include "resources.h"

#include "tile.h"

#include <iostream>
#include <map>
#include <vector>


void Geese::eatResources(Player* victim){
    
    // Choose half of the victim's resources to be lost (rounded down)
    int numResourcesLost = victim->getResourceCount() / 2;
    int totalResourceTypes = victim->getResources().size();

    std::vector<int> lostResources(totalResourceTypes, 0);

    for (int resourceNum = 0; resourceNum < numResourcesLost; ++resourceNum){
        Resource lostResource = victim->getRandomResource();
        //lostResources[lostResource] += 1;
        lostResources[lostResource.getVal()] += 1;
        victim->remove(lostResource, 1);
    }

    std::cout << "Student " << victim->getColour();
    std::cout << " loses " << numResourcesLost << " resources to the geese. They lose:" << std::endl;

    for (int resourceType = 0; resourceType < totalResourceTypes; ++resourceType ){ 
        if (lostResources.at(resourceType) == 0){
            continue;
        }
        Resource resourceLost{resourceType};
        std::cout << lostResources[resourceType] << " " << resourceLost.getNameToUpper() << std::endl;
    }

}

Tile *Geese::getTile(){
    return currentGeeseTile;
}


void Geese::setCurrentGeeseTile(Tile *newGeeseTile){
    //currentGeeseTile->removeGeese();
    currentGeeseTile = newGeeseTile;
    //currentGeeseTile->setGeese(this);
}