#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>
#include "vector2f.hpp"

class Sprite
{
    public:
        Sprite() = default;
        virtual ~Sprite() = default;
        virtual void move() = 0; //calculate pos, defined in derived class
        void update(); //update rect with new pos
        inline SDL_Rect* getRect() {return &rect;}
        inline Vector2f* getPos() {return &pos;}
        inline void setY(float _y) {pos.y = _y;}
    protected:
        SDL_Rect rect;
        Vector2f pos;
        Vector2f dir;
        float speed;
};
#endif
