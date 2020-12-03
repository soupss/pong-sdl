#include "font.hpp"
#include <iostream>

TTF_Font* Font::loadFont(int _size)
{
    TTF_Font* loadedFont;
    loadedFont = TTF_OpenFont("res/fonts/bpdots.unicasesquare-bold.otf", _size);
    if(!loadedFont)
    {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
    }
    return loadedFont;
}

void Font::destroyFont(TTF_Font* _font)
{
    TTF_CloseFont(_font);
}
