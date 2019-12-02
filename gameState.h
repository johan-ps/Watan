#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
#include <memory>

class Player;

struct GameState {
    int curTurn;
    std::vector<std::unique_ptr<Player>> players;
    std::vector<int> values;
    std::vector<int> resourceTypes;
};

#endif
