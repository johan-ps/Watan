#include "player.h"

Player::Player(std::string colour): colour{colour}, criteriaCompleted{0} {
    resources = std::vector<int> (6, 0);
    }

/*std::vector<int> Player::getResources(){
    return resources;
}*/

int Player::getCriteriaSize(){
    return criteria.size();
}
std::string Player::getColour(){
    return colour;
}



// PlayerInfo Player::getInfo(){
//     return {resources, criteria, colour};
// }

// void Player::addGoal(Goal * new_goal){
//     goals.emplace_back(new_goal);

// }

Player::~Player() {}