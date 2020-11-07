#include "sprite.hpp"

void Sprite::init(float _x, float _y)
{
    pos.x = _x;
    pos.y = _y;
    rect = {0, 0, GET_WIDTH(), GET_HEIGHT()};
}

void Sprite::update()
{
    pos.x += vel.x;
    pos.y += vel.y;
    rect.x = pos.x;
    rect.y = pos.y;
}

void Sprite::setVel(float _x, float _y)
{
    vel.x = _x;
    vel.y = _y;
}
