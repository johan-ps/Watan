#include "board.h"
#include <string>
#include <iostream>


//return the location of a tile given the column and row
int Board::findTile(int col, int row) {
    for (int i = 0; i < tileCount; i++) {
        if (col == tiles.at(i)->getInfo().col && row == tiles.at(i)->getInfo().row) {
            return tiles.at(i)->getInfo().location;
        }
    }
    return -1;
}

//find the direction of tileB from tileA given appropriate col and row values
std::string findDir(int colA, int rowA, int colB, int rowB) {
    if (rowA == rowB) {
        if (colA - 2 == colB) {
            return "N";
        } else if (colA + 2 == colB) {
            return "S";
        }
    } else if (rowA - 1 == rowB) {
        if (colA + 1 == colB) {
            return "SW";
        } else if (colA - 1 == colB) {
            return "NW";
        }
    } else if (rowA + 1 == rowB) {
        if (colA - 1 == colB) {
            return "NE";
        } else if (colA + 1 == colB) {
            return "SE";
        }
    }
    return "N";
}


//initialize board
void Board::init(int boardSize) {
    tileCount = boardSize;
    int values[19] = {3, 10, 5, 4, 0, 10, 11, 3, 8, 2, 6, 8, 12, 5, 11, 4, 6, 9, 9};
    int counter = 0, width[9] = {1, 2, 3, 2, 3, 2, 3, 2, 1};

    //fill board with tiles
    int col = 0, row = 2;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < width[i]; j++) {
            tiles.emplace_back(new Tile(counter, values[counter], std::string("CAFFEINE"), col, row));
            row += 2;
            counter++;
        }
        ++col;
        row = 3 - width[i + 1];
    }

    //add appropriate neighbours to tiles
    for (int i = 0; i < 19; i++) {
        TileInfo cur = tiles.at(i)->getInfo();        
        
        for (int col = -2; col < 3; col++) {
            if (col == 0) {
                continue;
            }
            for (int row = -1; row < 2; row++) {
                int loc = findTile(cur.col + col, cur.row + row);
                if (loc == -1) {
                    continue;
                } else {
                    TileInfo cur = tiles.at(i)->getInfo();
                    TileInfo other = tiles.at(loc)->getInfo();
                    tiles.at(i)->addNeighbour(tiles.at(loc), findDir(cur.col, cur.row, other.col, other.row));
                }
            }
        }
    }

    // N: Tile(col - 2, row)
    // NE: Tile(col - 1, row + 1)
    // SE: Tile(col + 1, row + 1)
    // S: Tile(col + 2, row)
    // SW: Tile(col + 1, row - 1)
    // NW: Tile(col - 1, row - 1)

    for (int i = 0; i < 54; i++) {
        criteria.emplace_back(new Assignment {i});
    }
    int count = 0;
    std::string dir[6] = {"NW", "NE", "E", "SE", "SW", "W"};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            tiles.at(i)->addCriterion(criteria.at(count), dir[j]);
            count++;
        }
    }
    // for (int i = 3; i < 6; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         tiles.at(i)->addCriterion(criteria.at(count), dir[j]);
    //         count++;
    //     }
    // }
    
    //td = new TextDisplay();
    // for (int i = 0; i < 9; i++) {
    //     std::vector<Criterion *> temp;
    //     for (int j = 0; j < width[i]; j++) {
    //         temp.emplace_back(new Assignment(counter));
    //         counter++;
    //     }
    //     criteria.emplace_back(temp);
    // }
}

void Board::drawBoard() {
    for (int i = 0; i < 6; i++) {
        tiles.at(i)->printTile();
    }
}
