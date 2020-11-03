#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>

class Sprite
{
    public:
        Sprite();
        Sprite(int _x, int _y, SDL_Texture* _texture);
        ~Sprite();
        SDL_Texture* getTexture() {return texture;}
        SDL_Rect* getRect() {return rect;}
    protected:
        int x, y;
        SDL_Texture* texture;
        SDL_Rect* rect;
};
#endif
