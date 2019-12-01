#ifndef __RESOURCE_H__
#define __RESOURCE_H__
#include <string>

std::string resourceType [6]= {"caffeine", "lab", "lecture", "study", "tutorial", "netflix"};
std::string getName(int);
int getNum(std::string);

#endif