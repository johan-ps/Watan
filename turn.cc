#include "turn.h"

Turn::Turn(Player* whoseTurn, Dice* dice, std::string phase): 
    whoseTurn{whoseTurn}, dice{dice}, phase{phase} {}

void Turn::startTurn(){


}


Player* Turn::getCurStudent(){
    return nullptr;
}

void Turn::nextTurn(Player *){

}

void Turn::help(){

}