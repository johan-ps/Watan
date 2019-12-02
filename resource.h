#ifndef __RESOURCE_H__
#define __RESOURCE_H__
#include <string>

//enum class ResourceType = {caffeine, lab, lecture, study, tutorial, netflix};
//sstd::string resourceNames [6];

std::string getResourceName(int);

int getResourceNum(std::string);

#endif