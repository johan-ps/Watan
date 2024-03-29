#include "player.h"

Player::Player(std::string colour, std::vector<int> resources): 
    colour{colour}, criteriaCompleted{0}, resources{resources} {}

Player::Player(std::string colour, std::vector<Criterion*> criteria, 
    std::vector<Goal*> goals, std::vector<int> resources): 
    colour{colour}, criteriaCompleted{0}, criteria{criteria}, goals{goals}, resources{resources} {}

int Player::getCriteriaSize(){
    return criteria.size();
}
std::string Player::getColour(){
    return colour;
}

int Player::getCompleted(){
    return criteriaCompleted;
}

int Player::getResourceCount(){
    int resourceCount = 0;
    for (auto resource: resources){
        resourceCount += resource;
    }

    return resourceCount;
}

std::vector<Criterion*> Player::getCriterion() {
    return criteria;
}

std::vector<Goal*> Player::getGoals() {
    return goals;
}

std::vector<int> Player::getResources() {
    return resources;
}

std::vector<int> Player::getResourcesGained() {
    std::vector<int> temp = resourcesGained;
    for (auto &n : resourcesGained) {
        n = 0;
    }
    return temp;
}

void Player::addResourceGained(Resource type, int amount) {
    resourcesGained.at(type.getVal()) += amount;
}

// PlayerInfo Player::getInfo(){
//     return {resources, criteria, colour};
// }

// void Player::addGoal(Goal * new_goal){
//     goals.emplace_back(new_goal);

// }

Player::~Player() {}





