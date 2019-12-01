#include "fileManager.h"
#include <iostream>

FileManager::FileManager() {

}

void FileManager::writeToFile(std::string file) {

}

void FileManager::readBoardFromFile(std::string file) {
    std::ifstream fileName {file};
    //std::cout << "Load board from file 2: " << file << std::endl;
}

void FileManager::readGameFromFile(std::string file) {
    std::ifstream fin {file};
    //std::cout << "Load saved game from file 2: " << file << std::endl;
    int curTurn;
    fin >> curTurn;

    std::vector<Player*> players;

    for (int i = 0; i < 4; i++) {
        std::string studentData;
        getline(fin, studentData);
        std::string numCaffeines, numLabs, numLectures, numStudies, numTutorials;
        
        //players.emplace_back(new Player{})
    }

// <curTurn>
// <student0Data> : <numCaffeines> <numLabs> <numLectures> <numStudies> <numTutorials> g <goals> c <criteria>
// <student1Data>
// <student2Data>
// <student3Data>
// <board>
// <geese>
}