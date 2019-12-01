#include "assignment.h"
#include "../../resource.h"
#include <iostream>

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
    std::cout << "Distribute resources" << std::endl;
    Player * owner = getOwner();
    // if(owner) {
    //     int resourceNum = getResourceNum(resource);
    //     owner->recieve(resourceNum, getCriteriaVal());
    // }
}


//Exam and Midterm should be decorator classes when implemented
void Assignment::improve() {}
