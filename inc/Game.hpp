#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include "Renderer.hpp"

class Game
{
    public:
        Game();
        ~Game();
        void events();
        void draw();
        bool isRunning() {return running;}
    private:
        SDL_Window* window;
        Renderer rendererObj;
        SDL_Event event;
        SDL_Texture* paddleTexture;
        SDL_Rect paddleRect;
        bool running;
};
#endif
