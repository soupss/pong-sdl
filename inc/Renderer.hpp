#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>

class Renderer
{
    public:
        Renderer() = default;
        ~Renderer();
        void create(SDL_Window* _window);
        void clear();
        void render(SDL_Texture* _texture, SDL_Rect _rect);
        void present();
        SDL_Renderer* get() {return renderer;}
    private:
        SDL_Renderer* renderer;
};
#endif
