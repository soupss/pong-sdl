#include "renderer.hpp"
#include <iostream>

void Renderer::create(SDL_Window* _window)
{
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        std::cerr  << "Unable to create renderer :" << SDL_GetError() << std::endl;
    }
}

void Renderer::destroy()
{
    SDL_DestroyRenderer(renderer);
}

void Renderer::renderTexture()
{
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x5A, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}
