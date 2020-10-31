#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argc, char* argv[]) {
    //  init sdl, libs
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        std::cout << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "Unable to initialize SDL_Image: " << SDL_GetError() << std::endl;

    //  setup
    RenderWindow window("Pong", 720, 480);
    SDL_Texture* paddleTexture = window.loadTexture("res/gfx/paddle.png");

    //  game loop
    SDL_Event event;
    bool running = true;
    while(running) {
        //  events
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case(SDL_QUIT):
                    running = false;
                    break;
            }
        }
        window.clear();
        window.render(paddleTexture);
        window.display();
    }

    //  unload
    IMG_Quit();
    SDL_Quit();
    return 0;
}
