#ifndef __CRITERION_H__
#define __CRITERION_H__
#include "../development.h"
#include "../../observer.h"
#include "../../player/player.h"

class Criterion : public Development, public Observer {

    public:
        Criterion(int locationVal, std::vector<int> cost);
        virtual void notify() = 0;
        virtual void complete(Player* player, bool init = false) = 0;
        virtual void improve(Player* player, bool init = false) = 0;
        virtual void distributeResources(std::string) = 0;
};

#endif