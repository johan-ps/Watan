#include "hexagon.h"
#include <iostream>

Hexagon::Hexagon(std::string resource, std::vector<std::string> criteria, std::vector<std::string> goals) {
    resource = resource;
    this->criteria = criteria;
    this->goals = goals;
    int diff = 11 - resource.length();
    for (int i = 0; i < diff; i++) {
        resourceSpace += " ";
    }
    hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
    hexagon[1] = "/            \\";
    hexagon[2] = goals.at(countG) + space[6] + format(temp) + space[5] + goals.at(countG + 1);
    hexagon[3] = "/" + space[5] + resource + resourceSpace + "\\";
    hexagon[4] = "|" + criteria.at(countC) + "|" + space[7] + format(temp) + space[7] + "|" + criteria.at(countC + 1) + "|";
    hexagon[5] = "\\                /";
    hexagon[6] = goals.at(countG) + space[7] + space[6] + goals.at(countG + 1);
    hexagon[7] = "\\            /";
    hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
    hexagon[9] = "--" + goals.at(countG) + "--";

    hex[0] = space[6] + format(temp) + space[5]; //just location
    hex[1] = space[5] + resource + resourceSpace; //just resource
    hex[2] = space[7] + format(temp) + space[7]; //just value
}

std::string Hexagon::format(int x) {
    if (x < 10) {
        return (" " + std::to_string(x));
    } else {
        return (std::to_string(x));
    }
}

void Hexagon::setHexagon(int c, int g) {
    countC += c;
    countG += g;

    if (countC + 1 > criteria.size()) {
        return;
    } else if (countG + 1 > goals.size()) {
        return;
    } else if (countG + 2 > goals.size()) {
        hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[3] = "/" + space[5] + resource + resourceSpace + "\\";
        hexagon[4] = "|" + criteria.at(countC) + "|" + space[7] + format(temp) + space[7] + "|" + format(countC + 1) + "|";
        hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[9] = "--" + goals.at(countG) + "--";
    } else {
        hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[2] = goals.at(countG) + space[6] + format(temp) + space[5] + goals.at(countG + 1);
        hexagon[3] = "/" + space[5] + resource + resourceSpace + "\\";
        hexagon[4] = "|" + criteria.at(countC) + "|" + space[7] + format(temp) + space[7] + "|" + format(countC + 1) + "|";
        hexagon[6] = goals.at(countG) + space[7] + space[6] + goals.at(countG + 1);
        hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[9] = "--" + goals.at(countG) + "--";
    }
}

void Hexagon::setHex(int c, int g) {
    temp = 0;
    hex[0] = space[6] + format(temp) + space[5];
    hex[1] = space[5] + resource + resourceSpace;
    hex[2] = space[7] + format(temp) + space[7];
}

std::string Hexagon::getTab(int index) {
    return tab[index];
}

std::string Hexagon::getSpace(int index) {
    return space[index];
}

std::string Hexagon::getHexagon(int x) {
    std::string temp = this->hexagon[x];
    if (x == 0 || x == 8) {
        setHexagon(iteratorC + 2, iteratorG + 1);
    } else if (x == 4) {
        setHexagon(iteratorC + 2, iteratorG);
    } else if (x == 2 || x == 6) {
        setHexagon(iteratorC, iteratorG + 2);
    } else if (x == 9) {
        setHexagon(iteratorC, iteratorG + 1);
    }
    return temp;
}

std::string *Hexagon::getHex(int x) {
    return hex;
}