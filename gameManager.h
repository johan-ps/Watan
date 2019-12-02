#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "./player/student.h"
#include "fileManager.h"
#include "dice.h"
#include "turn.h"

class Turn;
class Board;

struct GameState {
    std::vector<std::unique_ptr<Player>> players;
    std::vector<int> values;
    std::vector<int> resourceTypes;

}

class GameManager {
    FileManager *fileManager;
    Dice *dice;
    Turn *curTurn;
    // Geese geese;
    std::unique_ptr<Board> gameBoard;
    std::vector<std::unique_ptr<Player>> players;


    public:
    GameManager();
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
    void seed(int x);
    void load(std::string x);
    void board(std::string x);
    friend class Turn;
};


#endif
