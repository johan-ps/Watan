#include <string>

class GameManager {
    std::string fileName;

    public:
    void startGame();
    void gameOver();
    void createPlayers();
    void createDice();
    void createBoard();
    void createFileManager();
    void moveGeese();
    void printPlayerStatus();
    void startTurns();
    void saveGame();
}