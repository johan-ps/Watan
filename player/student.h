#ifndef STUDENT_H
#define STUDENT_H

#include "player.h"

class Student : public Player {
    public:
    Student(std::string colour);
    
    void steal(Player *) override;
    void trade(Player *, Resource) override;
    void printStatus() override;
    bool purchase(std::vector<int>, Criterion *) override;
};

#endif
