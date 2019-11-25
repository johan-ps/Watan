// #include "resource.h"
// #include "goal.h"
// #include "criterion.h"
// #include "geese.h"
#include <vector>
#include <string>

//class Goal;
//class Criterion;
//class Geese;
//class Resource;

class Tile {
    int location;
    int value;
    std::string resource;
    //Resource resource;
    //std::vector<Goal> goals;
    //std::vector<Criterion> criteria;
    //Geese geese;
    //bool isOverrun;
    public:
    Tile(int location, int value, std::string resource);
    void printTile();
};