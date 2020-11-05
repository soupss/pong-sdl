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
                SDL_Texture* ballTexture = IMG_LoadTexture(renderer.get(), "res/gfx/ball.png");
                player1.init(paddleTexture);
                player2.init(paddleTexture);
                ball.init(ballTexture);
                int spacing = 100;
                player1.setPos(spacing, (SCREEN_HEIGHT/2)-(player1.getRect().h/2));
                player2.setPos(SCREEN_WIDTH+player2.getRect().w-spacing, (SCREEN_HEIGHT/2)-(player1.getRect().h/2));
                ball.setPos((SCREEN_WIDTH/2)-(ball.getRect().w/2), (SCREEN_HEIGHT/2)-(ball.getRect().h/2));
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
    renderer.render(player1.getTexture(), player1.getRect());
    renderer.render(player2.getTexture(), player2.getRect());
    renderer.render(ball.getTexture(), ball.getRect());
    renderer.present();
}
