#include "Resources.hpp"
#include <iostream>

Resources::Resources()
{
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "Unable to initialize SDL lib SDL_image: " << IMG_GetError() << std::endl;
    }
}

Resources::~Resources()
{
    IMG_Quit();
}

SDL_Texture* Resources::loadTexture(std::string _path, SDL_Renderer* _renderer)
{
    SDL_Surface* loadedSurface = nullptr;
    SDL_Texture* texture = nullptr;
    loadedSurface = IMG_Load(_path.c_str());
    if(loadedSurface == NULL)
    {
        std::cerr << "Unable to load image " << _path.c_str() << ": " << IMG_GetError();
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
        if(loadedSurface == NULL)
        {
            std::cerr << "Unable to convert surface " << _path.c_str() << ": " << IMG_GetError();
        }
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}
