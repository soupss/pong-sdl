#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>
#include "vector2f.hpp"

class Sprite
{
    public:
        void init(float _x, float _y);
        void update();
        inline SDL_Rect getRect() const {return rect;}
        inline Vector2f getPos() const {return pos;}
    protected:
        SDL_Rect rect;
        Vector2f pos;
        virtual int GET_WIDTH() const = 0;
        virtual int GET_HEIGHT() const = 0;
};
#endif
