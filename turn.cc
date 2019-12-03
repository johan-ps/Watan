#include "turn.h"
#include <iostream>

Turn::Turn(GameManager *gm):
    gm{gm} {}

void Turn::startTurn(Player *playerTurn){
    whoseTurn = playerTurn;
    
    int count = 0;
    for (auto &player : gm->gameState->players) {
        if (player->getColour() == playerTurn->getColour()) {
            gm->gameState->curTurn = count++;
        }
    }

    std::cout << "Student " << whoseTurn->getColour() << "'s turn." << std::endl;
    whoseTurn->printStatus();
    std::string input;

    while(true) {
        std::cout << "> ";
        if (std::cin >> input) {
            if (input == "load") {
                int val;
                std::cin >> val;
                gm->dice->setDice(false);
                gm->dice->setLoadVal(val);
            } else if (input == "fair") {
                //set dice to fair
                gm->dice->setDice(true);
            } else if (input == "roll") {
                //roll dice
                gm->dice->roll();
                gm->gameState->curTurn = count;
                endTurn();
                return;
            } else {
                //print error msg
                std::cout << "Invalid command" << std::endl;
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
                gm->gameBoard->drawBoard();
            } else if (input == "status") {
                //print status of all students
                for (auto &n : gm->gameState->players) {
                    n->printStatus();
                }
            } else if (input == "criteria") {
                //prints the criteria the current student has completed
                whoseTurn->printCompletions();
            } else if (input == "achieve") {
                int loc;
                std::cin >> loc;
                gm->gameBoard->achieveGoal(loc, whoseTurn, true);
            } else if (input == "complete") {
                int loc;
                std::cin >> loc;
                gm->gameBoard->completeCriteria(loc, whoseTurn, true);
            } else if (input == "improve") {
                int loc;
                std::cin >> loc;
                gm->gameBoard->improveCriteria(loc, whoseTurn);
            } else if (input == "trade") {

            } else if (input == "next") {
                return;
            } else if (input == "save") {
                std::string fileName;
                std::cin >> fileName;
                gm->fileManager->writeToFile(fileName, *(gm->gameState));
            } else if (input == "help") {
                help();
            } else {
                //print error msg
                std::cout << "Invalid command" << std::endl;
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

Player *Turn::getCurStudent() {
    return whoseTurn;
}

// void Turn::nextTurn(Player * nextPlayer){
//     whoseTurn = nextPlayer;
// }

void Turn::help() {
    std::cout << "Valid commands:" << std::endl;
    std::cout << "board" << std::endl;
    std::cout << "status" << std::endl;
    std::cout << "criteria" << std::endl;
    //std::cout << "acheive <goal>" << std::endl;
    std::cout << "complete <criterion>" << std::endl;
    std::cout << "improve <criterion>" << std::endl;
    //std::cout << "trade <colour> <give> <take>" << std::endl;
    std::cout << "next" << std::endl;
    //std::cout << "save <file>" << std::endl;
    std::cout << "help" << std::endl;
}