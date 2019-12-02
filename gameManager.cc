#include "gameManager.h"
#include "board.h"

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
}

void GameManager::load(std::string x) {
    //std::cout << "Load saved game from file: " << x << std::endl;
    fileManager->readGameFromFile(x, *gameState);
}

void GameManager::board(std::string x) {
    //std::cout << "Load board from file: " << x << std::endl;
    fileManager->readBoardFromFile(x, *gameState);
}

bool GameManager::startGame() {
    createBoard(19);
    createPlayers(4);
    //initialize player criteria
    for (auto &n : gameState->players) {
        int loc;
        std::cout << "Student " << n->getColour() << ", where do you want to complete an Assignment?\n> ";
        std::cin >> loc;
        gameBoard->completeCriteria(loc, n.get(), true);
    }
    for (std::vector<std::unique_ptr<Player>>::reverse_iterator it = gameState->players.rbegin(); it != gameState->players.rend(); ++it) {
        int loc;
        std::cout << "Student " << it->get()->getColour() << ", where do you want to complete an Assignment?\n> ";
        std::cin >> loc;
        gameBoard->completeCriteria(loc, it->get(), true);
    }
    dice->setBoard(gameBoard.get());
    turns = new Turn{this};

    std::string response = startTurns();

    if (response == "yes"){
        return true;
    }
    else if (response == "no"){
        return false;
    }
    else{
        // MAYBE NEED TO HAVE THIS CHECK IN StartTurns()?
        std::cout << "Good job man you gave the program an invalid command (should've done yes or no)" << std::endl;
        return false;
    }
}

std::string GameManager::startTurns() {
    while (true) {
        for (auto &player : gameState->players) {
            turns->startTurn(player.get());
            std::cout << "DEBUG: Next Player's Turn" << std::endl;

            // CHANGE THIS (and anything else after in the call chain) 
            // TO WORK WITH AN EXCEPTION THAT WE THROW, IF APPLICABLE

            //std::cout << "DEBUG: RIGHT BEFORE IF STATEMENT" << std::endl;
            if (player->getCompleted() >= 10){ 
                //std::cout << "ENTERED IF STATEMENT" << std::endl;
                std::string response = gameOver();
                return response;
            }
            //////////////////////////////////////////////////////////
        }
    }
    // players.at(1)->recieve(0, 1);
    // players.at(1)->printStatus();
}

std::string GameManager::gameOver() { // MAYBE PASS IN " Player *winner " as parameter?
    //end game
    std::string response;
    std::cout << "Would you like to play again? \n>" << std::endl; // TODO - CHANGE "\n>"" TO SOMETHING BETTER
    std::cin >> response;
    return response;
}

void GameManager::createBoard(int boardSize) {
    std::cout << "here 1" << std::endl;
    gameBoard = std::make_unique<Board>();
    if (gameState->values.size() != 0) {
        std::cout << "here 2" << std::endl;
        gameBoard->initValues(gameState->values);
    } else {
        std::cout << "here 3" << std::endl;
        std::vector<int> shuffleVal = {2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12};
        std::cout << "here 4" << std::endl;
        std::random_shuffle(shuffleVal.begin(), shuffleVal.end());
        std::cout << "here 5" << std::endl;
        gameState->values = shuffleVal;
        std::cout << "here 6" << std::endl;
        // for (int i = 0; i < boardSize; i++) {
        //     gameState->values.emplace_back(shuffleVal.at(i));
        // }
        gameBoard->initValues(gameState->values);
        std::cout << "here 7" << std::endl;
    }
    std::cout << "here 8" << std::endl;
    gameBoard->init(boardSize);
}

void GameManager::createPlayers(int num) {
    //std::vector<int> resources = {2, 1, 0, 2, 1, 0};
    std::string playerColours[4] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < num; i++) {
        gameState->players.emplace_back(new Student{playerColours[i]});
    }
}

