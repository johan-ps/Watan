#include "tile.h"
#include <iostream>
#include <cmath>
#include <memory>

Tile::Tile(int location, int value, Resource resource, int col, int row):
    location{location}, value{value}, resource{resource}, col{col}, row{row} {}




bool Tile::isOverrun(){
    return geese; // HOPEFULLY PTR GETS CASTED TO A BOOL PROPERLY
}

TileInfo Tile::getInfo() {
    return {
        location, value, col, row, resource, criteria, goals, neighbours
    };
}

bool Tile::checkAdjCriteria(int locationVal){
    std::string cardinal[6] = {"NW", "NE", "W", "E", "SW", "SE"};
    std::string choice, adjOne, adjTwo;
    double spot;

    for(int i = 0; i < 6; ++i){
        choice = cardinal[i];

        if(locationVal == criteria[choice]->getLocationVal()){
            spot = i;
            adjOne = cardinal[(int)(fabs(spot - 1.5) - 0.5)];
            adjTwo = cardinal[(int)(-fabs(spot - 3.5) + 5.5)];

            if(criteria[adjOne]->isSet() || criteria[adjTwo]->isSet()){
                return false;
            }
        }
    }
    return true;
}

bool Tile::checkAdjAchievements(int locationVal, std::string colour){
    std::string goalCard[6] = {"N", "NW", "NE", "SW", "SE", "S"};
    std::string critCard[6] = {"NW", "NE", "W", "E", "SW", "SE"};
    std::string choice;
    double spot;

    for(int i = 0; i < 6; ++i){
        choice = critCard[i];

        if(locationVal == criteria[choice]->getLocationVal()){
            //std::cout << "made it inside: " << std::endl;
            spot = i;
            Player * adjOne = goals[goalCard[(int)(fabs(spot - 0.5) - 0.5)]]->getOwner();
            Player * adjTwo = goals[goalCard[(int)(-fabs(spot - 4.5) + 5.5)]]->getOwner();

            if(adjOne){
                //std::cout << "adjacent 1 exists: " << adjTwo->getColour() << std::endl;
                if(colour == adjOne->getColour()){
                    return true;
                }
            }
            if(adjTwo){
               // std::cout << "adjacent 2 exists: " << adjTwo->getColour() << std::endl;
                if(colour == adjTwo->getColour()){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Tile::checkAdjGoal(int locationVal, std::string colour){
    std::string critCard[6] = {"NW", "NE", "W", "E", "SW", "SE"};
    std::string goalCard[6] = {"N", "NW", "NE", "SW", "SE", "S"};
    std::string choice;
    double spot;

    for(int i = 0; i < 6; ++i){
        choice = goalCard[i];

        if(locationVal == goals[choice]->getLocationVal()){
            spot = i;
            Player * adjCritA = criteria[critCard[(int)(fabs(spot - 0.5) - 0.5)]]->getOwner();
            Player * adjCritB = criteria[critCard[(int)(-fabs(spot - 4.5) + 5.5)]]->getOwner();
            Player * adjGoalA = goals[goalCard[(int)(fabs(spot - 1.5) - 0.5)]]->getOwner();
            Player * adjGoalB = goals[goalCard[(int)(-fabs(spot - 3.5) + 5.5)]]->getOwner();
            Tile * adjTileA = neighbours[goalCard[(int)(fabs(spot - 1.5) - 0.5)]];
            Tile * adjTileB = neighbours[goalCard[(int)(-fabs(spot - 3.5) + 5.5)]];

            //Checks adjacent Criteria
            if(adjCritA && (colour == adjCritA->getColour())){
                return true;
            } else if(adjCritB && (colour == adjCritB->getColour())){
                return true;
            //Checks adjacent Goals on the same tile
            } else if(adjGoalA && (colour == adjGoalA->getColour())){
                return true;
            } else if(adjGoalB && (colour == adjGoalB->getColour())){
                return true;
            }

            //Checks adjacent Goals on adjacent Tiles
            if(adjTileA){
                if(adjTileA->checkAdjTile(spot, true, colour)) {
                    return true;
                } 
            } 
            if(adjTileB){
                if(adjTileB->checkAdjTile(spot, false, colour)) {
                    return true;
                } 
            }
        }
    }
    return false;
}

bool Tile::checkAdjTile(double spot, bool isTileA, std::string colour){
    std::string tileCard[6] = {"N", "NW", "NE", "SW", "SE", "S"};
    Player * adjGoalA;
    Player * adjGoalB;

    int x = (int) spot;
    if(isTileA){
        if(x % 5){ 
            adjGoalA = goals["S"]->getOwner();
        } else {
            adjGoalA = goals["SE"]->getOwner();
        }
        adjGoalB = goals[tileCard[(int)(-fabs(spot - 2.5) + 4.5)]]->getOwner();
    } else {
        if(x % 5){ 
            adjGoalA = goals["N"]->getOwner();
        } else {
            adjGoalA = goals["NW"]->getOwner();
        }
        adjGoalB = goals[tileCard[(int)(fabs(spot - 2.5) + 0.5)]]->getOwner();
    }

    if(adjGoalA && (colour == adjGoalA->getColour())){
        return true;
    } else if(adjGoalB && (colour == adjGoalB->getColour())){
        return true;
    }

    return false;
}





void Tile::addNeighbour(Tile *tile, std::string dir) {
    //std::cout << "Called with dir: " << dir << " and Loc" << tile->getInfo().location << std::endl;
    neighbours[dir] = tile;
}

void Tile::addCriterion(Criterion *criterion, std::string dir) {
    //std::cout << "Tile at location: " << location << ", added criteria <" << criterion->getLocationVal() << "> in dir: " << dir << std::endl;
    //std::cout << "Called with dir: " << dir << " and Loc" << criterion->getLocationVal() << std::endl;
    criteria[dir] = criterion;
}
void Tile::addGoal(Goal *goal, std::string dir) {
    goals[dir] = goal;
}

void Tile::setGeese(Geese *incomingFlock){
    geese = incomingFlock;
}


void Tile::notify() {
    for (auto &n : criteria) {
        if (n.second->getOwner()) {
            n.second->distributeResources(resource);
        }
    }
}

void Tile::printTile() {
    std::string dir[6] = {"N", "NE", "SE", "S", "SW", "NW"};
    std::cout << "Tile " << value << ":\n\tLocation: " << location << std::endl; //<< "\n\tValue: " << value << "\n\tResouce: " << resource;
    //std::cout << "\n\t(Col, Row): (" << col << ", " << row << ")" << std::endl;
    // for (int i = 0; i < 6; i++) {
    //     try {
    //         std::cout << "\tNeighbour <" << dir[i] << "> : " << neighbours.at(dir[i])->getInfo().location << std::endl;
    //     } catch (std::out_of_range) {
    //         //do nothing
    //     }
    //     std::cout << std::endl;
    // }
    // std::string dir2[6] = {"NW", "NE", "E", "SE", "SW", "W"};
    // for (int i = 0; i < 6; i++) {
    //     try {
    //         std::cout << "\tCriteria <" << dir2[i] << "> : " << criteria.at(dir2[i])->getLocationVal() << std::endl;
    //     } catch (std::out_of_range) {
    //         //do nothing
    //     } catch (...) {
    //         //do nothing
    //     }
    //     std::cout << std::endl;
    // }
    
    std::string dir3[6] = {"N", "NW", "NE", "SW", "SE", "S"};
    for (int i = 0; i < 6; i++) {
        try {
            std::cout << "\tGoal <" << dir3[i] << "> : " << goals.at(dir3[i])->getLocationVal() << std::endl;
        } catch (std::out_of_range) {
            //do nothing
        } catch (...) {
            //do nothing
        }
        std::cout << std::endl;
    }

}


Tile::~Tile() {
    // criteria.clear();
    // goals.clear();
    // neighbours.clear();
}





