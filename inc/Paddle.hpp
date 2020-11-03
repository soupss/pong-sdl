#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SDL2/SDL.h>
#include "Sprite.hpp"

class Paddle : public Sprite
{
    public:
        Paddle();
        Paddle(int _x, int _y, SDL_Texture* _texture);
};
#endif
