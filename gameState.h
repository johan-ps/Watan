#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
#include <memory>
#include <algorithm>

class Player;

class Geese;

struct GameState {
    int curTurn;
    int gooseTile;
    std::vector<std::unique_ptr<Player>> players;
    std::vector<int> values;
    std::vector<int> resourceTypes;
    Geese* geese;
};

#endif
