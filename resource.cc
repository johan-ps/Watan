#include "resource.h"
#include <string>

std::string Resource::getName(int num) {
    return resourceType[num];
}

int Resource::getNum(std::string name){
    name[0] = std::tolower(name[0]);
    for(int i = 0; i < 6; ++i){
        if(resourceType[i] == name) {
            return i;
        }
    }
}