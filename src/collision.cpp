#include "collision.hpp"

bool Collision::check(const SDL_Rect* _rectA, const Vector2f* _posA, const SDL_Rect* _rectB, const Vector2f* _posB)
{
    int topA, bottomA, leftA, rightA;
    int topB, bottomB, leftB, rightB;

    topA = _posA->y;
    bottomA = _posA->y + _rectA->h;
    leftA = _posA->x;
    rightA = _posA->x + _rectA->w;

    topB = _posB->y;
    bottomB = _posB->y + _rectB->h;
    leftB = _posB->x;
    rightB = _posB->x + _rectB->w;

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
