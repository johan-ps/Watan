#include "fileManager.h"
#include <iostream>
#include <sstream>
#include <memory>

FileManager::FileManager() {

}

void FileManager::writeToFile(GameState &gameState, std::string fileName) {
    std::ofstream fout {fileName};
    fout << gameState.curTurn << std::endl;
    for (auto &player : gameState.players) {
        for (auto resources : player->getResources()) {
            fout << resources << " ";
        }
        fout << "g";
        for (auto &goals : player->getGoals()) {
            fout << " " << goals->getLocationVal();
        }
        fout << " c";
        for (auto criteria : player->getCriterion()) {
            fout << " " << criteria->getLocationVal();
            fout << " " << criteria->getCriteriaVal();
        }
        fout << std::endl;
    }
    for (unsigned int i = 0; i < gameState.values.size(); i++) {
        fout << " " << gameState.resourceTypes.at(i).getVal();
        fout << " " << gameState.values.at(i);
    }
    fout << std::endl;
    if (gameState.gooseTile != -1) {
        fout << gameState.gooseTile << std::endl;
    }
}

void FileManager::readBoardFromString(std::string boardData, GameState &gameState) {
    std::istringstream sin {boardData};
    
    while (true){
        int resourceType = -1;
        if (sin >> resourceType) {
            // Add in resourceType to next tile in GameState
            if (resourceType == 0) {
                gameState.resourceTypes.emplace_back(Resource{"CAFFEINE"});
            } else if (resourceType == 1) {
                gameState.resourceTypes.emplace_back(Resource{"LAB"});
            } else if (resourceType == 2) {
                gameState.resourceTypes.emplace_back(Resource{"LECTURE"});
            } else if (resourceType == 3) {
                gameState.resourceTypes.emplace_back(Resource{"STUDY"});
            } else if (resourceType == 4) {
                gameState.resourceTypes.emplace_back(Resource{"TUTORIAL"});
            } else {
                gameState.resourceTypes.emplace_back(Resource{"NETFLIX"});
            }

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

void FileManager::readBoardFromFile(GameState &gameState, std::string fileName) {
    std::ifstream file {fileName};

    std::string boardData;
    getline(file, boardData);
    
    readBoardFromString(boardData, gameState);
}


void FileManager::readGameFromFile(GameState &gameState, std::string fileName) {
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
                criteria.emplace_back(new Assignment{std::stoi(input), type});       
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
        std::vector<Criterion*> tempCriteria;
        std::vector<Goal*> tempGoal;
        Player *tempPlayer = new Student{colour[i], tempCriteria, tempGoal, {numCaffeines, numLabs, numLectures, numStudies, numTutorials}};
        for (auto criterion : criteria) {
            int temp = criterion->getCriteriaVal();
            criterion->complete(tempPlayer, true);
            criterion->setCriteriaVal(temp);
        }
        for (auto goal : goals) {
            goal->achieve(tempPlayer, true);
        }
        gameState.players.emplace_back(tempPlayer);
    }

    std::string boardData;
    getline(fin, boardData);
    readBoardFromString(boardData, gameState);

    int gooseTile;
    fin >> gooseTile;
    if (!fin) {
        gameState.gooseTile = -1;
    } else {
        gameState.gooseTile = gooseTile;
    }
    gameState.geese = new Geese{};

}





