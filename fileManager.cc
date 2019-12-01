#include "fileManager.h"
#include <iostream>
#include <sstream>

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

    std::string colour[4] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < 4; i++) {
        std::string studentData;
        getline(fin, studentData);
        std::istringstream sin {studentData};
        int numCaffeines, numLabs, numLectures, numStudies, numTutorials;
        std::vector<Goal*> goals;
        std::vector<Criterion*> criteria;
        
        sin >> numCaffeines;
        sin >> numLabs;
        sin >> numLectures;
        sin >> numStudies;
        sin >> numTutorials;

        int input;
        std::string specifier;
        sin >> specifier;
        while (true) {
            if (sin >> input) {
                goals.emplace_back(new Achievement{input});
            } else {
                if (sin.eof()) {
                    break;
                } else if (sin.fail()) {
                    sin.clear();
                    sin.ignore();
                    break;
                }
            }
        }
        sin >> specifier;
        while (true) {
            if (sin >> input) {
                int type;
                sin >> type;
                if (type == 1) {
                    criteria.emplace_back(new Assignment{input});
                } else if (type == 2) {
                    criteria.emplace_back(new Assignment{input});
                } else {
                    criteria.emplace_back(new Assignment{input});
                }

                
            } else {
                if (sin.eof()) {
                    break;
                } else if (sin.fail()) {
                    sin.clear();
                    sin.ignore();
                    break;
                }
            }
        }

        players.emplace_back(new Student{colour[i]});
    }

    //Board *board;

// <curTurn>
// <student0Data> : <numCaffeines> <numLabs> <numLectures> <numStudies> <numTutorials> g <goals> c <criteria>
// <student1Data>
// <student2Data>
// <student3Data>
// <board>
// <geese>
}