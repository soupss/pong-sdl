#include "ball.hpp"
#include <cstdlib>
#include <ctime>
#include "game.hpp"

Ball::Ball(float _x, int _maxY)
{
    //rect pos defined in Sprite::update
    rect = {0, 0, WIDTH, HEIGHT};
    bounces = 0;
    speed = baseSpeed;
    //initialize srand
    srand(time(NULL));
    pos.x = _x;
    //randmize Y position and direction
    pos.y = rand() % _maxY;
    dir.x = (rand() % 2) ? 1 : -1;
    dir.y = (rand() % 2) ? 1 : -1;
}

Ball::Ball()
{
}

Ball::~Ball()
{ }

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

void Ball::up()
{
    dir.y = -1;
    increaseSpeed();
}

void Ball::down()
{
    dir.y = 1;
    increaseSpeed();
}

void Ball::left()
{
    dir.x = -1;
    increaseSpeed();
}

void Ball::right()
{
    dir.x = 1;
    increaseSpeed();
}

void Ball::increaseSpeed()
{
    if(bounces < 20)
    {
        speed *= 1.015f;
    }
    ++bounces;
}
