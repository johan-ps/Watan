// #include "./assets/resources/resource.h"
// #include "./assets/resources/caffeine.h"
// #include "./assets/developments/development.h"
// #include "./assets/developments/criteria/criterion.h"
// #include "./assets/developments/criteria/assignment.h"
// #include "./assets/developments/goal/goal.h"
// #include "./assets/developments/goal/achievement.h"
//#include "resource.h"
//#include "./player/player.h"
//#include "board.h"
//#include "tile.h"
//#include "textDisplay.h"
#include "gameManager.h"

//#include "dice.h"
#include <iostream>

int main(int argc, char *argv[]) {

    GameManager mng;

    for (int i = 1; i < argc; i += 2) {
        if (std::string(argv[i]) == "-seed") {
            mng.seed(std::stoi(argv[i + 1]));
        } else if (std::string(argv[i]) == "-load") {
            mng.load(std::string(argv[i + 1]));
        } else if (std::string(argv[i]) == "-board") {
            mng.board(std::string(argv[i + 1]));
        } else {
            // other situations
        }
    }
    
    //bool restartGame = true;

    // END OF GAME NOT FULLY DONE; NEED TO PROB REFACTOR
    //while (restartGame){
        mng.startGame();

        // NEED TO FREE MEMORY AND STUFF
    //}

    //mng.getGameBoard().drawBoard();
    //b.drawBoard();
    // TextDisplay *td = new TextDisplay();
    // td->drawBoard();
}





