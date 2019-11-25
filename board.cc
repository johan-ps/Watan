#include "board.h"
#include <string>
#include <iostream>

Board::Board(int boardSize):
    tileCount{boardSize} {
        int values[19] = {3, 10, 5, 4, 0, 10, 11, 3, 8, 2, 6, 8, 12, 5, 11, 4, 6, 9, 9};

        for (int i = 0; i < boardSize; i++) {
            tiles.emplace_back(new Tile(i, values[i], std::string("CAFFEINE")));
        }
}

void Board::drawBoard() {
    for (int i = 0; i < tileCount; i++) {
        tiles.at(i)->printTile();
    }
}