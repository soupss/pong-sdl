#ifndef COLLISION_HPP
#define COLLISION_HPP
#include <SDL2/SDL.h>

struct Collision
{
    static bool check(const SDL_Rect& _a, const SDL_Rect& _b);
};
#endif
