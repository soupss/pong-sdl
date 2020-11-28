#include "ball.hpp"

Ball::Ball(float _x, float _y)
{
    pos.x = _x;
    pos.y = _y;
    vel.x = 0;
    vel.y = 0;
    //rect pos defined in Sprite::update
    rect = {0, 0, WIDTH, HEIGHT};
}

Ball::Ball()
{ }

Ball::~Ball()
{ }

void Ball::move()
{
    pos.x += speed * vel.x;
    pos.y += speed * vel.y;
}
