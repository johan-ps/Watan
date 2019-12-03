#include "geese.h"

#include <iostream>
#include <vector>


void Geese::eatResources(Player* victim){
    
    // Choose half of the victim's resources to be lost (rounded down)

    int numResourcesLost = -1;

    std::vector<int> lostResources;

    std::cout << "Student " << victim->getColour();
    std::cout << " loses " << numResourcesLost << "resources to the geese. They lose:" << std::endl;


    for (auto resourceLost: lostResources){ // might have to do ++i
        //std::cout << numResource << " " << resourceName << std::endl; 
    }

}