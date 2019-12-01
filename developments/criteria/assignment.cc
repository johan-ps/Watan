#include "assignment.h"
#include "../../resource.h"

Assignment::Assignment(int locationVal, std::vector<int> cost):
    Criterion{locationVal, cost} {}

void Assignment::complete(Player *player, bool init) {
    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        if (init) {
            setDevelopment(player, 1);
        } else if(player->purchaseCriteria(getCost(), this)) {
            setDevelopment(player, 1);
            //alert text display of new owner/criteria type somehow
        } else {
            throw "InsufficientResourcesException";
        }
    } else {
        throw "AlreadyAchievedException";
    }
}

void Assignment::notify() {}

void Assignment::distributeResources(std::string resource) {
    //int resourceNum = getNum(resource);
}

//Criterion type should be a field in criterion class?


//Exam and Midterm should be decorator classes when implemented
void Assignment::improve() {}
