#include "menu.hpp"
#include <SDL2/SDL.h>
#include "statehandler.hpp"
#include "renderer.hpp"

void Menu::events()
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
            StateHandler::setNextState(States::TITLE);
        }
    }
}

void Menu::update()
{
}

void Menu::render()
{
    Renderer::clear(0, 255, 0);
    Renderer::present();
}
