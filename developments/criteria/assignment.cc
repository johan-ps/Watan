#include "assignment.h"
#include "../../resource.h"

Assignment::Assignment(int locationVal, std::vector<int> cost):
    Criterion{locationVal, cost} {}

void Assignment::complete(Player *player) {
    if(!isSet() /*AND IF THERE IS NO ADJACENT*/){
        
        if(player->purchase(getCost(), this)) {
            setDevelopment(player);
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
    int resourceNum = getNum(resource);
}

//Criterion type should be a field in criterion class?
int Assignment::getCriterionType() {
    return 1;
}

//Exam and Midterm should be decorator classes when implemented
void Assignment::improve() {}
