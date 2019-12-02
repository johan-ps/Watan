#include "resource.h"

std::string resourceNames [6] = {"caffeine", "lab", "lecture", "study", "tutorial", "netflix"};

std::string getResourceName(int num) {
    return resourceNames[num];
    // MIGHT HAVE TO THROW AN EXCEPTION IF USED IMPROPERLY
}

int getResourceNum(std::string name){
    for (unsigned int i = 0; i < name.length(); i++) {
        name[i] = std::tolower(name[i]);
    }
    for(int i = 0; i < 6; ++i){
        if(resourceNames[i] == name) {
            return i;
        }
    }
    
    return -1; // THROW AN EXCEPTION
}