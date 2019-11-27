#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>

class Board;

class GameManager {
    // FileManager fileManager;
    // Turn curTurn;
    // Geese geese;
    Board *gameBoard;

    public:
    //void startGame();
    // void gameOver();
    // void createPlayers();
    // void createDice();
    // void createBoard();
    // void createFileManager();
    // void moveGeese();
    // void printPlayerStatus();
    // void startTurns();
    // void saveGame();
    Board getGameBoard();
    GameManager(int boardSize);
};

#endif
