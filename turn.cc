#include "turn.h"

Turn::Turn(Player* whoseTurn, Dice* dice, std::string phase): 
    whoseTurn{whoseTurn}, dice{dice}, phase{phase} {}

void Turn::startTurn(){
    std::cout << "Student " << whoseTurn->getColour() << "'s turn." << std::endl;
    whoseTurn->printStatus();

    

}

Player *Turn::getCurStudent(){
    return whoseTurn;
}

void Turn::nextTurn(Player * nextPlayer){
    whoseTurn = nextPlayer;
}

void Turn::help(){
    std::cout << "Valid commands:" << std::endl;
    // std::cout << "board" << std::endl;
    // std::cout << "status" << std::endl;
    // std::cout << "criteria" << std::endl;
    // std::cout << "acheive <goal>" << std::endl;
    // std::cout << "complete <criterion>" << std::endl;
    // std::cout << "improve <criterion>" << std::endl;
    // std::cout << "trade <colour> <give> <take>" << std::endl;
    // std::cout << "next" << std::endl;
    // std::cout << "save <file>" << std::endl;
    // std::cout << "help" << std::endl;
}