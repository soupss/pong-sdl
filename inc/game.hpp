#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Game
{
    public:
        Game(); //prepare game variables
        ~Game(); //free memory and quit sdl+sdl libs
        void run(); //start the game loop
        static TTF_Font* loadFont(int _size);
        static void destroyFont(TTF_Font* _font);
    private:
        bool init(); //initialize sdl+sdl libs
        SDL_Window* window; //defined in Game::init()
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
};
#endif
