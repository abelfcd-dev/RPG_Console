#include <iostream>
#include <ctime>
#include "Game.h"



int main() {
    srand(time(NULL));

    Game game;
    game.Initialize();
    game.Loop();
    game.Shutdown();
    return 0;
}