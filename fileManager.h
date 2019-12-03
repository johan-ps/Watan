#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <string>
#include <fstream>

#include "./player/student.h"
#include "./developments/goal/achievement.h"
#include "./developments/criteria/assignment.h"
#include "board.h"
#include "gameState.h"

class FileManager {
    //std::string fileName;
    void readBoardFromString(std::string boardData, GameState &gameState);

    public:
    FileManager();
    void writeToFile(GameState &gameState, std::string fileName = "backup.sv");
    void readGameFromFile(GameState &gameState, std::string fileName = "backup.sv");
    void readBoardFromFile(GameState &gameState, std::string fileName = "backup.sv");
};

#endif





