#include "turn.h"

Turn::Turn(Dice* dice): 
    dice{dice} {}

void Turn::startTurn(Player *playerTurn){
    whoseTurn = playerTurn;

    std::cout << "Student " << whoseTurn->getColour() << "'s turn." << std::endl;
    //whoseTurn->printStatus();
    std::string input;

    while(true) {
        std::cout << "> ";
        if (std::cin >> input) {
            if (input == "load") {
                //set dice to loaded
            } else if (input == "fair") {
                //set dice to fair
            } else if (input == "roll") {
                //roll dice
                endTurn();
                return;
            } else {
                //print error msg
            }
        } else {
            if (std::cin.eof()) {
                break;
            } else if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
}

void Turn::endTurn() {
    std::string input;

    while(true) {
        std::cout << "> ";
        if (std::cin >> input) {
            if (input == "board") {
                //print board
            } else if (input == "status") {
                //print status of all students
            } else if (input == "criteria") {
                //prints the criteria the current student has completed
            } else if (input == "achieve") {

            } else if (input == "complete") {

            } else if (input == "improve") {

            } else if (input == "trade") {

            } else if (input == "next") {
                return;
            } else if (input == "save") {

            } else if (input == "help") {
                help();
            } else {
                //print error msg
            }
        } else {
            if (std::cin.eof()) {
                break;
            } else if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
}

Player *Turn::getCurStudent(){
    return whoseTurn;
}

// void Turn::nextTurn(Player * nextPlayer){
//     whoseTurn = nextPlayer;
// }

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