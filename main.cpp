#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Stack.hpp"
#include "GameClasses.hpp"
#include "GameLogic.hpp"
#include "MoveManager.hpp"

using namespace std;

int main(){
    //using srand(), rand() because the c++ random library was inconveniently predictable when I was testing this segment
    srand(time(NULL));
    vector<Actor*> actors;

    setupGame(actors);
    game(actors[0], actors[1]);

}
