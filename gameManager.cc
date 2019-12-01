#include "gameManager.h"
#include "board.h"

#include "iostream"
#include "string"
Board GameManager::getGameBoard() {
    return *gameBoard;
}

void GameManager::startGame() {
    createBoard(19);
    createPlayers(1);
    for (auto &n : players) {
        int loc;
        std::cout << "Student " << n->getColour() << ", where do you want to complete an Assignment?\n>";
        std::cin >> loc;
        gameBoard->completeCriteria(loc, n.get(), true);
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
    for (int i = 0; i < num; i++) {
        players.emplace_back(new Student{"Blue"});
    }
}
