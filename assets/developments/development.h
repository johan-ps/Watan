<<<<<<< HEAD
#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

//#include <map>

//class Resource;
//class Player;

class Development : public Observer {
    //std::map<Resource><int> cost;
    //Player player;
    public:
    virtual ~Development() = 0;
};

=======
#ifndef __DEVElOP_H__
#define __DEVELOP_H__
#include <map>
#include "/u9/sdgrecco/cs246/a5FinalProject/Watan/assets/resources/resources.h"

class Development {
    std::map<Resource, int> cost;
    Player *player;
};
>>>>>>> stageOneCriterion
#endif