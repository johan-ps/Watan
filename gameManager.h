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
//#include "resources.h"
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
    ~GameManager();
    friend class Turn;
};


#endif
