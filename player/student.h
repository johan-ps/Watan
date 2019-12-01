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
    void printCompletions() override;
    bool purchase(std::vector<int>, Development *) override;
};

#endif
