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
        inline static int GET_SCREEN_WIDTH() {return SCREEN_WIDTH;}
        inline static int GET_SCREEN_HEIGHT() {return SCREEN_HEIGHT;}
    private:
        bool init(); //initialize sdl+sdl libs
        SDL_Window* window; //defined in Game::init()
        static const int SCREEN_WIDTH = 1100;
        static const int SCREEN_HEIGHT = 600;
};
#endif
