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

void Renderer::renderTexture(SDL_Texture* _texture, SDL_Rect* _rect)
{
    SDL_RenderCopy(renderer, _texture, nullptr, _rect);
}

void Renderer::clear(int _r, int _g, int _b, int _a)
{
    //blue
    SDL_SetRenderDrawColor(renderer, _r, _g, _b, _a);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}
