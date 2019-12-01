#ifndef __RESOURCE_H__
#define __RESOURCE_H__
#include <string>

std::string resourceType [6]= {"caffeine", "lab", "lecture", "study", "tutorial", "netflix"};

std::string getResourceName(int num) {
    return resourceType[num];
}

int getResourceNum(std::string name){
    name[0] = std::tolower(name[0]);
    for(int i = 0; i < 6; ++i){
        if(resourceType[i] == name) {
            return i;
        }
    }
    return 5;
}

#endif