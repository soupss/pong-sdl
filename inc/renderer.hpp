#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>

class Renderer
{
    public:
        static void create(SDL_Window* _window); //create renderer for a window
        static void destroy();
        static void renderTexture();
        static void clear();
        static void present();
    private:
        inline static SDL_Renderer* renderer = nullptr;
};
#endif
