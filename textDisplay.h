#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
//#include "resources.h"
#include <string>
#include <vector>
#include "hexagon.h"

class Resource;

class TextDisplay : public Observer {
    std::vector<Resource> resources;
    std::vector<std::string> values;
    std::vector<std::string> criteria;
    std::vector<std::string> goals;
    int gooseTile;
    public:
    TextDisplay(std::vector<Resource> resources, std::vector<int> tileValues, int gooseTile = -1);
    void notify(int location, char type, std::string player = "");// override;
    void drawBoard();
    friend class hexagon;
};

#endif





