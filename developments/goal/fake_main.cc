#include "goal.h"
#include "achievement.h"
//#include "../../player/player.h"
#include "../../player/student.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    Achievement achievement_test(0);

    // A player wants to achieve an unset achievement
    Student s {"Blue"};

    //achievement_test.achieve(&s);

    // try to achieve again, even though achievement is now set (shouldn't work)

    // try{
    //     achievement_test.achieve(&s);
    // }
    // catch (...){
    //     cout << "ACHIEVEMENT FAILED" << endl;
    // }
    
    return 0;
}





