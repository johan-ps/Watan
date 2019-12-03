#include "fileManager.h"
#include <iostream>
#include <sstream>
#include <memory>

FileManager::FileManager() {

}

void FileManager::writeToFile(std::string file) {

}

void FileManager::readBoardFromString(std::string boardData, GameState &gameState) {
    std::istringstream sin {boardData};
    
    while (true){
        int resourceType = -1;
        if (sin >> resourceType) {
            // Add in resourceType to next tile in GameState
            if (resourceType == 0) {
                gameState.resourceTypes.emplace_back("CAFFEINE");
            } else if (resourceType == 1) {
                gameState.resourceTypes.emplace_back("LAB");
            } else if (resourceType == 2) {
                gameState.resourceTypes.emplace_back("LECTURE");
            } else if (resourceType == 3) {
                gameState.resourceTypes.emplace_back("STUDY");
            } else if (resourceType == 4) {
                gameState.resourceTypes.emplace_back("TUTORIAL");
            } else {
                gameState.resourceTypes.emplace_back("NETFLIX");
            }

            int tileValue = -1;
            if (sin >> tileValue){
                // Add in tileValue to next tile in GameState
                gameState.values.emplace_back(tileValue < 10 ? " " + std::to_string(tileValue) : std::to_string(tileValue));
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

void FileManager::readBoardFromFile(std::string fileName, GameState &gameState) {
    std::ifstream file {fileName};

    std::string boardData;
    getline(file, boardData);
    
    readBoardFromString(boardData, gameState);
}


void FileManager::readGameFromFile(std::string fileName, GameState &gameState) {
    std::ifstream fin {fileName};

    fin >> gameState.curTurn;

    std::string studentData;
    getline(fin, studentData);
    
    std::vector<Player*> players;

    std::string colour[4] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < 4; i++) {
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

        std::string input;
        while (true) {
            if (sin >> input) {
                if (input == "g") {
                    continue;
                } else if (input == "c") {
                    break;
                } else {
                    goals.emplace_back(new Achievement{std::stoi(input)});
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
        while (true) {
            if (sin >> input) {
                int type;
                sin >> type;
                if (type == 1) {
                    criteria.emplace_back(new Assignment{std::stoi(input)});
                } else if (type == 2) {
                    criteria.emplace_back(new Assignment{std::stoi(input)});
                } else {
                    criteria.emplace_back(new Assignment{std::stoi(input)});
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
        Player *tempPlayer = new Student{colour[i], criteria, goals, {numCaffeines, numLabs, numLectures, numStudies, numTutorials}};
        for (auto criterion : criteria) {
            criterion->complete(tempPlayer, true);
        }
        for (auto goal : goals) {
            goal->achieve(tempPlayer, true);
        }
        gameState.players.emplace_back(tempPlayer);      
    }

    std::string boardData;
    getline(fin, boardData);
    readBoardFromString(boardData, gameState);

    fin >> gameState.gooseTile;


}