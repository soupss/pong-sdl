#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>

class Game
{
    public:
        Game(); //prepare game variables
        void run(); //start the game loop
    private:
        bool init(); //initialize SDL and SDL libs
        SDL_Window* window; //defined in Game::init()
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
};
#endif
