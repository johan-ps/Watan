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
    public:
    TextDisplay();
    void notify(int location, char type, std::string player);// override;
    void drawBoard();
    friend class hexagon;
};

#endif
