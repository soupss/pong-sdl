#ifndef PLAYING_HPP
#define PLAYING_HPP
#include <SDL2/SDL_ttf.h>
#include "gamestate.hpp"
#include "paddle.hpp"
#include "ball.hpp"

class Playing : public GameState
{
    public:
        Playing();
        ~Playing() override;
        void events() override;
        void update() override;
        void render() override;
    private:
        void handleInput();
        void constraintPaddles(); //constraint paddles to screen
        void constraintBall(); //constraint ball to screen
        TTF_Font* font;
        Paddle* player1;
        Paddle* player2;
        Ball* ball;
};
#endif
