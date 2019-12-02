#include "tile.h"
#include <iostream>

Tile::Tile(int location, int value, std::string resource, int col, int row):
    location{location}, value{value}, resource{resource}, col{col}, row{row} {}

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

TileInfo Tile::getInfo() {
    return {
        location, value, col, row, resource, criteria, goals, neighbours
    };
}