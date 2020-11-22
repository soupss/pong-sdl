#include "title.hpp"
#include <SDL2/SDL.h>
#include "statehandler.hpp"
#include "renderer.hpp"
#include "game.hpp"

Title::Title()
{
    font = Game::loadFont(50);
}

Title::~Title()
{
    Game::destroyFont(font);
}

void Title::events()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            StateHandler::setNextState(States::QUIT);
        }
        //if enter or space is pressed
        if(event.type == SDL_KEYDOWN &&
                (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE))
        {
            StateHandler::setNextState(States::MENU);
        }
    }
}

void Title::update()
{
}

void Title::render()
{
    Renderer::clear(0, 0, 255);
    Renderer::renderText(font, "aaa", 100, 100);
    Renderer::present();
}
