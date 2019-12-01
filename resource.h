#ifndef __RESOURCE_H__
#define __RESOURCE_H__
#include <string>

//enum class ResourceType = {caffeine, lab, lecture, study, tutorial, netflix};

std::string resourceNames [6] = {"caffeine", "lab", "lecture", "study", "tutorial", "netflix"};

std::string getResourceName(int num) {
    return resourceNames[num];

    // MIGHT HAVE TO THROW AN EXCEPTION IF USED IMPROPERLY
}

int getResourceNum(std::string name){
    name[0] = std::tolower(name[0]);
    for(int i = 0; i < 6; ++i){
        if(resourceNames[i] == name) {
            return i;
        }
    
    return -1; // THROW AN EXCEPTION
}

#endif