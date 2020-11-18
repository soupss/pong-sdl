#include "game.hpp"
#include "timer.hpp"

int main(int argc, char* argv[])
{
    Game game;
    while(game.isRunning())
    {
        game.events();
        if(!game.isPaused())
        {
            game.update();
        }
        game.draw();
        //to calculate fps
        Timer::countFrame();
    }
    return 0;
}
