#include "hexagon.h"

Hexagon::Hexagon(std::string resource) {
    resource = resource;
    int diff = 11 - resource.length();
    for (int i = 0; i < diff; i++) {
        resourceSpace += " ";
    }
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

    hexagon[0] = "|" + format(countC) + "|--" + format(temp) + "--|" + format(countC + 1) + "|";
    hexagon[2] = format(countG) + space[6] + format(temp) + space[5] + format(countG + 1);
    hexagon[3] = "/" + space[5] + resource + resourceSpace + "\\";
    hexagon[4] = "|" + format(countC) + "|" + space[7] + format(temp) + space[7] + "|" + format(countC + 1) + "|";
    hexagon[6] = format(countG) + space[7] + space[7] + format(countG);
    hexagon[8] = "|" + format(countC) + "|--" + format(temp) + "--|" + format(countC + 1) + "|";
}

void Hexagon::setHex(int c, int g) {
    temp = 0;
    hex[0] = space[6] + format(temp) + space[5];
    hex[1] = space[5] + resource + resourceSpace;
    hex[2] = space[7] + format(temp) + space[7];
}

std::string *Hexagon::getTab() {
    return tab;
}

std::string *Hexagon::getSpace() {
    return space;
}

std::string Hexagon::getHexagon(int x) {
    std::string temp = this->hexagon[x];
    if (x == 0 || x == 4) {
        setHexagon(iteratorC + 2, iteratorG);
    } else if (x == 8) {
        setHexagon(iteratorC + 2, iteratorG + 1);
    } else if (x == 2 || x == 6) {
        setHexagon(iteratorC, iteratorG + 2);
    }
    return temp;
}

std::string *Hexagon::getHex(int x) {
    return hex;
}