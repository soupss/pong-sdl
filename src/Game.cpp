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
                SDL_Texture* paddleTexture = IMG_LoadTexture(rendererObj.get(), "res/gfx/paddle.png");
                /* sprites.push_back(new Sprite(paddleTexture, 10, 100)); */
                std::shared_ptr<Sprite> player1 = std::make_shared<Sprite>(paddleTexture, 10, 100);
                sprites.push_back(player1);
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
    for(std::shared_ptr<Sprite> sprite:sprites)
    {
        rendererObj.render(sprite->getTexture(), sprite->getRect());
    }
    rendererObj.present();
}
