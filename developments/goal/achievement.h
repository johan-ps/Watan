#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "goal.h"

class Achievement : public Goal {
    public:
    Achievement(int locationVal);
    void achieve(Player *) override;
};

#endif
