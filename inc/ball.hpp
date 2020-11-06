#ifndef BALL_HPP
#define BALL_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        const static int WIDTH = 15, HEIGHT = 15;
        Ball() = default;
        void init(int _x, int _y);
};
#endif
