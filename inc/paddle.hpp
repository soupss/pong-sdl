#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        const static int WIDTH = 15, HEIGHT = 90;
        inline int GET_WIDTH() const override {return WIDTH;}
        inline int GET_HEIGHT() const override {return HEIGHT;}
        void setY(float _y);
};
#endif
