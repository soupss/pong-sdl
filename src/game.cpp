#include "game.hpp"
#include <iostream>
#include "statehandler.hpp"

Game::Game()
    :SCREEN_WIDTH(1100), SCREEN_HEIGHT(600)
{
    if(!init())
    {
        std::cerr << "init failed\n";
    }
    else
    {
        //set the first state and change to it
        StateHandler::setNextState(States::TITLE);
        StateHandler::changeState();
    }
}

void Game::run()
{
    while(StateHandler::getCurrentStateID() != States::QUIT)
    {
        StateHandler::getCurrentState()->events();
        StateHandler::getCurrentState()->update();
        StateHandler::getCurrentState()->render();
        //change state if needed
        StateHandler::changeState();
    }
}

bool Game::init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if(window == NULL)
        {
            std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            //libs
        }
    }
    return success;
}
