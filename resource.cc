#include "resource.h"
#include <vector>

std::string Resource::getName(int value) {
    std::string name[6] = {"caffeine", "lab", "lecture", "study", "tutorial", "netflix"};
    return name[value];
}