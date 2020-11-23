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

void Renderer::renderText(TTF_Font* _font, std::string _text, int _x, int _y, SDL_Color _color)
{
    SDL_Surface* surface;
    surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
    if(surface == NULL)
    {
        std::cerr << "Unable to render text surface: " << TTF_GetError() << std::endl;
    }
    else
    {
        SDL_Texture* texture;
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(texture == NULL)
        {
            std::cerr << "Unable to create texture from rendered text: " << TTF_GetError() << std::endl;
        }
        else
        {
            int w = surface->w;
            int h = surface->h;
            SDL_Rect rect = {_x - w/2, _y - h/2, w, h};
            renderTexture(texture, &rect);
        }
    }
    SDL_FreeSurface(surface);
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
