#include "Sprite.hpp"

Sprite::Sprite()
{
}

Sprite::Sprite(int _x, int _y, SDL_Texture* _texture)
    :x(_x), y(_y), texture(_texture)
{
    rect->x = x;
    rect->y = y;
    //get texture size
    int textureW, textureH;
    SDL_QueryTexture(texture, NULL, NULL, &textureW, &textureH);
    rect->w = textureW;
    rect->h = textureH;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}
