#include "paddle.hpp"

Paddle::Paddle()
    :vel(0)
{ }

void Paddle::move()
{
    pos.y += vel * speed;
}
