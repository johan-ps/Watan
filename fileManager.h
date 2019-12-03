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
    void writeToFile(std::string fileName, GameState &gameState);
    void readGameFromFile(std::string fileName, GameState &gameState);
    void readBoardFromFile(std::string fileName, GameState &gameState);
};

#endif
