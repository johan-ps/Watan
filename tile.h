#ifndef TILE_H
#define TILE_H

#include "resources.h"
#include "./developments/criteria/criterion.h"
#include "./developments/goal/achievement.h"
#include "./player/player.h"

#include "observer.h"
#include "subject.h"
#include "geese.h"
#include <vector>
#include <string>
#include <map>

class Tile;

struct TileInfo {
    int location;
    int value;
    int col;
    int row;
    Resource resource;
    std::map<std::string, Criterion*> criteria;
    std::map<std::string, Goal*> goals;
    std::map<std::string, Tile*> neighbours;
};

class Tile : public Subject, public Observer {
    int location;
    int value;
    Resource resource;
    int col;
    int row;
    Geese *geese;
    TileInfo *tileInfo;
    
    std::map<std::string, Criterion*> criteria;
    std::map<std::string, Goal*> goals;
    std::map<std::string, Tile*> neighbours;


    public:
        Tile(int location, int value, Resource resource, int col, int row);

        // Getters
        bool isOverrun();
        TileInfo getInfo();
        bool checkAdjCriteria(int locationVal);
        bool checkAdjAchievements(int locationVal, std::string colour);
        bool checkAdjGoal(int locationVal, std::string colour);
        bool checkAdjTile(double spot, bool isTileA, std::string colour);
        

        // Setters
        void addNeighbour(Tile *tile, std::string dir);
        void addCriterion(Criterion *criterion, std::string dir);
        void addGoal(Goal *goal, std::string dir);
        void setGeese(Geese *incomingFlock);
        void removeGeese();

        void notify();// override;
        void printTile();

        ~Tile();
};

#endif





