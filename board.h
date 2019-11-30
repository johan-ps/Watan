#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "textDisplay.h"
#include "./developments/criteria/assignment.h"
#include "./developments/goal/achievement.h"
#include <vector>
#include "observer.h"

//class Tile;
//class TextDisplay;

class Board : public Subject, public Observer {
    std::vector<Tile*> tiles;
    std::vector<Criterion*> criteria;
    std::vector<Goal*> goals;
    //std::vector<std::vector<Criterion *>> criteria;
    TextDisplay *td = nullptr;
    int tileCount;

    //private methods
    void initTiles();
    void initCriteria();
    void initGoals();

public:
    void notify(int diceVal);// override;
    void init(int boardSize);
    void drawBoard();
    int findTile(int col, int row);
    std::string *findNeighbourByCriteria(std::string criterionDir);
    std::string getOppositeDirection(std::string dirTile, std::string dirCriterion);
};

#endif
