#ifndef __CRITERIA_H__
#define __CRITERIA_H__
#include "../development.h"

class Criterion : public Development {
    public:
    // virtual void improve() = 0;
    // virtual void distributeResources() = 0;
    int getCriterionType();
};

#endif