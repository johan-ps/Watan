#ifndef __CRITERION_H__
#define __CRITERION_H__
#include "../development.h"
#include "../../observer.h"
//#include "../../player/player.h"
#include "../../resources.h"
#include <string>

class Player;

class Criterion : public Development, public Observer {

    public:
        Criterion(int locationVal, std::vector<int> cost);
        virtual void notify() = 0;
        virtual void complete(Player* player, bool init = false) = 0;
        virtual void improve(Player* player, bool init = false) = 0;
        virtual void distributeResources(Resource resource) = 0;
        virtual ~Criterion() = 0;
};

#endif