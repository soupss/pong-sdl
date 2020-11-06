#include <iostream>
#include "renderer.hpp"

Renderer::Renderer()
    :renderer(nullptr)
{ }

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}

void Renderer::init(SDL_Window* _window)
{
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Renderer::render(SDL_Rect _rect)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &_rect);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}
