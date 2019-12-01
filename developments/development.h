#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include "../player/player.h"
#include <vector>
//#include <map>


//class Player;
//class Resource;

class Development {
    int locationVal;
    int criteriaVal;
    const std::vector<int> cost;
    Player *player;

    void setOwner(Player *, int);

    protected:
        void setDevelopment(Player *, int);

    public:
        Development(int locationVal, const std::vector<int> cost);
        virtual ~Development() = 0;
        const std::vector<int> getCost();
        int getLocationVal();
        int getCriteriaVal();
        bool isSet();
        Player * getOwner();
};

#endif