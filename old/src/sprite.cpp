#include "sprite.hpp"

void Sprite::init(float _x, float _y)
{
    pos.x = _x;
    pos.y = _y;
    rect = {0, 0, GET_WIDTH(), GET_HEIGHT()};
}

void Sprite::update()
{
    rect.x = pos.x;
    rect.y = pos.y;
}
