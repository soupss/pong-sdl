#include "game.hpp"
#include <iostream>
#include "sound.hpp"
#include "statehandler.hpp"
#include "renderer.hpp"
#include "timer.hpp"

Game::Game()
{
    if(!init())
    {
        std::cerr << "init failed\n";
    }
    else
    {
        //prepare
        Renderer::create(window);
        Sound::loadAll();
        //set the first state and change to it
        StateHandler::setNextState(States::TITLE);
        StateHandler::changeState();
    }
}

Game::~Game()
{
    Renderer::destroy();
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Game::run()
{
    Timer::start();
    while(StateHandler::getCurrentStateID() != States::QUIT)
    {
        StateHandler::getCurrentState()->events();
        //change state if needed
        StateHandler::changeState();
        StateHandler::getCurrentState()->update();
        StateHandler::getCurrentState()->render();
        Timer::countFrame();
    }
}

TTF_Font* Game::loadFont(int _size)
{
    TTF_Font* loadedFont;
    loadedFont = TTF_OpenFont("res/fonts/bpdots.unicasesquare-bold.otf", _size);
    if(!loadedFont)
    {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
    }
    return loadedFont;
}

void Game::destroyFont(TTF_Font* _font)
{
    TTF_CloseFont(_font);
}

bool Game::init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        success = false;
    }
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(window == NULL)
    {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        success = false;
    }
    //libs
    if(TTF_Init() == -1)
    {
        std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
        success = false;
    }
    success = Sound::init();
    //init success
    return success;
}
