#include "playing.hpp"
#include <iostream>
#include <sstream>
#include "game.hpp"
#include "statehandler.hpp"
#include "renderer.hpp"
#include "timer.hpp"
#include "colors.hpp"

Playing::Playing()
{
    font = Game::loadFont(40);
    int spacing = 100;
    int paddleY = Game::GET_SCREEN_HEIGHT() / 2 - Paddle::HEIGHT / 2;
    //define sprites
    player1 = new Paddle(spacing, paddleY);
    player2 = new Paddle(Game::GET_SCREEN_WIDTH() - Paddle::WIDTH - spacing, paddleY);
    ball = new Ball(Game::GET_SCREEN_WIDTH() / 2 - Ball::WIDTH / 2, Game::GET_SCREEN_HEIGHT() / 2 - Ball::HEIGHT / 2);
}

Playing::~Playing()
{
    Game::destroyFont(font);
    delete player1;
    delete player2;
    delete ball;
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
    handleInput();
}

void Playing::update()
{
    player1->move();
    player2->move();
    ball->move();
    player1->update();
    player2->update();
    ball->update();
}

void Playing::render()
{
    const SDL_Color bg = Colors::BACKGROUND;
    Renderer::clear(bg.r, bg.g, bg.b);
    std::stringstream fps;
    fps << Timer::getAvgFps();
    SDL_Color orange = Colors::PRIMARY;
    Renderer::renderText(font, fps.str(), 45, 10, orange);
    Renderer::renderRect(player1->getRect());
    Renderer::renderRect(player2->getRect());
    Renderer::renderRect(ball->getRect());
    Renderer::present();
}

void Playing::handleInput()
{
    const unsigned char* ks = SDL_GetKeyboardState(NULL); //keystate
    //player1
    if(ks[SDL_SCANCODE_W] && ks[SDL_SCANCODE_S])
    {
        player1->stop();
    }
    else if(ks[SDL_SCANCODE_W] && player1->getPos()->y > 0)
    {
        player1->up();
    }
    else if(ks[SDL_SCANCODE_S] && player1->getPos()->y + player1->getRect()->h < Game::GET_SCREEN_HEIGHT())
    {
        player1->down();
    }
    else
    {
        player1->stop();
    }
    //player2
    if(ks[SDL_SCANCODE_UP] && ks[SDL_SCANCODE_DOWN])
    {
        player2->stop();
    }
    else if(ks[SDL_SCANCODE_UP] && player2->getPos()->y > 0)
    {
        player2->up();
    }
    else if(ks[SDL_SCANCODE_DOWN] && player2->getPos()->y + player2->getRect()->h < Game::GET_SCREEN_HEIGHT())
    {
        player2->down();
    }
    else
    {
        player2->stop();
    }
}
