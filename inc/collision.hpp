#ifndef COLLISION_HPP
#define COLLISION_HPP
#include <SDL2/SDL.h>
#include "vector2f.hpp"

struct Collision
{
    static bool check(const SDL_Rect* _rectA, const Vector2f* _posA, const SDL_Rect* _rectB, const Vector2f* _posB);
};

#endif
