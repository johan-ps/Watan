#ifndef __CRITERION_H__
#define __CRITERION_H__
#include "../development.h"
#include "../../observer.h"
#include "../../player/player.h"

class Criterion : public Development, public Observer {
    public:
        Criterion(int locationVal, std::vector<int> cost = {1, 0, 0, 0, 0, 0});
        virtual void notify() = 0;
        virtual void complete(Player *player, bool init) = 0;
        virtual void improve() = 0;
        virtual void distributeResources() = 0;
        virtual int getCriterionType() = 0;
};

#endif