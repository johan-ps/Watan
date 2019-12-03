#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
#include <memory>
#include <algorithm>
#include "resources.h"

class Player;

class Geese;

struct GameState {
    int curTurn;
    int gooseTile = 5; // REMOVE THIS DEFAULT VALUE
    std::vector<std::unique_ptr<Player>> players;
    std::vector<int> values;
    std::vector<Resource> resourceTypes;
    Geese* geese;
};

#endif





