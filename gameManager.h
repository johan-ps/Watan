#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "./player/student.h"
#include "turn.h"
#include "dice.h"

class Board;

class GameManager {
    // FileManager fileManager;
    Dice *dice;
    Turn *curTurn;
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
    void startTurns();
    // void saveGame();
    Board getGameBoard();
};

#endif
