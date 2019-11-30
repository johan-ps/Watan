#include "textDisplay.h"
#include "hexagon.h"
#include <iostream>
#include <string>

TextDisplay::TextDisplay() {
    for (int i = 0; i < 54; i++) {
        criteria.emplace_back(i < 9 ? " " + std::to_string(i) : std::to_string(i));
    }
}

void TextDisplay::drawBoard() {
    Hexagon hexa {"CAFFEINE"};

    int width[9] = {1, 2, 3, 2, 3, 2, 3, 2, 1};
    int loc[19];
    for (int i = 0; i < 19; i++) {
        loc[i] = i;
    }
    // std::string criteria[54];
    // for (int i = 0; i < 54; i++) {
    //     if (i < 10) {
    //         criteria[i] = " " + std::to_string(i);
    //     } else {
    //         criteria[i] = std::to_string(i);
    //     }
    // }

    int count = 0;
    // while(count < 10) {
    //     std::cout << hexa.getHexagon()[0] << std::endl;
    //     count += 2;
    //     hexa.setHexagon(count);
    // }

    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(0) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(1) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(2) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(3) << std::endl;

    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(0) << hexa.getHex(2)[2] << hexa.getHexagon(0) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(1) << hexa.getSpace(11) << hexa.getSpace(5) << hexa.getHexagon(1) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(2) << hexa.getSpace(10) << hexa.getSpace(3) << hexa.getHexagon(2) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(3) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(3) << std::endl;

    // std::string hexagonTopRight = hexagon[0] + space[4] + temp + "  ";

    for (int i = 0; i < 3; i++) {
        std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(0) << hexa.getHex(2)[2] << hexa.getHexagon(0) << hexa.getHex(2)[2] << hexa.getHexagon(0) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(1) << hexa.getSpace(11) + hexa.getSpace(5) << hexa.getHexagon(1) << hexa.getSpace(11) + hexa.getSpace(5) << hexa.getHexagon(1) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(2) << hexa.getSpace(10) + hexa.getSpace(3) << hexa.getHexagon(2) << hexa.getSpace(10) + hexa.getSpace(3) << hexa.getHexagon(2) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(3) << hexa.getSpace(9) + hexa.getSpace(3) << hexa.getHexagon(3) << hexa.getSpace(9) + hexa.getSpace(3) << hexa.getHexagon(3) << std::endl;
        
        std::cout << hexa.getTab(0) << hexa.getHexagon(4) << hexa.getHexagon(9) << hexa.getHexagon(4) << hexa.getHexagon(9) << hexa.getHexagon(4) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(5) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(5) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(5) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(3) << hexa.getHexagon(6) << hexa.getHex(0)[0] << hexa.getHexagon(6) << hexa.getHex(0)[0] << hexa.getHexagon(6) << std::endl;
        std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(7) << hexa.getHex(1)[1] << hexa.getHexagon(7) << hexa.getHex(1)[1] << hexa.getHexagon(7) << std::endl;
    }
    std::cout << hexa.getTab(0) << hexa.getSpace(5) << hexa.getHexagon(0) << hexa.getHex(2)[2] << hexa.getHexagon(0) << hexa.getHex(2)[2] << hexa.getHexagon(0) << std::endl;

    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(5) << hexa.getSpace(9) << hexa.getSpace(3) << hexa.getHexagon(5) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(3) << hexa.getHexagon(6) << hexa.getHex(0)[0] << hexa.getHexagon(6) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(7) << hexa.getHex(1)[1] << hexa.getHexagon(7) << std::endl;
    std::cout << hexa.getTab(1) << hexa.getSpace(5) << hexa.getHexagon(8) << hexa.getHex(2)[2] << hexa.getHexagon(8) << std::endl;

    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(5) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(3) << hexa.getHexagon(6) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(7) << std::endl;
    std::cout << hexa.getTab(2) << hexa.getSpace(5) << hexa.getHexagon(8) << std::endl;

    // std::cout << tab[2] << hexagon[5] << std::endl;
    // std::cout << tab[2] << hexagon[6] << std::endl;
    // std::cout << tab[2] << hexagon[7] << std::endl;
    // std::cout << tab[2] << hexagon[8] << std::endl;



}

void TextDisplay::notify(int location, char type, std::string player) {
    if (type == 'c') {
        criteria.at(location) = player;
    }
}

void TextDisplaydrawBoard() {
    std::string resource = "CAFFEINE";

    // space = {"3 spaces", "4 spaces", "5 spaces", "6 spaces", "7 spaces"}
    std::string space[5] = {"   ", "    ", "     ", "      ", "       "};

    //calculate the remaining spaces after resources is printed
    int diff = 11 - resource.length();
    std::string resourceSpace = "";
    for (int i = 0; i < diff; i++) {
        resourceSpace += " ";
    }
    
    //tab = {"0 spaces", "15 spaces", "30 spaces"}
    std::string tab[3] = {"", "               ", "                              "};

    std::string temp = " 0";

    std::string hexagon[9] = {
        space[2] + "|" + temp + "|--" + temp + "--|" + temp + "|",
        space[2] + "/            \\",
        space[0] + temp + space[3] + temp + space[2] + temp,
        space[0] + "/" + space[2] + resource + resourceSpace + "\\",
        "|" + temp + "|" + space[4] + temp + space[4] + "|" + temp + "|",
        space[0] + "\\                /",
        space[0] + temp + space[4] + space[3] + temp,
        space[2] + "\\            /",
        space[2] + "|" + temp + "|--" + temp + "--|" + temp + "|"
    };

    // for (int i = 0; i < 9; i++) {
    //     std::cout << hexagon[i] << std::endl;
    // }

    std::string hexagonTopRight = hexagon[0] + space[4] + temp + "  ";

    std::cout << tab[2] << hexagon[0] << std::endl;
    std::cout << tab[2] << hexagon[1] << std::endl;
    std::cout << tab[2] << hexagon[2] << std::endl;
    std::cout << tab[2] << hexagon[3] << std::endl;

    std::cout << tab[1] << hexagonTopRight << hexagon[0] << std::endl;
    std::cout << tab[1] << hexagon[1] << "           " << hexagon[1] << std::endl;
    std::cout << tab[1] << hexagon[2] << "          " << hexagon[2] << std::endl;
    std::cout << tab[1] << hexagon[3] << "         " << hexagon[3] << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << tab[0] << hexagonTopRight << hexagonTopRight << hexagon[0] << std::endl;
        std::cout << tab[0] << hexagon[1] << "           " << hexagon[1] << "           " << hexagon[1] << std::endl;
        std::cout << tab[0] << hexagon[2] << "          " << hexagon[2] << "          " << hexagon[2] << std::endl;
        std::cout << tab[0] << hexagon[3] << "         " << hexagon[3] << "         " << hexagon[3] << std::endl;

        std::cout << tab[0] << hexagon[4] << "--" << temp << "--" << hexagon[4] << "--" << temp << "--" << hexagon[4] << std::endl;
        std::cout << tab[0] << hexagon[5] << "         " << hexagon[5] << "         " << hexagon[5] << std::endl;
        std::cout << tab[0] << space[0] << temp << "          " << hexagon[2] << "          " << hexagon[2] << "             " << temp << std::endl;
        std::cout << tab[0] << space[2] << "\\" << "         " << hexagon[3] << "         " << hexagon[3] << "            " << "/" << std::endl;
    }

    std::cout << tab[0] << hexagonTopRight << hexagonTopRight << hexagon[0] << std::endl;

    std::cout << tab[1] << hexagon[5] << "         " << hexagon[5] << std::endl;
    std::cout << tab[1] << hexagon[6] << space[3] + temp + "  " << hexagon[6] << std::endl;
    std::cout << tab[1] << hexagon[7] << space[2] + resource + resourceSpace << "\\            /" << std::endl;
    std::cout << tab[1] << hexagon[8] << space[4] << temp << "  " << hexagon[8] << std::endl;

    std::cout << tab[2] << hexagon[5] << std::endl;
    std::cout << tab[2] << hexagon[6] << std::endl;
    std::cout << tab[2] << hexagon[7] << std::endl;
    std::cout << tab[2] << hexagon[8] << std::endl;
}
