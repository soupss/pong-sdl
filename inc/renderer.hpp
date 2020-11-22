#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "colors.hpp"

class Renderer
{
    public:
        static void create(SDL_Window* _window); //create renderer for a window
        static void destroy();
        static void renderTexture(SDL_Texture* _texture, SDL_Rect* _rect);
        static void renderText(TTF_Font* _font, std::string _text, int _x, int _y, SDL_Color _color=Colors::FOREGROUND);
        static void clear(int _r, int _g, int _b, int _a=255);
        static void present();
    private:
        inline static SDL_Renderer* renderer = nullptr;
};
#endif
