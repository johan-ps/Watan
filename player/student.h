#ifndef STUDENT_H
#define STUDENT_H

#include "player.h"

class Development;

class Student : public Player {
    public:
    Student(std::string colour);
    
    void steal(Player *) override;
    void trade(Player *, std::string resource) override;
    void printStatus() override;
    bool purchaseCriteria(std::vector<int>, Criterion *) override;
    bool purchaseGoal(std::vector<int>, Goal *) override;
    void printCompletions() override;
};

#endif
