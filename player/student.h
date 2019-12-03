#ifndef STUDENT_H
#define STUDENT_H

#include "player.h"
#include "../exception.h"

class Development;

class Student : public Player {
    public:
    Student(std::string colour, std::vector<int> resources = {0, 0, 0, 0, 0});
    Student(std::string colour, std::vector<Criterion*>, std::vector<Goal*>, std::vector<int> resources = {0, 0, 0, 0, 0});
    
    void steal(Player *victim) override;
    void trade(Player *otherPlayer, Resource gained, Resource lost) override;
    void recieve(Resource type, int amount) override;
    void remove(Resource type, int amount) override;
    void printStatus() override;
    void printCompletions() override;
    void purchaseCriteria(std::vector<int> cost, Criterion *newCriterion, bool improving, bool init = false) override;
    void purchaseGoal(std::vector<int> cost, Goal *newGoal, bool init = false) override;
    ~Student();
};

#endif





