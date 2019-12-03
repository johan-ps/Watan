#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <string>
#include <vector>

class Resource {
    std::vector<std::string> resourceNames = {"caffeine", "lab", "lecture", "study", "tutorial", "netflix"};
    std::string resourceType;
    unsigned int resourceVal;
    public:
    Resource(std::string resourceType);
    Resource(unsigned int resourceVal);
    std::string getName();
    int getVal();
    std::string getNameToLower();
    std::string getNameToUpper();
};

#endif
