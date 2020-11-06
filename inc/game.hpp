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
        void update();
        void draw();
        bool isRunning() {return running;}
    private:
        bool running;
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
        SDL_Window* window;
        Renderer renderer;
        SDL_Event event;
        Paddle player1;
        Paddle player2;
        Ball ball;
};
#endif
