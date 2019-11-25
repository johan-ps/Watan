#include "tile.h"
#include <vector>

//class Tile;
//class TextDisplay;

class Board {
    std::vector<Tile*> tiles;
    //TextDisplay td = nullptr;
    const int tileCount;
    public:
    void drawBoard();

    Board(int boardSize);
};