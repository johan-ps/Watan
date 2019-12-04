#ifndef GOAL_H
#define GOAL_H

#include "../development.h"
#include <vector>

class Goal : public Development {
    public:
        Goal(int locationVal, int criteriaVal, const std::vector<int> cost);
        virtual void achieve(Player *player, bool init = false) = 0;
        virtual ~Goal() = 0;
};

#endif





