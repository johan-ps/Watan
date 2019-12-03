#ifndef HEXAGON_H
#define HEXAGON_H

#include <string>
#include <vector>

class Hexagon {
    unsigned int locCount = 0;
    int gooseCount = 0;
    unsigned int valCount = 0;
    unsigned int rCount = 0;
    int iteratorC = 0;
    int iteratorG = 0;
    unsigned int countC = 0;
    unsigned int countG = 0;
    std::string goose = "     ";
    // space = {"0 spaces", "1 space", "2 space", "3 spaces", "4 spaces", "5 spaces", "6 spaces", "7 spaces",
    //          "8 spaces", "9 spaces", "10 spaces", "11 spaces"}
    std::string space[12] = {"", " ", "  ", "   ", "    ", "     ", "      ", "       ", "        ", "         ", "          ", "           "};
    std::vector<std::string> resources;
    std::vector<std::string> criteria;
    std::vector<std::string> goals;
    std::vector<std::string> values;
    int gooseTile;
    
    //tab = {"0 spaces", "15 spaces", "30 spaces"}
    std::string tab[3] = {"", "               ", "                              "};
    std::string hexagon[10];
    std::string hex[4];

    public:
    Hexagon(std::vector<std::string> resources, std::vector<std::string> criteria, std::vector<std::string> goals, std::vector<std::string> values, int gooseTile = -1);
    std::string getTab(int index);
    std::string getSpace(int index);
    std::string format(int x);
    void setHexagon(int c, int g);
    void setHex(int c, int g);
    std::string getHexagon(int x);
    std::string getHex(int x);
    std::string resourceSpace(std::string resource);
};

#endif
