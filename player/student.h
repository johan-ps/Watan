#ifndef STUDENT_H
#define STUDENT_H

#include "player.h"

class Development;

class Student : public Player {
    public:
    Student(std::string colour, std::vector<int> = {0, 0, 0, 0, 0});
    Student(std::string colour, std::vector<Criterion*>, std::vector<Goal*>, std::vector<int> = {0, 0, 0, 0, 0});
    
    void steal(Player *) override;
    void trade(Player *, std::string, std::string) override;
    void recieve(int, int) override;
    void printStatus() override;
    void printCompletions() override;
    bool purchaseCriteria(std::vector<int>, Criterion *, bool, bool init = false) override;
    bool purchaseGoal(std::vector<int>, Goal *, bool init = false) override;
};

#endif
