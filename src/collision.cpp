#include "collision.hpp"

bool Collision::check(const SDL_Rect& _a, const SDL_Rect& _b)
{
    int topA, bottomA, leftA, rightA;
    int topB, bottomB, leftB, rightB;

    topA = _a.y;
    bottomA = _a.y + _a.h;
    leftA = _a.x;
    rightA = _a.x + _a.w;

    topB = _b.y;
    bottomB = _b.y + _b.h;
    leftB = _b.x;
    rightB = _b.x + _b.w;

    //if any of the A sides are outside B
    if(leftA >= rightB)
    {
        return false;
    }
    if(rightA <= leftB)
    {
        return false;
    }
    if(topA >= bottomB)
    {
        return false;
    }
    if(bottomA <= topB)
    {
        return false;
    }
    return true;
}
