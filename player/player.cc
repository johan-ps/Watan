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


// PlayerInfo Player::getInfo(){
//     return {resources, criteria, colour};
// }

// void Player::addGoal(Goal * new_goal){
//     goals.emplace_back(new_goal);

// }

Player::~Player() {}