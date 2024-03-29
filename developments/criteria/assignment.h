#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "criterion.h"
#include "../../player/player.h"
#include "../../exception.h"
#include "../../resources.h"

class Assignment : public Criterion {

    public:
        Assignment(int location, int criteriaVal = 1, std::vector<int> cost = {1, 1, 1, 0, 1});
        void complete(Player* player, bool init = false) override;
        void notify() override;
        void improve(Player* player, bool init = false) override;
        void distributeResources(Resource resource) override;
        ~Assignment();
};

#endif




