#include "fileManager.h"
#include <iostream>
#include <sstream>
#include <memory>

FileManager::FileManager() {

}

void FileManager::writeToFile(std::string file) {

}

void FileManager::readBoardFromFile(std::string fileName, GameState &gameState) {
    std::ifstream file {fileName};
    //std::cout << "Load board from file 2: " << file << std::endl;

    std::string boardData;
    getline(file, boardData);
    std::istringstream sin {boardData};

    while (true){
        int resourceType = -1;
        if (sin >> resourceType) {
            // Add in resourceType to next tile in GameState
            gameState.resourceTypes.emplace_back(resourceType);

            int tileValue = -1;
            if (sin >> tileValue){
                // Add in tileValue to next tile in GameState
                gameState.values.emplace_back(tileValue);
            }
            else {
                if (sin.eof()) {
                    break;
                }
                else if (sin.fail()) {
                    sin.clear();
                    sin.ignore();
                    break;
                }
            }

        } 
        else {
            if (sin.eof()) {
                break;
            } 
            else if (sin.fail()) {
                sin.clear();
                sin.ignore();
                break;
            }
        }
    }

}


void FileManager::readGameFromFile(std::string fileName, GameState &gameState) {
    std::ifstream fin {fileName};
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

        gameState.players.emplace_back(new Student{colour[i], criteria, goals, {numCaffeines, numLabs, numLectures, numStudies, numTutorials}});        
    }

    //Board *board;

    // read in geese

// <curTurn>
// <student0Data> : <numCaffeines> <numLabs> <numLectures> <numStudies> <numTutorials> g <goals> c <criteria>
// <student1Data>
// <student2Data>
// <student3Data>
// <board> : 0 3 1 10 3 5 1 4 5 7 3 10 2 11 0 3 3 8 0 2 0 6 1 8 4 12 1 5 4 11 2 4 4 6 2 9 2 9
// <geese>
}