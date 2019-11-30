#ifndef __CRITERIA_H__
#define __CRITERIA_H__
#include "../development.h"
#include "../../observer.h"

class Criterion : public Development, public Observer {
    public:
        Criterion(int locationVal, const std::vector<int> costs);
        virtual ~Criterion();
        virtual void notify() = 0;
        virtual void improve() = 0;
        virtual void distributeResources() = 0;
        virtual int getCriterionType() = 0;
};

#endif