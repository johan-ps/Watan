#include "textDisplay.h"
#include "hexagon.h"
#include <iostream>
#include <string>

TextDisplay::TextDisplay(std::vector<std::string> resources, std::vector<std::string> tileValues, std::vector<std::string> criteria, std::vector<std::string> goals, int gooseTile):
    resources{resources}, values{tileValues}, criteria{criteria}, goals{goals}, gooseTile{gooseTile} {}
    
TextDisplay::TextDisplay(std::vector<std::string> resources, std::vector<std::string> tileValues, int gooseTile):
    resources{resources}, values{tileValues}, gooseTile{gooseTile} {
        for (int i = 0; i < 54; i++) {
            criteria.emplace_back(i < 10 ? " " + std::to_string(i) : std::to_string(i));
        }
        for (int i = 0; i < 72; i++) {
            goals.emplace_back(i < 10 ? " " + std::to_string(i) : std::to_string(i));
        }
    }

void TextDisplay::drawBoard() {
    Hexagon hexa {resources, criteria, goals, values, gooseTile};

    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(0) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(1) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(2) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(3) << std::endl;

    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(0) << hexa.getHex(2) << hexa.getHexagon(0) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(1) << hexa.getSpace(11) << hexa.getSpace(5) << hexa.getHexagon(1) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(2) << hexa.getSpace(10) << hexa.getSpace(3) << hexa.getHexagon(2) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(3) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(3) << std::endl;

    for (int i = 0; i < 3; i++) {
        //std::cout << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(0) << hexa.getHex(2) << hexa.getHexagon(0) << hexa.getHex(2) << hexa.getHexagon(0) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(1) << hexa.getHex(3) << hexa.getHexagon(1) << hexa.getHex(3) << hexa.getHexagon(1) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(2) << hexa.getSpace(10) + hexa.getSpace(3) << hexa.getHexagon(2) << hexa.getSpace(10) + hexa.getSpace(3) << hexa.getHexagon(2) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(3) << hexa.getSpace(9) + hexa.getSpace(3) << hexa.getHexagon(3) << hexa.getSpace(9) + hexa.getSpace(3) << hexa.getHexagon(3) << std::endl;
        
        //std::cout << std::endl;
        std::cout << hexa.getTab(0) << hexa.getHexagon(4) << hexa.getHexagon(9) << hexa.getHexagon(4) << hexa.getHexagon(9) << hexa.getHexagon(4) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(5) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(5) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(5) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(6) << hexa.getHex(0) << hexa.getHexagon(6) << hexa.getHex(0) << hexa.getHexagon(6) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(7) << hexa.getHex(1) << hexa.getHexagon(7) << hexa.getHex(1) << hexa.getHexagon(7) << std::endl;
    }
    std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(0) << hexa.getHex(2) << hexa.getHexagon(0) << hexa.getHex(2) << hexa.getHexagon(0) << std::endl;

    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(5) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(5) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(6) << hexa.getHex(0) << hexa.getHexagon(6) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(7) << hexa.getHex(1) << hexa.getHexagon(7) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(8) << hexa.getHex(2) << hexa.getHexagon(8) << std::endl;

    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(5) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(6) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(7) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(8) << std::endl;
}

void TextDisplay::notify(int location, char type, std::string player) {
    if (type == 'c') {
        criteria.at(location) = player;
    } else if (type == 'g') {
        goals.at(location) = player;
    } else if (type == 'r') {
        gooseTile = location;
    }
}
