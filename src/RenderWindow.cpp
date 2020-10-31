#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* _title, int _w, int _h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(_title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _w, _h, 0);
    if (window == NULL)
        std::cout << "Couldn't create window: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Texture* RenderWindow::loadTexture(const char* _filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, _filePath);
    if (texture == NULL)
        std::cout << "Failed to load texture: " << SDL_GetError() << std::endl;
    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* _tex)
{
    SDL_RenderCopy(renderer, _tex, NULL, NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
