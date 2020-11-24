#include "playing.hpp"
#include <iostream>
#include "game.hpp"
#include "statehandler.hpp"
#include "renderer.hpp"
#include "colors.hpp"
#include "paddle.hpp"

Playing::Playing()
{
    font = Game::loadFont(40);
    int spacing = 100;
    int paddleY = Game::GET_SCREEN_HEIGHT() / 2 - Paddle::HEIGHT / 2;
    //define sprites
    player1 = new Paddle(spacing, paddleY);
    player2 = new Paddle(Game::GET_SCREEN_WIDTH() - Paddle::WIDTH - spacing, paddleY);
}

Playing::~Playing()
{
    Game::destroyFont(font);
    delete player1;
    delete player2;
}

void Playing::events()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            StateHandler::setNextState(States::QUIT);
        }
    }
}

void Playing::update()
{
    player1->move();
    player2->move();
    player1->update();
    player2->update();
}

void Playing::render()
{
    const SDL_Color bg = Colors::BACKGROUND;
    Renderer::clear(bg.r, bg.g, bg.b);
    Renderer::renderRect(player1->getRect());
    Renderer::renderRect(player2->getRect());
    Renderer::present();
}
