#ifndef TILE_H
#define TILE_H

// #include "resource.h"
// #include "goal.h"
#include "./developments/criteria/criterion.h"
// #include "geese.h"
#include <vector>
#include <string>
#include <map>

//class Goal;
//class Criterion;
//class Geese;
//class Resource;

class Tile {
    int location;
    int value;
    std::string resource;
    //Resource resource;
    //std::vector<Goal> goals;
    std::map<std::string, Criterion*> criteria;
    std::map<std::string, Tile*> neighbours;
    //Geese geese;
    //bool isOverrun;
    public:
    Tile(int location, int value, std::string resource);
    void printTile();
};

#endif
