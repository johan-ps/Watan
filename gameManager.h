#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include <stdlib.h>

#include "board.h"
#include "textDisplay.h"
#include "./player/student.h"
#include "./developments/goal/achievement.h"
#include "./developments/criteria/assignment.h"
#include "fileManager.h"
#include "dice.h"
#include "turn.h"
#include "exception.h"

class Resource;
class Turn;

class GameManager {
    GameState *gameState;
    FileManager *fileManager;
    Dice *dice;
    Turn *turns;
    std::unique_ptr<Board> gameBoard;
    TextDisplay *td;
    bool seedInit = false;


    public:
    GameManager();
    void startGame();
    void gameOver(std::string winner);
    void createPlayers(int num);
    void createBoard(int boardSize);
    void startTurns();
    Board getGameBoard();
    void seed(int x);
    void load(std::string x);
    void board(std::string x);
    ~GameManager();
    friend class Turn;
};


#endif





