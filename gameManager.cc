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

void GameManager::startGame() {
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
    startTurns();
}

void GameManager::startTurns() {
    while (true) {
        for (auto &n : gameState->players) {
            turns->startTurn(n.get());
        }
    }
    // players.at(1)->recieve(0, 1);
    // players.at(1)->printStatus();
}

void GameManager::gameOver() { // MAYBE PASS IN " Player *winner " as parameter?
    //end game
    std::string response = "";
    std::cout << "Would you like to play again?" << std::endl;
    std::cin >> response;
    //return response;
}

void GameManager::createBoard(int boardSize) {
    gameBoard = std::make_unique<Board>();
    if (gameState->values.size() != 0) {
        gameBoard->initValues(gameState->values);
    } else {
        std::vector<int> shuffleVal = {2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12};
        std::random_shuffle(shuffleVal.begin(), shuffleVal.end());
        gameState->values = shuffleVal;
        gameBoard->initValues(gameState->values);
    }
    gameBoard->init(boardSize);
}

void GameManager::createPlayers(int num) {
    //std::vector<int> resources = {2, 1, 0, 2, 1, 0};
    std::string playerColours[4] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < num; i++) {
        gameState->players.emplace_back(new Student{playerColours[i]});
    }
}

