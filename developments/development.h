#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H
#include "../observer.h"

//#include <map>

//#include "../player/player.h"

class Player;
//class Resource;


class Development : public Observer {
    //std::map<Resource><int> cost;
    Player *player;
    int locationVal;

    protected:
        void setOwner(Player *);

    public:
        Development(int locationVal);
        int getLocationVal();
        virtual ~Development() = 0;
};

#endif