#include <SDL2/SDL.h>
#include "Sprite.hpp"

Sprite::Sprite(int _x, int _y, SDL_Surface* _surface)
    :x(_x), y(_y), surface(_surface) {
    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;
}

Sprite::~Sprite() {
    SDL_FreeSurface(surface);
}
