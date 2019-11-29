#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "goal.h"

class Achievement : public Goal {
    public:
    void achieve() override;
};

#endif
