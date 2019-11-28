#ifndef __CRITERIA_H__
#define __CRITERIA_H__
#include "../development.h"

class Criterion : public Development {
    public:
    Criterion(int locationVal);
    virtual void improve() = 0;
    // virtual void distributeResources() = 0;
    virtual int getCriterionType() = 0;
    virtual ~Criterion();
};

#endif