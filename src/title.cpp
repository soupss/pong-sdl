#include <SDL2/SDL.h>
#include "title.hpp"
#include "statehandler.hpp"

void Title::events()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            StateHandler::setNextState(States::QUIT);
        }
    }
}

void Title::update()
{
}

void Title::render()
{
}
