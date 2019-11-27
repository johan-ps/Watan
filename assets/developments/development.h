#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

//#include <map>

//class Resource;
//class Player;

class Development {
    //std::map<Resource><int> cost;
    //Player player;
    int locationVal;
    public:
    int getLocationVal();
    virtual ~Development() = 0;
};

#endif