#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>

class Sprite
{
    public:
        Sprite() = default;
        ~Sprite();
        void init(SDL_Texture* _texture);
        void setPos(int _x, int _y);
        SDL_Rect getRect() {return rect;}
        SDL_Texture* getTexture() {return texture;}
    protected:
        SDL_Texture* texture;
        SDL_Rect rect;
};
#endif
