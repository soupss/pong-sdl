#include "Game.hpp"

int main(int argc, char* args[])
{
    Game game;
    while(game.isRunning())
    {
        game.events();
        game.draw();
    }
    return 0;
}
