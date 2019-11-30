#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "goal.h"

class Achievement : public Goal {
    public:
        Achievement(int locationVal, std::vector<int> cost = {1, 0, 0, 0, 0, 0});
        void achieve(Player *) override;
};

#endif
