#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "criterion.h"
#include "../../tile.h"
#include "../../player/player.h"
#include <vector>

class Assignment : public Criterion {
    int location;
    const std::vector<int> cost = { 1, 1, 1, 0, 1, 0};

    public:
        Assignment(int location);
        void notify() override;
        void complete(Player*);
        void improve() override;
        void distributeResources() override;
        int getCriterionType() override;
};

#endif
