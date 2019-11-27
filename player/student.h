#ifndef STUDENT_H
#define STUDENT_H

#include "player.h"

class Student : public Player {
    public:
    void trade(Player *, Resource) override;
    void steal(Player *) override;
    void printStatus() override;
};

#endif
