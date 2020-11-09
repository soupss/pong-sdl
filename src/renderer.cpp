#include <iostream>
#include "renderer.hpp"

Renderer::Renderer()
    :renderer(nullptr)
{ }

Renderer::~Renderer()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
}

void Renderer::init(SDL_Window* _window)
{
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
    }
}

void Renderer::loadFont(int _size)
{
    font = TTF_OpenFont("res/fonts/bpdots.unicasesquare-bold.otf", _size);
    if(!font)
    {
        std::cerr << "Unable to load font: " << TTF_GetError() << std::endl;
    }
}

void Renderer::renderRect(SDL_Rect _rect)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &_rect);
}

void Renderer::renderTexture(SDL_Texture* _texture, SDL_Rect _rect)
{
    SDL_RenderCopy(renderer, _texture, NULL, &_rect);
}

void Renderer::renderText(const char* _text, int _x, int _y, SDL_Color _color)
{
    SDL_Surface* surface;
    surface = TTF_RenderText_Solid(font, _text, _color);
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
            SDL_Rect rect;
            rect = {_x, _y, surface->w, surface->h};
            renderTexture(texture, rect);
        }
    }
    SDL_FreeSurface(surface);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}
