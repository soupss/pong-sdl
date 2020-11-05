#include "sprite.hpp"

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::init(SDL_Texture* _texture)
{
    texture = _texture;
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect = {0, 0, w, h};
}
void Sprite::setPos(int _x, int _y)
{
    rect.x = _x;
    rect.y = _y;
}
