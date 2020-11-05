#include "game.hpp"

int main(int argc, char* argv[])
{
    Game game;
    while(game.isRunning())
    {
        game.events();
        game.draw();
    }
    return 0;
}
