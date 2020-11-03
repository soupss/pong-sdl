#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include "Game.hpp"
#include "Renderer.hpp"
#include "ResourceManager.hpp"
#include "Paddle.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void handleEvents();
        void draw();
        bool hasQuit() {return quit;}
    private:
        SDL_Window* window;
        SDL_Surface* screenSurface;
        SDL_Rect* screenRect;
        ResourceManager resourceManager;
        Renderer renderer;
        Paddle player1;
        /* Paddle player2; */
        bool quit;
};
#endif
