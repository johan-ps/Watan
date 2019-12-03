#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
#include <memory>
#include <algorithm>

class Player;

struct GameState {
    int curTurn;
    int gooseTile;
    std::vector<std::unique_ptr<Player>> players;
    std::vector<std::string> values;
    std::vector<std::string> resourceTypes;
};

#endif
