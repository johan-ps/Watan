// #include "resource.h"
// #include "goal.h"
// #include "criterion.h"
// #include "geese.h"

class Goal;
class Criterion;
class Geese;
class Resource;

class Tile {
    int location;
    int value;
    Resource resource;
    std::vector<Goal> goals;
    std::vector<Criterion> criteria;
    Geese geese;
    bool isOverrun;
};