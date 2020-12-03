#ifndef FONT_HPP
#define FONT_HPP
#include <SDL2/SDL_ttf.h>

struct Font
{
    static TTF_Font* loadFont(int _size);
    static void destroyFont(TTF_Font* _font);
};
#endif
