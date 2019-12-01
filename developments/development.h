#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

//#include "../player/player.h"
#include <vector>
//#include <map>


class Player;
//class Resource;


class Development {
    int locationVal;
    const std::vector<int> cost;
    Player *player;
    //bool isSet;

    protected:
        void setDevelopment(Player *);
        void setOwner(Player *);

    public:
        Development(int locationVal, const std::vector<int> cost);
        virtual ~Development() = 0;
        const std::vector<int> getCost();
        int getLocationVal();
        bool isSet();
};

#endif