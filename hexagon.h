#ifndef HEXAGON_H
#define HEXAGON_H

#include <string>

class Hexagon {
<<<<<<< HEAD
    int iteratorC = 0;
    int iteratorG = 0;
=======
    int iterator = 0;
>>>>>>> e8ca1e7f8272f9c901f3fc56f033fc81660135a0
    int countC = 0;
    int countG = 0;
    int temp = 0;
    // space = {"0 spaces", "1 space", "2 space", "3 spaces", "4 spaces", "5 spaces", "6 spaces", "7 spaces",
    //          "8 spaces", "9 spaces", "10 spaces", "11 spaces"}
    std::string space[12] = {"", " ", "  ", "   ", "    ", "     ", "      ", "       ", "        ", "         ", "          ", "           "};

    //calculate the remaining spaces after resources is printed
    std::string resource = "CAFFEINE";
    std::string resourceSpace = "";
    
    //tab = {"0 spaces", "15 spaces", "30 spaces"}
    std::string tab[3] = {"", "               ", "                              "};
    std::string hexagon[9] = {
        "|" + format(countC) + "|--" + format(countG) + "--|" + format(countC + 1) + "|",
        "/            \\",
        format(countG) + space[3] + format(temp) + space[2] + format(countG + 1),
        "/" + space[2] + resource + resourceSpace + "\\",
        "|" + format(countC) + "|" + space[4] + format(temp) + space[4] + "|" + format(countC + 1) + "|",
        "\\                /",
        format(countG) + space[4] + space[3] + format(countG),
        "\\            /",
        "|" + format(countC) + "|--" + format(countG) + "--|" + format(countC + 1) + "|"
    };

    std::string hex[3] = {
        space[6] + format(temp) + space[5], //just location
        space[5] + resource + resourceSpace, //just resource
        space[7] + format(temp) + space[7], //just value
    };

    public:
    Hexagon(std::string resource);
    std::string *getTab();
    std::string *getSpace();
    std::string format(int x);
    void setHexagon(int c, int g);
    void setHex(int c, int g);
    std::string getHexagon(int x);
    std::string *getHex(int x);
};

#endif
