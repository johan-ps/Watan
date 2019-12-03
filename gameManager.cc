#include "gameManager.h"

#include <iostream>

GameManager::GameManager():
    fileManager{new FileManager{}}, dice{new Dice{}} {
        gameState = new GameState{};
    }

Board GameManager::getGameBoard() {
    return *gameBoard;
}

void GameManager::seed(int x) {
    //std::cout << "Set seed to " << x << std::endl;
    dice->setSeed(x);
    //seedVal = x;
    seedInit = true;
    srand(x);
}

void GameManager::load(std::string x) {
    //std::cout << "Load saved game from file: " << x << std::endl;
    fileManager->readGameFromFile(*gameState, x);
    //std::cout << "Size >>>>>>>>>> " << gameState->resourcesTypes.size() << std::endl;
}

void GameManager::board(std::string x) {
    //std::cout << "Load board from file: " << x << std::endl;
    fileManager->readBoardFromFile(*gameState, x);
}

void GameManager::startGame() {
    gameBoard = std::make_unique<Board>();
    createPlayers(4);
    createBoard(19);
    td = new TextDisplay{gameState->resourceTypes, gameState->values, gameState->gooseTile};
    gameBoard->setTextDisplay(td);
    //modify textdisplay to current state
    for (auto &player : gameState->players) {
        for (auto criterion : player->getCriterion()) {
            std::string playerAssignment = player->getColour().substr(0, 1) + 'A';
            td->notify(criterion->getLocationVal(), 'c', playerAssignment);
        }
    }
    for (auto &player : gameState->players) {
        for (auto goal : player->getGoals()) {
            std::string playerAchievement = player->getColour().substr(0, 1) + 'A';
            td->notify(goal->getLocationVal(), 'g', playerAchievement); 
        }
    }
    gameBoard->drawBoard();
    //initialize player criteria
    for (auto &n : gameState->players) {
        int loc;
        std::cout << "Student " << n->getColour() << ", where do you want to complete an Assignment?" << std::endl;
        while (true) {
            std::cout << "> ";
            try {
                std::cin >> loc;
                gameBoard->completeCriteria(loc, n.get(), true);
                gameBoard->drawBoard();
                break;
            } catch (AlreadyCompletedException &c) {
                std::cout << c.getError() << std::endl;
                continue;
            } catch (InvalidLocationException &l) {
                std::cout << l.getError() << std::endl;
                continue;
            } catch (AdjacentCriteriaExistException &a) {
                std::cout << a.getError() << std::endl;
                continue;
            } catch (GameOverException &g) {
                gameOver(g.getColour());
            }
        }
    }
    for (std::vector<std::unique_ptr<Player>>::reverse_iterator it = gameState->players.rbegin(); it != gameState->players.rend(); ++it) {
        int loc;
        std::cout << "Student " << it->get()->getColour() << ", where do you want to complete an Assignment?" << std::endl;
        while (true) {
            std::cout << "> ";
            try {
            std::cin >> loc;
            gameBoard->completeCriteria(loc, it->get(), true);
            gameBoard->drawBoard();
            break;
            } catch (AlreadyCompletedException &c) {
                std::cout << c.getError() << std::endl;
                continue;
            } catch (InvalidLocationException &l) {
                std::cout << l.getError() << std::endl;
                continue;
            } catch (AdjacentCriteriaExistException &a) {
                std::cout << a.getError() << std::endl;
                continue;
            } catch (GameOverException &g) {
                gameOver(g.getColour());
            }   
        }
    }
    dice->setBoard(gameBoard.get());
    turns = new Turn{this};

    startTurns();
}

void GameManager::startTurns() {
    try {
        while (true) {
            for (auto &player : gameState->players) {
                turns->startTurn(player.get());
            }
        }
    } catch (GameOverException &g) {
        gameOver(g.getColour());
    }
}

void GameManager::gameOver(std::string winner) {
    std::string response;
    std::cout << "Student " << winner << " wins!!!" << std::endl;
    std::cout << "Would you like to play again?\n> " << std::endl;
    while(true) {
        if (std::cin >> response) {
            if (response == "yes") {
                std::cout << "Would you like to start a new game, or load from a file?\n> " << std::endl;
                while(true) {
                    if (std::cin >> response) {
                        if (response == "new") {
                            startGame();
                        } else if (response == "file") {
                            std::cin >> response;
                            board(response);
                        } else {
                            std::cout << "Enter 'new' or 'file <filename>'." << std::endl;
                        }
                    }else {
                        if (std::cin.eof()) {
                            break;
                        } else if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                }
            } else if (response == "no") {
                break;
            } else {
                std::cout << "Enter 'yes' or 'no'." << std::endl;
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

void GameManager::createBoard(int boardSize) {
    if (gameState->values.size() != 0) {
        gameBoard->initValues(gameState->values);
        gameBoard->initResources(gameState->resourceTypes);
    } else {
        if (!seedInit) {
            srand(std::time(0));
        }
        std::vector<int> shuffleVal = {2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12};
        std::random_shuffle(shuffleVal.begin(), shuffleVal.end());
        gameState->values = shuffleVal;
        gameBoard->initValues(gameState->values);
        std::vector<Resource> shuffleResources = {
            Resource("CAFFEINE"), Resource("CAFFEINE"), Resource("CAFFEINE"), Resource("CAFFEINE"),
            Resource("LAB"), Resource("LAB"), Resource("LAB"), Resource("LAB"),
            Resource("LECTURE"), Resource("LECTURE"), Resource("LECTURE"), Resource("LECTURE"),
            Resource("TUTORIAL"), Resource("TUTORIAL"), Resource("TUTORIAL"),
            Resource("STUDY"), Resource("STUDY"), Resource("STUDY"),
            Resource("NETFLIX")
        };
        std::random_shuffle(shuffleResources.begin(), shuffleResources.end());
        gameState->resourceTypes = shuffleResources;        
        gameBoard->initResources(gameState->resourceTypes);
    }
    gameBoard->init(boardSize);
}

void GameManager::createPlayers(int num) {
    std::vector<Criterion*> criteriaTemp;
    std::vector<Goal*> goalsTemp;
    if (gameState->players.size() == 0) {
        std::string playerColours[4] = {"Blue", "Red", "Orange", "Yellow"};
        for (int i = 0; i < num; i++) {
            gameState->players.emplace_back(new Student{playerColours[i]});
        }
    } else {
        for (auto &player : gameState->players) {
            for (auto criterion : player->getCriterion()) {
                //criterion->complete(player, true);
                criteriaTemp.emplace_back(criterion);
            }
        }
        for (auto &player : gameState->players) {
            for (auto goal : player->getGoals()) {
                //goal->achieve(player, true);
                goalsTemp.emplace_back(goal);
            }
        }
    }
    gameBoard->initCriteria(criteriaTemp);
    gameBoard->initGoals(goalsTemp);
}

GameManager::~GameManager() {
    delete gameState;
    delete fileManager;
    delete dice;
    delete turns;
    delete td;
}






