#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "criterion.h"
#include "../../tile.h"
#include "../../player/player.h"
#include <vector>

class Assignment : public Criterion {
    int location;

    public:
    void complete(Player* player);
    void improve() override;
    //void distributeResources() override;
    int getCriterionType() override;

    Assignment(int location);
};

#endif
