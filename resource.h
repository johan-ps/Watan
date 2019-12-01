#ifndef __RESOURCE_H__
#define __RESOURCE_H__
#include <string>

//enum class ResourceType = {caffeine, lab, lecture, study, tutorial, netflix};
//sstd::string resourceNames [6];

std::string getResourceName(int num);

int getResourceNum(std::string name);

#endif