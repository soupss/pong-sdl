#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class ResourceManager
{
    public:
        ResourceManager();
        ~ResourceManager();
        SDL_Texture* loadTexture(const std::string _path, SDL_Renderer* _renderer);
};
#endif
