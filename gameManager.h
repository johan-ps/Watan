#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "./player/student.h"

class Board;

class GameManager {
    // FileManager fileManager;
    // Turn curTurn;
    // Geese geese;
    std::unique_ptr<Board> gameBoard;
    std::vector<std::unique_ptr<Player>> players;


    public:
    void startGame();
    void gameOver();
    void createPlayers(int num);
    // void createDice();
    void createBoard(int boardSize);
    // void createFileManager();
    // void moveGeese();
    // void printPlayerStatus();
    // void startTurns();
    // void saveGame();
    Board getGameBoard();
};

#endif
