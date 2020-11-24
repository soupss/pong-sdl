#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>
#include "vector2f.hpp"

class Sprite
{
    public:
        Sprite() = default;
        virtual ~Sprite() = default;
        virtual void move() = 0; //defined in derived classes
        void update(); //update rect with new pos
        inline SDL_Rect* getRect() {return &rect;}
    protected:
        SDL_Rect rect;
        Vector2f pos;
        Vector2f vel;
};
#endif
