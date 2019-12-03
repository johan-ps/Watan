#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "criterion.h"
#include "../../tile.h"
#include "../../player/player.h"
#include <vector>

class Assignment : public Criterion {

    public:
        Assignment(int location, std::vector<int> cost = {1, 1, 1, 0, 1});
        void complete(Player* player, bool init = false) override;
        void notify() override;
        void improve(Player* player, bool init = false) override;
        void distributeResources(std::string) override;
};

#endif