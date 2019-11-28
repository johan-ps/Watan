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

struct TileInfo {
    int location;
    int value;
    int col;
    int row;
    std::string resource;
};

class Tile {
    int location;
    int value;
    std::string resource;
    int col;
    int row;
    //Resource resource;
    //std::vector<Goal> goals;
    std::map<std::string, Criterion*> criteria;
    std::map<std::string, Tile*> neighbours;
    //Geese geese;
    //bool isOverrun;
    public:
    Tile(int location, int value, std::string resource, int col, int row);
    void printTile();
    void addNeighbour(Tile *tile, std::string dir);
    void addCriterion(Criterion *criterion, std::string dir);
    TileInfo getInfo();
};

#endif
