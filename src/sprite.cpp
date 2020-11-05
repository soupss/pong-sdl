#include "sprite.hpp"

Sprite::Sprite(SDL_Texture* _texture, int _x, int _y)
    :texture(_texture)
{
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect = {_x, _y, w, h};
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}
