#include "tile.h"
#include <iostream>

Tile::Tile(int location, int value, std::string resource):
    location{location}, value{value}, resource{resource} {}

void Tile::printTile() {
    std::cout << "Tile " << value << ":\n\tLocation: " << location << "\n\tValue: " << value << "\n\tResouce: " << resource << std::endl;
}