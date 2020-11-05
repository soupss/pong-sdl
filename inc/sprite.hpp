#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>

class Sprite
{
    public:
        Sprite(SDL_Texture* _texture, int _x, int _y);
        ~Sprite();
        SDL_Rect getRect() {return rect;}
        SDL_Texture* getTexture() {return texture;}
    private:
        SDL_Texture* texture;
        SDL_Rect rect;
};
#endif
