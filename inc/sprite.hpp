#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>
#include "vector2f.hpp"

class Sprite
{
    public:
        void init(float _x, float _y);
        void update();
        SDL_Rect getRect() {return rect;}
    protected:
        SDL_Rect rect;
        Vector2f pos;
        virtual int GET_WIDTH() = 0;
        virtual int GET_HEIGHT() = 0;
};
#endif
