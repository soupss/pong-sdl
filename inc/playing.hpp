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
        TTF_Font* font;
        //pointers to sprite base class
        //defined in Playing::Playing()
        Paddle* player1;
        Paddle* player2;
        Ball* ball;
};
#endif
