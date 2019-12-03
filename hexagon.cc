#include "hexagon.h"
#include <iostream>

Hexagon::Hexagon(std::vector<Resource> resourceTypes, std::vector<std::string> criteriaVal, std::vector<std::string> goalsVal, std::vector<std::string> val, int gooseTile):
    resources{resourceTypes}, criteria{criteriaVal}, goals{goalsVal}, values{val}, gooseTile{gooseTile} {

    // for (int i = 0; i < criteria.size(); i++) {
    //     std::cerr << i << " : " << criteria.at(i) << std::endl;
    // }   
    
    hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
    hexagon[1] = "/            \\";
    hexagon[2] = goals.at(countG) + space[6] +  format(locCount) + space[5] + goals.at(countG + 1);
    hexagon[3] = "/" + space[5] + resources.at(rCount).getName() + resourceSpace(resources.at(rCount).getName()) + "\\";
    hexagon[4] = "|" + criteria.at(countC) + "|" + space[7] + values.at(valCount) + space[7] + "|" + criteria.at(countC + 1) + "|";
    hexagon[5] = "\\" + space[5] + goose + space[6] + "/";
    hexagon[6] = goals.at(countG) + space[7] + space[6] + goals.at(countG + 1);
    hexagon[7] = "\\            /";
    hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
    hexagon[9] = "--" + goals.at(countG) + "--";

    hex[0] = space[6] + format(locCount) + space[5]; //just location
    hex[1] = space[5] + resources.at(rCount).getName() + resourceSpace(resources.at(rCount).getName()); //just resource
    hex[2] = space[7] + values.at(valCount) + space[7]; //just value
    hex[3] = space[5] + goose + space[6];
}

std::string Hexagon::resourceSpace(std::string resource) {
    int diff = 11 - resource.length();
    std::string resourceSpaces = "";
    for (int i = 0; i < diff; i++) {
        resourceSpaces += " ";
    }
    return resourceSpaces;
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

    
    //std::cerr << hexagon[4] << std::endl;

    if (countC + 1 > criteria.size()) {
        return;
    } else if (valCount + 1 > values.size() || rCount + 1 > resources.size() || locCount + 1 > values.size()) {
        if (countG + 1 > goals.size()) {
            return;
        } else if (countG + 2 > goals.size()) {
            hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
            hexagon[5] = "\\" + space[5] + goose + space[6] + "/";
            hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
            hexagon[9] = "--" + goals.at(countG) + "--";
        } else {
            hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
            hexagon[5] = "\\" + space[5] + goose + space[6] + "/";
            hexagon[6] = goals.at(countG) + space[7] + space[6] + goals.at(countG + 1);
            hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
            hexagon[9] = "--" + goals.at(countG) + "--";
        }
    } else if (countG + 1 > goals.size()) {
        return;
    } else if (countG + 2 > goals.size()) {
        hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[3] = "/" + space[5] + resources.at(rCount).getName() + resourceSpace(resources.at(rCount).getName()) + "\\";
        hexagon[4] = "|" + criteria.at(countC) + "|" + space[7] + values.at(valCount) + space[7] + "|" + criteria.at(countC + 1) + "|";
        hexagon[5] = "\\" + space[5] + goose + space[6] + "/";
        hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[9] = "--" + goals.at(countG) + "--";
    } else {
        hexagon[0] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[2] = goals.at(countG) + space[6] + format(locCount) + space[5] + goals.at(countG + 1);
        hexagon[3] = "/" + space[5] + resources.at(rCount).getName() + resourceSpace(resources.at(rCount).getName()) + "\\";
        hexagon[4] = "|" + criteria.at(countC) + "|" + space[7] + values.at(valCount) + space[7] + "|" + criteria.at(countC + 1) + "|";
        hexagon[5] = "\\" + space[5] + goose + space[6] + "/";
        hexagon[6] = goals.at(countG) + space[7] + space[6] + goals.at(countG + 1);
        hexagon[8] = "|" + criteria.at(countC) + "|--" + goals.at(countG) + "--|" + criteria.at(countC + 1) + "|";
        hexagon[9] = "--" + goals.at(countG) + "--";
    }
}

void Hexagon::setHex(int c, int g) {
    if (valCount + 1 > values.size() || rCount + 1 > values.size() || locCount + 1 > values.size()) {
        return;
    }
    hex[0] = space[6] + format(locCount) + space[5]; //just location
    hex[1] = space[5] + resources.at(rCount).getName() + resourceSpace(resources.at(rCount).getName()); //just resource
    hex[2] = space[7] + values.at(valCount) + space[7]; //just value
    hex[3] = space[5] + goose + space[6]; //just goose
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
        if (valCount < 18) {
            valCount++;
        }
        setHexagon(iteratorC + 2, iteratorG);
        setHex(iteratorC + 2, iteratorG);
    } else if (x == 2) {
        if (locCount < 18) {
            locCount++;
        }
        setHexagon(iteratorC, iteratorG + 2);
        setHex(iteratorC, iteratorG + 2);
    } else if (x == 3) {
        if (rCount < 18) {
            rCount++;
        }
        setHexagon(iteratorC, iteratorG);
        setHex(iteratorC, iteratorG);
    } else if (x == 5) {
        if (gooseCount < 18) {
            gooseCount++;
        }
        if (gooseCount == gooseTile) {
            goose = "GEESE";
        } else {
            goose = "     ";
        }
        setHexagon(iteratorC, iteratorG);
        setHex(iteratorC, iteratorG);
        return this->hexagon[5];
    } else if (x == 6) {
        setHexagon(iteratorC, iteratorG + 2);
    } else if (x == 9) {
        setHexagon(iteratorC, iteratorG + 1);
    }
    return temp;
}

std::string Hexagon::getHex(int x) {
    std::string temp = this->hex[x];
    
    if (x == 0) {
        if (locCount < 18) {
            locCount++;
        }
        setHexagon(iteratorC, iteratorG);
        setHex(iteratorC, iteratorG);
    } else if (x == 1) {
        if (rCount < 18) {
            rCount++;
        }
        setHexagon(iteratorC, iteratorG);
        setHex(iteratorC, iteratorG);
    } else if (x == 2) {
        if (valCount < 18) {
            valCount++;
        }
        setHexagon(iteratorC, iteratorG);
        setHex(iteratorC, iteratorG);
    } else if (x == 3) {
        if (gooseCount < 18) {
            gooseCount++;
        }
        if (gooseCount == gooseTile) {
            goose = "GEESE";
        } else {
            goose = "     ";
        }
        setHexagon(iteratorC, iteratorG);
        setHex(iteratorC, iteratorG);
        return this->hex[3];
    }
    return temp;
}





