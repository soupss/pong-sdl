#include <iostream>
#include "renderer.hpp"

Renderer::Renderer()
    :renderer(nullptr)
{ }

Renderer::~Renderer()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(fontCache_texture);
    SDL_DestroyRenderer(renderer);
}

void Renderer::init(SDL_Window* _window)
{
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
    {
        std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
    }
}

void Renderer::loadFont(int _size)
{
    font = TTF_OpenFont("assets/fonts/bpdots.unicasesquare-bold.otf", _size);
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

void Renderer::renderText(std::string _text, int _x, int _y, SDL_Color _color)
{
    SDL_Texture* texture;
    //compare new text to font cache
    if(_text == fontCache_text)
    {
        //load texture from font cache
        texture = fontCache_texture;
    }
    else
    {
        //create new texture
        SDL_Surface* surface;
        surface = TTF_RenderText_Solid(font, _text.c_str(), _color);
        if(surface == NULL)
        {
            std::cerr << "Unable to render text surface: " << TTF_GetError() << std::endl;
        }
        else
        {
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if(texture == NULL)
            {
                std::cerr << "Unable to create texture from rendered text: " << TTF_GetError() << std::endl;
            }
            // update font cache
            fontCache_text = _text;
            fontCache_texture = texture;
        }
        SDL_FreeSurface(surface);
    }
    SDL_Rect rect;
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect = {_x, _y, w, h};
    renderTexture(texture, rect);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x5A, 0xFF, 0xCC);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}
