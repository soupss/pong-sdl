#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include "Game.hpp"
#include "Renderer.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void handleEvents();
        void display();
        bool hasQuit(){ return quit; }
    private:
        bool quit;
        SDL_Window* window;
        SDL_Surface* screenSurface;
        Renderer renderer;
};
#endif
