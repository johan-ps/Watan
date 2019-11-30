#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "goal.h"

class Achievement : public Goal {

    public:
        Achievement(int locationVal, const std::vector<int> cost);
        void achieve(Player *) override;
};

#endif
