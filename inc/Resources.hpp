#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Resources {
    public:
        Resources();
        ~Resources();
        SDL_Surface* loadSurface(std::string path, SDL_Surface* _screenSurface);
};
#endif
