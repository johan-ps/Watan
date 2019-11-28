#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "textDisplay.h"
#include "./developments/criteria/assignment.h"
#include <vector>

//class Tile;
//class TextDisplay;

class Board {
    std::vector<Tile*> tiles;
    std::vector<Criterion*> criteria;
    //std::vector<std::vector<Criterion *>> criteria;
    TextDisplay *td = nullptr;
    int tileCount;

public:
    void init(int boardSize);
    void drawBoard();
    int findTile(int col, int row);
};

#endif
