#include "sprite.hpp"

void Sprite::update()
{
    rect.x = round(pos.x);
    rect.y = round(pos.y);
}
