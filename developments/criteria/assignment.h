#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "criterion.h"
#include "../../tile.h"
#include "../../player/player.h"
#include <vector>

class Assignment : public Criterion {
    // int cost;
    // Player player;
    int location;
    // std::vector<Tile*> tiles;
    //std::vector<Goal*> goals;
    public:
    void complete(Player&);
    void improve() override;
    // void distributeResources() override;
    int getCriterionType() override;
    
    Assignment(int location);
};

#endif
