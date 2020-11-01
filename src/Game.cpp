#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

Game::Game() {
    quit = false;
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        std::cout << "Unable to initialize SDL : " << SDL_GetError() << std::endl;
    }
    else {
        window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
        if(window == NULL) {
            std::cout << "Unable to create window: " << SDL_GetError() << std::endl;
        }
        else {
            screenSurface = SDL_GetWindowSurface(window);
        }
    }
}

Game::~Game() {
    SDL_DestroyWindow(window);
    //  dereference pointer
    window = NULL;
    SDL_Quit();
}

void Game::handle_events() {
    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        switch(e.type){
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
}
void Game::display() {
    SDL_UpdateWindowSurface(window);
}
