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

//notify appropriate tiles with the given dice value
void Board::notify(int diceVal) {
    for (auto &n : tiles) {
        if (n->getInfo().value == diceVal) {

        }
    }
}

void Board::initTiles() {
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
}

void Board::initCriteria() {
    //create 54 criterion objects
    for (int i = 0; i < 54; i++) {
        criteria.emplace_back(new Assignment{i});
    }

    //init first 3 rows of criteria
    int count = 0;
    std::string dir[6] = {"NW", "NE", "W", "E", "SW", "SE"};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            tiles.at(i)->addCriterion(criteria.at(count), dir[j]);
            count++;
        }
    }

    //init rows 4 - 9 of criteria
    int tileC = 3;
    for (int i = 0; i < 3; i++) {
        // std::cout << "TileC: " << tileC << std::endl;
        for (int j = 0; j < 2; j++) {
            for (int k = tileC; k < tileC + 3; k++) {
                for (int l = 2; l < 4; l++) {
                    //std::cout << "TileC: " << tileC << std::endl;
                    tiles.at(k)->addCriterion(criteria.at(count), dir[l + j*2]);
                    count++;
                }
            }
        }
        tileC += 5;
    }
    tileC -= 2;

    //init rows 10 - 11 of criteria
    for (int i = tileC; i < tileC + 3; i++) {
        for (int j = 4; j < 6; j++) {
            tiles.at(i)->addCriterion(criteria.at(count), dir[j]);
            count++;
        }
    }

    //assign to neighbours
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 6; j++) {
            std::string direction;
            Criterion *criteriaTemp;
            try {
                direction = dir[j]; //direction of the criterion from the current tile
                criteriaTemp = tiles.at(i)->getInfo().criteria.at(direction); //pointer to the criteria at direction <direction>
                std::string *tileDir = findNeighbourByCriteria(direction); //array of possible neighbour tiles to add criteriaTemp to
                for (int k = 0; k < 2; k++) {
                    try {
                        Tile *tileTemp = tiles.at(i)->getInfo().neighbours.at(tileDir[k]); //possible neighbour tile
                        std::map<std::string, Criterion*> criteriaMap = tileTemp->getInfo().criteria;
                        std::string oppositeDir = getOppositeDirection(tileDir[k], direction);
                        std::map<std::string, Criterion*>::iterator it;
                        it = criteriaMap.find(oppositeDir);
                        if (it == criteriaMap.end()) {
                            tileTemp->addCriterion(criteriaTemp, oppositeDir);
                        }
                    } catch (std::out_of_range) {
                        //do nothing
                    }
                }
            } catch (std::out_of_range) {
                //do nothing
            }
        }
    }
}

void Board::initGoals() {
    for (int i = 0; i < 72; i++) {
        goals.emplace_back(new Achievement{i});
    }

    
}


//initialize board
void Board::init(int boardSize) {
    tileCount = boardSize;

    initTiles();
    initCriteria();
    initGoals();
    
    td = new TextDisplay();
}

std::string Board::getOppositeDirection(std::string dirTile, std::string dirCriterion) {
    if (dirTile == "N") {
        if (dirCriterion == "NE") {
            return "SE";
        } else {
            return "SW";
        }
    } else if (dirTile == "NE") {
        if (dirCriterion == "NE") {
            return "W";
        } else {
            return "SW";
        }
    } else if (dirTile == "SE") {
        if (dirCriterion == "SE") {
            return "W";
        } else {
            return "NW";
        }
    } else if (dirTile == "S") {
        if (dirCriterion == "SE") {
            return "NE";
        } else {
            return "NW";
        }
    } else if (dirTile == "SW") {
        if (dirCriterion == "SW") {
            return "E";
        } else {
            return "NE";
        }
    } else {
        if (dirCriterion == "NW") {
            return "E";
        } else {
            return "SE";
        }
    }
}

std::string *Board::findNeighbourByCriteria(std::string criterionDir) {
    //std::string dir[6] = {"NW", "NE", "E", "W", "SW", "SE"};
    std::string *tileDir = new std::string[2];
    if (criterionDir == "NW") {
        tileDir[0] = "N";
        tileDir[1] = "NW";
    } else if (criterionDir == "NE") {
        tileDir[0] = "N";
        tileDir[1] = "NE";
    } else if (criterionDir == "E") {
        tileDir[0] = "NE";
        tileDir[1] = "SE";
    } else if (criterionDir == "W") {
        tileDir[0] = "NW";
        tileDir[1] = "SW";
    } else if (criterionDir == "SW") {
        tileDir[0] = "S";
        tileDir[1] = "SW";
    } else {
        tileDir[0] = "S";
        tileDir[1] = "SE";
    }
    return tileDir;
}

void Board::drawBoard() {
    // for (int i = 0; i < 19; i++) {
    //     tiles.at(i)->printTile();
    // }
    td->drawBoard();
}
