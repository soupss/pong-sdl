#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>

class Renderer
{
    public:
        static void create(SDL_Window* _window); //create renderer for a window
        static void destroy();
        static void renderTexture(SDL_Texture* _texture, SDL_Rect* _rect);
        static void clear(int _r, int _g, int _b, int _a=255);
        static void present();
    private:
        inline static SDL_Renderer* renderer = nullptr;
};
#endif
