#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>

class Renderer
{
    public:
        Renderer();
        ~Renderer();
        //cant be created in constructor since it needs a window, which is not created when constructor is called
        void init(SDL_Window* _window);
        void clear();
        void render(SDL_Rect _rect);
        void present();
    private:
        SDL_Renderer* renderer;
};
#endif
