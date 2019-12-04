#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "goal.h"
#include "../../player/player.h"
#include "../../exception.h"

class Achievement : public Goal {
    public:
        Achievement(int locationVal, int criteriaVal = 0, std::vector<int> cost = { 0, 0, 0, 1, 1});
        void achieve(Player *player, bool init = false) override;
        ~Achievement();
};

#endif





