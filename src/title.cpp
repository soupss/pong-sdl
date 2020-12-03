#include "title.hpp"
#include <SDL2/SDL.h>
#include "game.hpp"
#include "statehandler.hpp"
#include "renderer.hpp"
#include "colors.hpp"
#include "sound.hpp"
#include "font.hpp"

Title::Title()
{
    font = Font::loadFont(120);
}

Title::~Title()
{
    Font::destroyFont(font);
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
        else if(event.type == SDL_KEYDOWN &&
                (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE))
        {
            Sound::playBlip2();
            StateHandler::setNextState(States::MENU);
        }
    }
}

void Title::update()
{ }

void Title::render()
{
    const SDL_Color bg = Colors::DARK_BACKGROUND;
    Renderer::clear(bg.r, bg.g, bg.b);
    Renderer::renderText(font, "Pong", (Game::GET_SCREEN_WIDTH() / 2), (Game::GET_SCREEN_HEIGHT() / 2));
    Renderer::present();
}
