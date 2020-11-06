#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        const static int WIDTH = 15, HEIGHT = 90;
        Paddle() = default;
        void init(int _x, int _y);
};
#endif
