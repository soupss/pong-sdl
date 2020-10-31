#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "Unable to initialize SDL_Image: " << SDL_GetError() << std::endl;

    SDL_Quit();
    return 0;
}
