#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <string>
#include <fstream>

#include "./player/student.h"
#include "./developments/goal/achievement.h"
#include "./developments/criteria/assignment.h"
#include "board.h"

class FileManager {
    //std::string fileName;

    public:
    FileManager();
    void writeToFile(std::string file);
    void readGameFromFile(std::string file);
    void readBoardFromFile(std::string file);
};

#endif
