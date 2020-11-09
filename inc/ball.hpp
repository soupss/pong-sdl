#ifndef BALL_HPP
#define BALL_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        const static int WIDTH = 15, HEIGHT = 15;
        inline int GET_WIDTH() const override {return WIDTH;}
        inline int GET_HEIGHT() const override {return HEIGHT;}
};
#endif
