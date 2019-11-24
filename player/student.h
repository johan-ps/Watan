#include "player.h"

class Student : public Player {
    public:
    void trade(Player, Resource) override;
    void steal(Player) override;
    void printStatus() override;
}