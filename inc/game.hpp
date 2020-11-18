#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include "renderer.hpp"
#include "paddle.hpp"
#include "ball.hpp"

class Game
{
    public:
        Game();
        ~Game();
        inline bool isRunning() const {return running;}
        void events();
        void update();
        void draw();
    private:
        bool init();
        void handleInput();
        void handleCollisions();
        bool running;
        const int SCREEN_WIDTH, SCREEN_HEIGHT;
        SDL_Window* window;
        Renderer renderer;
        SDL_Event event;
        Paddle player1;
        Paddle player2;
        int p1_score;
        int p2_score;
        Ball ball;
};
#endif
