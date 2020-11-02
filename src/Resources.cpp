#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "Resources.hpp"

Resources::Resources() {
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "Unable to initialize SDL lib SDL_image: " << IMG_GetError() << std::endl;
    }
}

Resources::~Resources() {
    IMG_Quit();
}

SDL_Surface* Resources::loadSurface(std::string path, SDL_Surface* _screenSurface) {
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL) {
        std::cerr << "Unable to load image " << path.c_str() << ": " << IMG_GetError();
    }
    else {
        optimizedSurface = SDL_ConvertSurface(loadedSurface, _screenSurface->format, 0);
        if(loadedSurface == NULL) {
            std::cerr << "Unable to optimize image " << path.c_str() << ": " << IMG_GetError();
        }
        SDL_FreeSurface(loadedSurface);
    }
    return optimizedSurface;
}
