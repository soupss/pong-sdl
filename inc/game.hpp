#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include <list>
#include <memory>
#include "renderer.hpp"
#include "paddle.hpp"
#include "ball.hpp"

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
        Paddle player1;
        Paddle player2;
        Ball ball;
        bool running;
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
};
#endif
