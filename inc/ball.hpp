#ifndef BALL_HPP
#define BALL_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        const static int WIDTH = 15, HEIGHT = 15;
        int GET_WIDTH() override {return WIDTH;}
        int GET_HEIGHT() override {return HEIGHT;}
};
#endif
