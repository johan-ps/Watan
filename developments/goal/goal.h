#ifndef GOAL_H
#define GOAL_H

#include "../development.h"

class Goal : public Development {
    public:
    Goal(int locationVal);
        virtual void achieve(Player *) = 0;
};

#endif
