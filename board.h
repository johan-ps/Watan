#ifndef BOARD_H
#define BOARD_H



//#include "tile.h"
//#include "resources.h"
//#include "textDisplay.h"
//criterion.h
    //development.h
        //player.h
        //vector
    //observer.h
    //player.h
//tile.h
    //criterion.h
    //achievement.h
        //goal.h
            //development.h
    //observer.h
    //subject.h
    //vector
    //string
    //map
//player.h
    //vector
    //string
//vector

#include "./developments/goal/achievement.h"
#include "./developments/criteria/assignment.h"
//goal.h
#include "tile.h"
#include "./player/player.h"
#include "textDisplay.h"
#include <vector>
#include "observer.h"
#include "subject.h"
#include <stdlib.h>

//class Tile;
class Resource;
class TextDisplay;

class Board : public Subject, public Observer {
    std::vector<Tile*> tiles;
    std::vector<Criterion*> criteria;
    std::vector<Goal*> goals;
    std::vector<int> values;
    std::vector<Resource> resources;
    TextDisplay *td = nullptr;
    int tileCount;

    //private methods
    void initTiles();
    void setCriteria();
    void setGoals();
    int findTile(int col, int row);
    std::string *findNeighbourByCriteria(std::string criterionDir);
    std::string findNeighbourByGoal(std::string goalDir);
    std::string getOppositeDirection(std::string dirTile, std::string dirCriterion);

public:
    void notify(int diceVal);// override;
    void setTextDisplay(TextDisplay *td);
    void setValues(std::vector<int> values);
    void init(int boardSize);
    void drawBoard();
    void completeCriteria(int loc, Player *player, bool init);
    void improveCriteria(int loc, Player *player);
    void achieveGoal(int loc, Player *player, bool init);
    void initValues(std::vector<int> values);
    void initResources(std::vector<Resource> resources);
    void initCriteria(std::vector<Criterion*> criteriaOwned);
    void initGoals(std::vector<Goal*> goalsOwned);
    std::vector<std::string> getCriteria();
    std::vector<std::string> getGoals();
    ~Board();
};

#endif
