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
}

void GameManager::gameOver() { // MAYBE PASS IN " Player *winner " as parameter?
    //end game
    std::string response = "";
    std::cout << "Would you like to play again?" << std::endl;
    std::cin >> response;
    //return response;
}

void GameManager::createBoard(int boardSize) {
    gameBoard = std::unique_ptr<Board> { new Board {} };
    //gameBoard = std::make_unique<Board> {new Board{} };
    gameBoard->init(boardSize);
}

void GameManager::createPlayers(int num) {
    for (int i = 0; i < num; i++) {
        players.emplace_back(new Student{"Blue"});
    }
}
