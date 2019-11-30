#ifndef __CRITERIA_H__
#define __CRITERIA_H__
#include "../development.h"
#include "../../observer.h"

class Criterion : public Development, public Observer {
    public:
<<<<<<< HEAD
        Criterion(int locationVal, const std::vector<int> costs);
        virtual ~Criterion();
=======
        Criterion(int locationVal, std::vector<int> cost = {1, 0, 0, 0, 0, 0});
>>>>>>> c10c31d83230831e48461aa589d3c39ae8f518d9
        virtual void notify() = 0;
        virtual void improve() = 0;
        virtual void distributeResources() = 0;
        virtual int getCriterionType() = 0;
};

#endif