#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "goal.h"
//#include "../../player/player.h"

class Achievement : public Goal {
    public:
        Achievement(int locationVal, std::vector<int> cost = { 0, 0, 0, 1, 1});
        void achieve(Player *, bool init = false) override;
};

#endif
