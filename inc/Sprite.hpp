#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

class Sprite {
    public:
        Sprite(int _x, int _y, SDL_Surface* _surface);
        ~Sprite();
    protected:
        int x, y;
        SDL_Rect rect;
        SDL_Surface* surface;
};
#endif
