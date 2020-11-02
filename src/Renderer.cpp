#include <SDL2/SDL.h>
#include "Renderer.hpp"

//  default constructor for composition
Renderer::Renderer()
    :renderer(NULL)
{
}

Renderer::Renderer(SDL_Window* _window) {
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear() {

}

void Renderer::render(SDL_Texture* _texture, const SDL_Rect* _srcRect, const SDL_Rect* _dstRect) {
    SDL_RenderCopy(renderer, _texture, _srcRect, _dstRect);
}

void Renderer::display() {
    SDL_RenderPresent(renderer);
}
