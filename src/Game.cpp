#include "Game.hpp"
#include <iostream>

Game::Game()
    :resourceManager(ResourceManager())
{
    quit = false;
    //  init sdl
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        std::cerr << "Unable to initialize SDL : " << SDL_GetError() << std::endl;
    }
    else
    {
        //  create window
        window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
        if(window == NULL)
        {
            std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
        }
        else
        {
            //  no errors
            screenSurface = SDL_GetWindowSurface(window);
            renderer = Renderer(window);
            //  create sprites
            SDL_Texture* paddleTexture = resourceManager.loadTexture("res/gfx/paddle.png", renderer.get());
            player1 = Paddle(0, 0, paddleTexture);
            //  define screen rect
            SDL_DisplayMode dm;
            SDL_GetCurrentDisplayMode(0, &dm);
            screenRect->w = dm.w;
            screenRect->h = dm.h;
            screenRect->x = screenRect->y = 0;
        }
    }
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}

void Game::handleEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
}

void Game::draw()
{
    renderer.clear();
    renderer.render(player1.getTexture(), player1.getRect(), screenRect);
    renderer.display();
}
