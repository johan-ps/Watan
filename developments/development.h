#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include "../player/player.h"
#include <vector>
#include "../textDisplay.h"
//#include <map>


//class Player;
//class Resource;

class Development {
    int locationVal;
    int criteriaVal;
    const std::vector<int> cost;
    Player *player;

    void setOwner(Player *);

    protected:
        void setDevelopment(Player *, int);
        TextDisplay *td;

    public:
        Development(int locationVal, const std::vector<int> cost);
        virtual ~Development() = 0;
        const std::vector<int> getCost();
        int getLocationVal();
        int getCriteriaVal();
        void setCriteriaVal(int);
        void setTextDisplay(TextDisplay *td);
        bool isSet();
        Player * getOwner();
};

#endif