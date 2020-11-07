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
                SDL_ShowCursor(SDL_DISABLE);
                //create renderer
                renderer.init(window);
                //init sprites
                const int edge = 50;
                const int paddleY = SCREEN_HEIGHT/2-Paddle::HEIGHT/2;
                player1.init(edge, paddleY);
                player2.init(SCREEN_WIDTH-Paddle::WIDTH-edge, paddleY);
                ball.init(SCREEN_WIDTH/2-Ball::WIDTH/2, SCREEN_HEIGHT/2-Ball::HEIGHT/2);
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
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
        else if(event.type == SDL_MOUSEMOTION){
            int mouseY;
            SDL_GetMouseState(NULL, &mouseY);
            int playerY = mouseY-player1.GET_HEIGHT()/2;
            const int bottom = SCREEN_HEIGHT - player1.GET_HEIGHT();
            if(playerY < 0)
            {
                playerY = 0;
            }
            else if(playerY > bottom)
            {
                playerY = bottom;
            }
            player1.setY(playerY);
        }
    }
}

void Game::update()
{
    player1.update();
    player2.update();
    ball.update();
}

void Game::draw()
{
    renderer.clear();
    renderer.render(player1.getRect());
    renderer.render(player2.getRect());
    renderer.render(ball.getRect());
    renderer.present();
}
