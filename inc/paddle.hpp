#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        const static int WIDTH = 15, HEIGHT = 90;
        int GET_WIDTH() override {return WIDTH;}
        int GET_HEIGHT() override {return HEIGHT;}
};
#endif
