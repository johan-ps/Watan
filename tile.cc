#include "tile.h"
#include <iostream>

Tile::Tile(int location, int value, std::string resource, int col, int row):
    location{location}, value{value}, resource{resource}, col{col}, row{row} {}

void Tile::printTile() {
    std::string dir[6] = {"N", "NE", "SE", "S", "SW", "NW"};
    std::cout << "Tile " << value << ":\n\tLocation: " << location << std::endl; //<< "\n\tValue: " << value << "\n\tResouce: " << resource;
    //std::cout << "\n\t(Col, Row): (" << col << ", " << row << ")" << std::endl;
    for (int i = 0; i < 6; i++) {
        try {
            std::cout << "\tNeighbour <" << dir[i] << "> : " << neighbours.at(dir[i])->getInfo().location << std::endl;
        } catch (std::out_of_range) {
            //do nothing
        }
        std::cout << std::endl;
    }

}

void Tile::addNeighbour(Tile *tile, std::string dir) {
    std::cout << "Called with dir: " << dir << " and Loc" << tile->getInfo().location << std::endl;
    neighbours[dir] = tile;
}

TileInfo Tile::getInfo() {
    return {
        location, value, col, row, resource
    };
}