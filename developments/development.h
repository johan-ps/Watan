#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

//#include <map>
#include <vector>

//#include "../player/player.h"

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
        int getLocationVal();
        bool isSet();
        virtual ~Development() = 0;
};

#endif