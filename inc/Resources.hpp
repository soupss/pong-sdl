#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Resources
{
    public:
        Resources();
        ~Resources();
        SDL_Texture* loadTexture(std::string _path, SDL_Renderer* _renderer);
};
#endif
