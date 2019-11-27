#include "tile.h"
#include "textDisplay.h"
#include "./assets/developments/criteria/assignment.h"
#include <vector>

//class Tile;
//class TextDisplay;

class Board {
    std::vector<Tile *> tiles;
    std::vector<std::vector<Criterion *>> criteria;
    TextDisplay *td = nullptr;
    int tileCount;

public:
    void init(int boardSize);
    void drawBoard();
};