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
                gm->fileManager->writeToFile(*(gm->gameState));
                break;
            } else if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                gm->fileManager->writeToFile(*(gm->gameState));
                break;
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
                try {
                    gm->gameBoard->achieveGoal(loc, whoseTurn, true);
                } catch (AlreadyAchievedException &a) {
                    std::cout << a.getError() << std::endl;
                } catch (InsufficientResourcesException &r) {
                    std::cout << r.getError() << std::endl;
                } catch (InvalidLocationException &l) {
                    std::cout << l.getError() << std::endl;
                }         
            } else if (input == "complete") {
                int loc;
                std::cin >> loc;
                try {
                    gm->gameBoard->completeCriteria(loc, whoseTurn, true);
                } catch (AlreadyCompletedException &c) {
                    std::cout << c.getError() << std::endl;
                } catch (InsufficientResourcesException &r) {
                    std::cout << r.getError() << std::endl;
                } catch (InvalidLocationException &l) {
                    std::cout << l.getError() << std::endl;
                } 
            } else if (input == "improve") {
                int loc;
                std::cin >> loc;
                try {
                    gm->gameBoard->improveCriteria(loc, whoseTurn);
                } catch (InsufficientResourcesException &r) {
                    std::cout << r.getError() << std::endl;
                }  catch (InvalidCriteriaException &c) {
                    std::cout << c.getError() << std::endl;
                } catch (CriteriaCannotBeImprovedException &c) {
                    std::cout << c.getError() << std::endl;
                } catch (InvalidLocationException &l) {
                    std::cout << l.getError() << std::endl;
                }
            } else if (input == "trade") {
                Player *player = nullptr;
                std::string colour, give, take, accept;
                if (std::cin) {
                    std::cin >> colour;
                } else {
                    std::cout << "Invalid command." << std::endl;
                    continue;
                }
                std::vector<std::string> resourceTemp = {"CAFFEINE", "LAB", "LECTURE", "STUDY", "TUTORIAL"};
                bool isValid = false;
                if (std::cin) {
                    std::cin >> give;
                    for (auto resource : resourceTemp) {
                        if (give == resource) {
                            isValid = true;
                            break;
                        }
                    }
                    if (!isValid) {
                        std::cout << "Invalid resource." << std::endl;
                        continue;
                    }                    
                } else {
                    std::cout << "Invalid command." << std::endl;
                    continue;
                }
                if (std::cin) {
                    std::cin >> take;
                    for (auto resource : resourceTemp) {
                        if (give == resource) {
                            isValid = true;
                            break;
                        }
                    }
                    if (!isValid) {
                        std::cout << "Invalid resource." << std::endl;
                        continue;
                    } 
                } else {
                    std::cout << "Invalid command." << std::endl;
                    continue;
                }
                for (auto &student : gm->gameState->players) {
                    if (student->getColour() == colour) {
                        player = student.get();
                    }
                }
                if (!player) {
                    std::cout << "Invalid colour." << std::endl;
                    continue;
                }
                std::cout << whoseTurn->getColour() << " offers " << colour << " one " << give << " for one " << take << "." << std::endl;
                std::cout << "Does " << colour << " accept this offer?" << std::endl;
                while (std::cin >> accept) {
                    if (accept == "yes") {
                        try {
                            whoseTurn->trade(player, give, take);
                        } catch (InvalidTradeException &t) {
                            std::cout << t.getError() << std::endl;
                            break;
                        }
                        std::cout << whoseTurn->getColour() << " gains one " << take << " and loses one " << give << "," << std::endl;
                        std::cout << colour << " gains one " << give << " and loses one " << take << "." << std::endl;
                        break;
                    } else if (accept == "no") {
                        std::cout << "Trade was rejected." << std::endl;
                        break;
                    } else {
                        std::cout << "Invalid command.\n> " << std::endl;
                    }
                }
            } else if (input == "next") {
                return;
            } else if (input == "save") {
                std::string fileName;
                std::cin >> fileName;
                gm->fileManager->writeToFile(*(gm->gameState), fileName);
            } else if (input == "help") {
                help();
            } else {
                //print error msg
                std::cout << "Invalid command." << std::endl;
            }
        } else {
            if (std::cin.eof()) {
                gm->fileManager->writeToFile(*(gm->gameState));
                break;
            } else if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                gm->fileManager->writeToFile(*(gm->gameState));
                break;
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