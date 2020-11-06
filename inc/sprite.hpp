#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>

class Sprite
{
    public:
        Sprite() = default;
        ~Sprite() = default;
        virtual void init(int _x, int _y, int _w, int _h);
        SDL_Rect getRect() {return rect;}
    protected:
        SDL_Rect rect;
};
#endif
