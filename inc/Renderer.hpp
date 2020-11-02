#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>

class Renderer {
    public:
        Renderer();
        Renderer(SDL_Window* _window);
        ~Renderer();
        void clear();
        void render(SDL_Texture* _texture, const SDL_Rect* _srcRect, const SDL_Rect* _dstRect);
        void display();
    private:
        SDL_Renderer* renderer;
};
#endif
