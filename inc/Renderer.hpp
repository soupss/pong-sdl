#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>

class Renderer
{
    public:
        Renderer() = default;
        Renderer(SDL_Window* _window);
        ~Renderer();
        void clear();
        void render(SDL_Texture* _texture, SDL_Rect _rect);
        void present();
    private:
        SDL_Renderer* renderer;
};
#endif
