#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include <list>
#include <memory>
#include "Renderer.hpp"
#include "Sprite.hpp"

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
        Renderer renderer;
        SDL_Event event;
        std::list<std::shared_ptr<Sprite>> sprites;
        bool running;
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
};
#endif
