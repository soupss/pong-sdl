#include "menu.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include "statehandler.hpp"
#include "game.hpp"
#include "renderer.hpp"

Menu::Menu()
    :selected(0)
{
    font = Game::loadFont(50);
}

Menu::~Menu()
{
    Game::destroyFont(font);
}

void Menu::events()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            StateHandler::setNextState(States::QUIT);
        }
        else if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_DOWN:
                case SDLK_j:
                    selectNext();
                    break;
                case SDLK_UP:
                case SDLK_k:
                    selectPrev();
                    break;
                case SDLK_RETURN:
                    switch(selected)
                    {
                        case 0: //play
                            StateHandler::setNextState(States::TITLE);
                            break;
                        case 1: //quit
                            StateHandler::setNextState(States::QUIT);
                            break;
                    }
                    break;
            }
        }
    }
}

void Menu::update()
{ }

void Menu::render()
{
    const SDL_Color c = Colors::BACKGROUND;
    Renderer::clear(c.r, c.g, c.b);
    const int spaceBetweenOptions = 100;
    //render options
    for(int i = 0;i<(int)MENU_OPTIONS.size();++i)
    {
        //y value of option with this index
        //            (            middle           )   (    spacing between    )   (                  y of first option                  )
        int optionY = (Game::GET_SCREEN_HEIGHT() / 2) + (i * spaceBetweenOptions) - (spaceBetweenOptions * (MENU_OPTIONS.size() / 2 - 0.5));
        std::string optionString = MENU_OPTIONS[i];
        if(i == selected)
        {
            optionString.insert(0, "> ");
            optionString.append(" <");
            Renderer::renderText(font, optionString, (Game::GET_SCREEN_WIDTH() / 2), optionY, Colors::PRIMARY);
        }
        else
        {
            Renderer::renderText(font, optionString, (Game::GET_SCREEN_WIDTH() / 2), optionY);
        }
    }
    Renderer::present();
}

void Menu::selectNext()
{
    if(selected != (int)MENU_OPTIONS.size() - 1)
    {
        ++selected;
    }
}

void Menu::selectPrev()
{
    if(selected != 0)
    {
        --selected;
    }
}
