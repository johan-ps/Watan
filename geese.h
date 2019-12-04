#ifndef __GEESE_H__
#define __GEESE_H__

#include "./player/player.h"

class Tile;

class Geese {
    Tile *currentGeeseTile;

    public:
        void eatResources(Player * victim);
        Tile *getTile();
        void setCurrentGeeseTile(Tile *newGeeseTile);

};



#endif 