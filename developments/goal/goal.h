#ifndef GOAL_H
#define GOAL_H

#include "../development.h"

class Goal : public Development {
    public:
        virtual void achieve(Player *) = 0;
};

#endif
