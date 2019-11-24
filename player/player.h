#include <map>

class Player {
    std::map<Resources><Integer> resources;
    std::vector<Goal> goals;
    std::map<Criterion><int> criteria;
    Dice dice;
    int resourceCount;
    std::string colour;

    public:
    virtual void trade(Player, Resource) = 0;
    virtual void steal(Player) = 0;
    virtual void printStatus() = 0;
}