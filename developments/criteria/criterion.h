#ifndef __CRITERIA_H__
#define __CRITERIA_H__
#include "../development.h"
//#include "../../observer.h"

class Criterion : public Development {
    public:
        Criterion(int locationVal);
        virtual ~Criterion();
        virtual void notify() = 0;
        virtual void improve() = 0;
        virtual void distributeResources() = 0;
        virtual int getCriterionType() = 0;
};

#endif