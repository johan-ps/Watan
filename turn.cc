#include "turn.h"
#include <iostream>
#include <sstream>
#include <algorithm>


Turn::Turn(GameManager *gm):
    gm{gm} {}

void Turn::startTurn(Player *playerTurn){
    whoseTurn = playerTurn;

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

        // Check roll value for special cases, such as Geese
        if (gm->dice->getRollVal() == 7){

            for (auto &player: gm->gameState->players){

                    if (player->getResourceCount() >= 10){
                        gm->gameState->geese->eatResources(player.get());
                    }

            }

            // TODO: INCORPORATE GOOSETILE

            std::cout << "Choose where to place the GEESE." << std::endl;
            int tileToBePlaced;
            std::cin >> tileToBePlaced;
            gm->gameBoard->placeGeese(tileToBePlaced);
            gm->gameState->gooseTile = tileToBePlaced;

            std::vector<Player *> studentVictims;

            Tile *geeseTile = gm->gameBoard->getTileByLocation(gm->gameState->gooseTile); // NOTE: Might be easier to just have Geese have a pointer to it's currently owned tile
            if (geeseTile){
                for (auto criterionPair: geeseTile->getInfo().criteria){ // Does this call getInfo() each iteration??
                    Criterion *criterion = criterionPair.second;
                    if (criterion->isSet()){
                        Player *victim = criterion->getOwner();
                        std::vector<Player *>::iterator iter = find(studentVictims.begin(), studentVictims.end(), victim);

                        if (iter != studentVictims.end() && victim != whoseTurn && victim->getResourceCount() > 0){
                            studentVictims.emplace_back(victim);
                        }

                    }
                }

                if (studentVictims.size() > 0){
                    //commenceSteal();
                }
                else{
                    std::cout << "Student " << whoseTurn->getColour() << " has no students to steal from." << std::endl;
                }

                // commenceSteal() /////////////////////////////////
                std::ostringstream printStudentVictims;
                for (auto &player: gm->gameState->players){
                    std::vector<Player *>::iterator iter = find(studentVictims.begin(), studentVictims.end(), player.get());

                    if (iter != studentVictims.end()){
                        printStudentVictims << player->getColour();

                        std::vector<Player *>::iterator temp_iter = iter;
                        temp_iter++;
                        if (temp_iter != studentVictims.end()){
                            printStudentVictims << ", ";
                        }
                    }
                }

                std::cout << "Student " << whoseTurn->getColour();
                std::cout << " can choose to steal from " << printStudentVictims.str() << "." << std::endl;

                std::cout << "Choose a student to steal from." << std::endl;
                std::string victimColour;
                std::cin >> victimColour;

                // Assuming valid input
                for (auto &possibleVictim: studentVictims){
                    if (possibleVictim->getColour() == victimColour){
                        whoseTurn->steal(possibleVictim);
                        break;
                    }
                }
                ////////////////////////////////////////////////////
            }
            else {
                std::cout << "Invalid Geese Tile" << std::endl; // REFACTOR USING EXCEPTIONS
            }
    }

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
                
            } else if (input == "complete") {
                int loc;
                std::cin >> loc;
                gm->gameBoard->completeCriteria(loc, whoseTurn, false);
            } else if (input == "improve") {
                int loc;
                std::cin >> loc;
                gm->gameBoard->improveCriteria(loc, whoseTurn);
            } else if (input == "trade") {

            } else if (input == "next") {
                return;
            } else if (input == "save") {

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