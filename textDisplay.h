#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include <string>
#include <vector>
#include "hexagon.h"

class TextDisplay : public Observer {
    //std::vector<std::vector<char>> display;
    std::vector<std::string> criteria;
    std::vector<std::string> goals;
    std::vector<std::string> values;
    std::vector<std::string> resources;
    public:
    TextDisplay(std::vector<std::string> resources, std::vector<std::string> tileValues);
    void notify(int location, char type, std::string player);// override;
    void drawBoard();
    friend class hexagon;
};

#endif
