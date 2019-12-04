#include "turn.h"
#include <iostream>
#include <sstream>
#include <algorithm>


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
                std::string val;
                std::cin >> val;
                try {
                    try {
                        gm->dice->setLoadVal(std::stoi(val));
                    } catch (std::invalid_argument &a) {
                        std::cout << "Invalid command." << std::endl;
                        continue;
                    }
                } catch (DiceOutOfRangeException &d) {
                    std::cout << d.getError() << std::endl;
                    continue;
                }
            } else if (input == "fair") {
                //set dice to fair
                gm->dice->setFair();
            } else if (input == "roll") {
                //roll dice
                try {
                    gm->dice->roll();
                    unsigned int totalResourceCount = 0;
                    for (auto &player : gm->gameState->players) {
                        std::string resourcesGained = "";
                        unsigned int playerResourceCount = 0;
                        std::vector<int> tempResources = player->getResourcesGained();
                        for (unsigned int i = 0; i < tempResources.size(); i++) {
                            totalResourceCount += tempResources.at(i);
                            playerResourceCount += tempResources.at(i);
                            Resource resource {i};
                            resourcesGained += std::to_string(tempResources.at(i)) + " " + resource.getNameToUpper() + "\n";
                        }
                        if (playerResourceCount != 0) {
                            std::cout << "Student " << player->getColour() << " gained:" << std::endl;
                            std::cout << resourcesGained;
                        }
                    }
                    if (totalResourceCount == 0) {
                        std::cout << "No students gained resources." << std::endl;
                    }
                    gm->gameState->curTurn = count;
                    endTurn();
                    return;
                } catch (DiceNotSetException &d) {
                    std::cout << d.getError() << std::endl;
                    continue;
                }
            } else {
                //print error msg
                std::cout << "Invalid command" << std::endl;
            }
        } else {
            if (std::cin.eof()) {
                gm->fileManager->writeToFile(*(gm->gameState));
                break;
            } else if (std::cin.fail()) {
                std::cout << "here" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
}

void Turn::commenceSteal(std::vector<Player *> studentVictims){ // MAYBE MAKE REFERENCE?
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
    std::cout << "> ";
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

void Turn::endTurn() {
    std::string input;

    // Check roll value for special cases, such as Geese
    if (gm->dice->getRollVal() == 7){

        // Geese eats all players resources that have 10 or more
        for (auto &player: gm->gameState->players){
                if (player->getResourceCount() >= 10){
                    gm->gameState->geese->eatResources(player.get());
                }
        }

        // CHECK THAT GOOSETILE UPDATES

        // Current player places GEESE
        std::cout << "Choose where to place the GEESE." << std::endl;
        std::cout << "> ";
        int tileToBePlaced;
        std::cin >> tileToBePlaced;
        gm->gameBoard->placeGeese(tileToBePlaced);
        gm->gameState->gooseTile = tileToBePlaced;

        std::vector<Player *> studentVictims;

        Tile *geeseTile = gm->gameBoard->getTileByLocation(gm->gameState->gooseTile); // NOTE: Might be easier to just have Geese have a pointer to it's currently owned tile
        
        // If Geese was placed on tile successfully
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

            // If there are students to steal from, start the stealing process for the active player
            if (studentVictims.size() > 0){
                commenceSteal(studentVictims);
            }
            else{
                std::cout << "Student " << whoseTurn->getColour() << " has no students to steal from." << std::endl;
            }

        }
        else {
            std::cout << "Invalid Geese Tile" << std::endl; // REFACTOR USING EXCEPTIONS
        }
    }

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
                    gm->gameBoard->achieveGoal(loc, whoseTurn);
                } catch (AlreadyAchievedException &a) {
                    std::cout << a.getError() << std::endl;
                    continue;
                } catch (InsufficientResourcesException &r) {
                    std::cout << r.getError() << std::endl;
                    continue;
                } catch (InvalidLocationException &l) {
                    std::cout << l.getError() << std::endl;
                    continue;
                } catch (CannotBuildGoalHereException &g) {
                    std::cout << g.getError() << std::endl;
                }
            } else if (input == "complete") {
                int loc;
                std::cin >> loc;
                try {
                    gm->gameBoard->completeCriteria(loc, whoseTurn);
                } catch (AlreadyCompletedException &c) {
                    std::cout << c.getError() << std::endl;
                    continue;
                } catch (InsufficientResourcesException &r) {
                    std::cout << r.getError() << std::endl;
                    continue;
                } catch (InvalidLocationException &l) {
                    std::cout << l.getError() << std::endl;
                    continue;
                } catch (NoAdjacentAchievementException &a) {
                    std::cout << a.getError() << std::endl;
                    continue;
                } catch (AdjacentCriteriaExistException &a) {
                    std::cout << a.getError() << std::endl;
                    continue;
                } catch (GameOverException &g) {
                    throw g;
                }
            } else if (input == "improve") {
                int loc;
                std::cin >> loc;
                try {
                    gm->gameBoard->improveCriteria(loc, whoseTurn);
                } catch (InsufficientResourcesException &r) {
                    std::cout << r.getError() << std::endl;
                    continue;
                }  catch (InvalidCriteriaException &c) {
                    std::cout << c.getError() << std::endl;
                    continue;
                } catch (CriteriaCannotBeImprovedException &c) {
                    std::cout << c.getError() << std::endl;
                    continue;
                } catch (InvalidLocationException &l) {
                    std::cout << l.getError() << std::endl;
                    continue;
                } catch (GameOverException &g) {
                    throw g;
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





