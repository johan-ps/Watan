#ifndef BOARD_H
#define BOARD_H

#include "./developments/goal/achievement.h"
#include "./developments/criteria/assignment.h"
#include "tile.h"
#include "./player/player.h"
#include "textDisplay.h"
#include <vector>
#include "observer.h"
#include "subject.h"
#include "geese.h"
#include <stdlib.h>

class Resource;

class Board : public Subject, public Observer {
    std::vector<Tile*> tiles;
    std::vector<Criterion*> criteria;
    std::vector<Goal*> goals;
    std::vector<int> values;
    std::vector<Resource> resources;
    TextDisplay *td = nullptr;
    int tileCount;
    Geese *geese;

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
    void completeCriteria(int loc, Player *player, bool init = false);
    void improveCriteria(int loc, Player *player, bool init = false);
    void achieveGoal(int loc, Player *player, bool init = false);
    void initValues(std::vector<int> values);

    bool placeGeese(int tileNum);
    void setGeese(Geese *incomingFlock);
    Tile *getTileByLocation(int loc);
    void initResources(std::vector<Resource> resources);
    void initCriteria(std::vector<Criterion*> criteriaOwned);
    void initGoals(std::vector<Goal*> goalsOwned);
    std::vector<std::string> getCriteria();
    std::vector<std::string> getGoals();
    ~Board();
};

#endif





