// #include "./assets/resources/resource.h"
// #include "./assets/resources/caffeine.h"
// #include "./assets/developments/development.h"
// #include "./assets/developments/criteria/criterion.h"
// #include "./assets/developments/criteria/assignment.h"
// #include "./assets/developments/goal/goal.h"
// #include "./assets/developments/goal/achievement.h"
#include "board.h"
//#include "tile.h"
#include "textDisplay.h"
#include "gameManager.h"

int main() {
    GameManager mng {19};
    mng.getGameBoard().drawBoard();
    TextDisplay *td = new TextDisplay();
    td->drawBoard();
}