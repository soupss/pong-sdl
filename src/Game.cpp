#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

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
                paddleTexture = IMG_LoadTexture(SDL_GetRenderer(window), "res/gfx/paddle.png");
                if(paddleTexture == NULL)
                int paddleW, paddleH;
                SDL_QueryTexture(paddleTexture, NULL, NULL, &paddleW, &paddleH);
                paddleRect = { 100, 100, paddleW, paddleH};
            }
        }
    }
}

Game::~Game()
{
    SDL_DestroyWindow(window);
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
    renderObj.clear();
    renderObj.render(paddleTexture, paddleRect);
    renderObj.present();
}
