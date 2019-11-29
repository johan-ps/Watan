#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "criterion.h"
#include "../../tile.h"
#include "../../player/player.h"
#include <vector>

class Assignment : public Criterion {
    int location;
<<<<<<< HEAD
    const std::vector<int> cost = { 1, 1, 1, 0, 1};

    public:
        Assignment(int location);
        void complete(Player*);
        void improve() override;
        void distributeResources() override;
        int getCriterionType() override;
=======

    public:
    void complete(Player* player);
    void improve() override;
    //void distributeResources() override;
    int getCriterionType() override;
>>>>>>> 8909719dc63fc346a61d3d73768cb9e70e56c417

};

#endif
