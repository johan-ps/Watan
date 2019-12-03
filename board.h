#ifndef BOARD_H
#define BOARD_H

//#include "tile.h"
#include "textDisplay.h"
#include "./developments/criteria/assignment.h"
#include "./developments/goal/achievement.h"
#include <vector>
#include "observer.h"
#include "subject.h"
#include <stdlib.h>

class Tile;
//class TextDisplay;

class Board : public Subject, public Observer {
    std::vector<Tile*> tiles;
    std::vector<Criterion*> criteria;
    std::vector<Goal*> goals;
    std::vector<int> values;
    std::vector<std::string> resources;
    //std::vector<std::vector<Criterion *>> criteria;
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
    void initResources(std::vector<std::string> resources);
    void initCriteria(std::vector<Criterion*> criteriaOwned);
    void initGoals(std::vector<Goal*> goalsOwned);
    std::vector<std::string> getCriteria();
    std::vector<std::string> getGoals();
};

#endif
