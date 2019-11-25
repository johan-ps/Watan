#include "gameManager.h"
#include "board.h"

GameManager::GameManager(int boardSize):
    gameBoard{new Board(boardSize)} {}

Board GameManager::getGameBoard() {
    return *gameBoard;
}