#include "gameManager.h"
#include "board.h"

#include "iostream"
#include "string"
Board GameManager::getGameBoard() {
    return *gameBoard;
}

void GameManager::startGame() {
    createBoard(19);
    createPlayers(4);
    //initialize player criteria
    for (auto &n : players) {
        int loc;
        std::cout << "Student " << n->getColour() << ", where do you want to complete an Assignment?\n> ";
        std::cin >> loc;
        gameBoard->completeCriteria(loc, n.get(), true);
    }
    for (std::vector<std::unique_ptr<Player>>::reverse_iterator it = players.rbegin(); it != players.rend(); ++it) {
        int loc;
        std::cout << "Student " << it->get()->getColour() << ", where do you want to complete an Assignment?\n> ";
        std::cin >> loc;
        gameBoard->completeCriteria(loc, it->get(), true);
    }
    dice = new Dice{};
    curTurn = new Turn{dice};
    startTurns();
}

void GameManager::startTurns() {
    while (true) {
        for (auto &n : players) {
            curTurn->startTurn(n.get());
        }
    }
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
    gameBoard->init(boardSize);
}

void GameManager::createPlayers(int num) {
    std::string playerColours[4] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < num; i++) {
        players.emplace_back(new Student{playerColours[i]});
    }
}
