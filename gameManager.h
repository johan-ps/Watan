#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include <stdlib.h>
#include "./player/student.h"
#include "fileManager.h"
#include "dice.h"
#include "turn.h"

class Turn;
class Board;

class GameManager {
    GameState *gameState;
    FileManager *fileManager;
    Dice *dice;
    Turn *turns;
    // Geese geese;
    std::unique_ptr<Board> gameBoard;
    TextDisplay *td;
    int seedVal;
    bool seedInit = false;
    //std::vector<std::unique_ptr<Player>> players;


    public:
    GameManager();
    bool startGame();
    std::string gameOver();
    void createPlayers(int num);
    // void createDice();
    void createBoard(int boardSize);
    // void createFileManager();
    // void moveGeese();
    // void printPlayerStatus();
    std::string startTurns();
    // void saveGame();
    Board getGameBoard();
    void seed(int x);
    void load(std::string x);
    void board(std::string x);
    friend class Turn;
};


#endif
