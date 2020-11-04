#include <SDL2/SDL_image.h>
#include <iostream>
#include "Game.hpp"

Game::Game()
    :running(true)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
    }
    else
    {
        window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
        if(window == NULL)
        {
            std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        }
        else
        {
            if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
            {
                std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
            }
            else
            {
                std::cout << "init success\n";
                //sdl init success
                rendererObj.create(window);
                paddleTexture = IMG_LoadTexture(rendererObj.get(), "res/gfx/paddle.png");
                int paddleW, paddleH;
                SDL_QueryTexture(paddleTexture, NULL, NULL, &paddleW, &paddleH);
                paddleRect = {200, 100, paddleW, paddleH};
            }
        }
    }
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Game::events()
{
    while(SDL_PollEvent(&event) != 0)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
        }
    }
}

void Game::draw()
{
    rendererObj.clear();
    rendererObj.render(paddleTexture, paddleRect);
    rendererObj.present();
}
