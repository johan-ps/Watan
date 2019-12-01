#ifndef STUDENT_H
#define STUDENT_H

#include "player.h"

class Development;

class Student : public Player {
    public:
    Student(std::string colour);
    
    void steal(Player *) override;
    void trade(Player *, std::string, std::string) override;
    void recieve(int, int) override;
    void printStatus() override;
    void printCompletions() override;
    bool purchaseCriteria(std::vector<int>, Criterion *) override;
    bool purchaseGoal(std::vector<int>, Goal *) override;
};

#endif
