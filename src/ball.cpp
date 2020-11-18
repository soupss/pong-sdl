#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ball.hpp"

Ball::Ball()
{
    srand(time(NULL));
}

void Ball::randDir()
{
    dir.x = (rand() % 2) ? 1 : -1;
    dir.y = (rand() % 2) ? 1 : -1;
}

void Ball::move()
{
    pos.x += speed * dir.x;
    pos.y += speed * dir.y;
}

void Ball::back()
{
    pos.x -= speed * dir.x;
    pos.y -= speed * dir.y;
}

void Ball::respawn(int _x, int _y)
{
    pos.x = _x;
    pos.y = _y;
}
