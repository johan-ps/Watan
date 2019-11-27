#include "board.h"
#include <string>
#include <iostream>

void Board::init(int boardSize) {
    tileCount = boardSize;
    int values[19] = {3, 10, 5, 4, 0, 10, 11, 3, 8, 2, 6, 8, 12, 5, 11, 4, 6, 9, 9};
    int counter = 0, width[9] = {1, 2, 3, 2, 3, 2, 3, 2, 1};

    for (int i = 0; i < boardSize; i++) {
        tiles.emplace_back(new Tile(i, values[i], std::string("CAFFEINE")));
    }
    td = new TextDisplay();
    for (int i = 0; i < 9; i++) {
        std::vector<Criterion *> temp;
        for (int j = 0; j < width[i]; j++) {
            temp.emplace_back(new Assignment(counter));
            counter++;
        }
        criteria.emplace_back(temp);
    }
}

void Board::drawBoard() {
    for (int i = 0; i < tileCount; i++) {
        tiles.at(i)->printTile();
    }
}
