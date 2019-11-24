//#include "tile.h"
#include <vector>

class Tile;
class TextDisplay;

class Board {
    std::vector<Tile> tiles;
    TextDisplay td = nullptr;
    public:
    drawBoard();
};