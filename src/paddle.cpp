#include "paddle.hpp"

Paddle::Paddle(float _x, float _y)
{
    pos.x = _x;
    pos.y = _y;
    //rect pos defined in Sprite::update()
    rect = {0, 0, WIDTH, HEIGHT};
}

Paddle::~Paddle()
{ }

void Paddle::move()
{
    pos.y += vel.y * speed;
}
