#include "player.h"

Player::Player(std::string colour):
    colour{colour} {}

std::vector<int> Player::getResources(){
    return resources;
}

int Player::getCriteriaSize(){
    return criteria.size();
}
std::string Player::getColour(){
    return colour;
}



// PlayerInfo Player::getInfo(){
//     return {resources, criteria, colour};
// }

Player::~Player() {}