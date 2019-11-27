<<<<<<< HEAD
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

=======
#ifndef __ASSIGN_H__
#define __ASSIGN_H__
>>>>>>> stageOneCriterion
#include "criterion.h"
#include "../../../tile.h"
#include <vector>

class Assignment : public Criterion {
    // int cost;
    // Player player;
    int location;
    // std::vector<Tile*> tiles;
    //std::vector<Goal*> goals;
    public:
<<<<<<< HEAD
    // void complete(Player&) override;
    // void improve() override;
    // void distributeResources() override;
    
    Assignment(int location);
};

#endif
=======
    void complete(Player&);
    void improve() override;
    void distributeResources() override;

    Assignment();
};
#endif 
>>>>>>> stageOneCriterion
