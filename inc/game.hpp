#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>

class Game
{
    public:
        Game(); //prepare game variables
        void run(); //start the game loop
    private:
        void quit(); //free memory and quit sdl+sdl libs
        bool init(); //initialize sdl+sdl libs
        SDL_Window* window; //defined in Game::init()
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
};
#endif
