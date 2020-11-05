#include <SDL2/SDL_image.h>
#include <iostream>
#include "game.hpp"

Game::Game()
    :running(true), SCREEN_WIDTH(800), SCREEN_HEIGHT(600)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
    }
    else
    {
        window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
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
                //create renderer
                renderer.init(window);
                SDL_Texture* paddleTexture = IMG_LoadTexture(renderer.get(), "res/gfx/paddle.png");
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
    renderer.clear();
    for(std::shared_ptr<Sprite> sprite:sprites)
    {
        renderer.render(sprite->getTexture(), sprite->getRect());
    }
    renderer.present();
}
