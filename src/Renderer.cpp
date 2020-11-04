#include "Renderer.hpp"

Renderer::Renderer(SDL_Window* _window)
{
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}

void Renderer::clear()
{
    SDL_RenderClear(renderer);
}

void Renderer::render(SDL_Texture* _texture, SDL_Rect _rect)
{
    SDL_RenderCopy(renderer, _texture, NULL, &_rect);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}
