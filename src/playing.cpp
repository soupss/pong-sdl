#include "playing.hpp"
#include <iostream>
#include <sstream>
#include "game.hpp"
#include "font.hpp"
#include "statehandler.hpp"
#include "renderer.hpp"
#include "timer.hpp"
#include "colors.hpp"
#include "collision.hpp"
#include "sound.hpp"

Playing::Playing()
    :player1score(0), player2score(0)
{
    smallFont = Font::loadFont(38);
    bigFont = Font::loadFont(50);
    int spacing = 100;
    int paddleY = Game::GET_SCREEN_HEIGHT() / 2 - Paddle::HEIGHT / 2;
    //define sprites
    player1 = new Paddle(spacing, paddleY);
    player2 = new Paddle(Game::GET_SCREEN_WIDTH() - Paddle::WIDTH - spacing, paddleY);
    ball = new Ball(Game::GET_SCREEN_WIDTH() / 2 - Ball::WIDTH / 2, Game::GET_SCREEN_HEIGHT() - Ball::HEIGHT);
}

Playing::~Playing()
{
    Font::destroyFont(smallFont);
    Font::destroyFont(bigFont);
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
    handleCollision();
    constraintBall();
    //update pos
    player1->move();
    player2->move();
    ball->move();
    //adjust pos
    //constraintBall doesnt set pos directly, hence its separated from constraintPaddles
    constraintPaddles();
    //send pos to rect
    player1->update();
    player2->update();
    ball->update();
}

void Playing::render()
{
    const SDL_Color bg = Colors::BACKGROUND;
    Renderer::clear(bg.r, bg.g, bg.b);
    //ui
        //fps
    std::stringstream fps;
    fps << Timer::getAvgFps();
    SDL_Color orange = Colors::PRIMARY;
    Renderer::renderText(smallFont, fps.str(), 45, 10, orange);
        //score
    std::stringstream score;
    score << player1score << " " << player2score;
    Renderer::renderText(bigFont, score.str(), Game::GET_SCREEN_WIDTH() / 2, 50);
    //sprites
    Renderer::renderRect(player1->getRect());
    Renderer::renderRect(player2->getRect());
    Renderer::renderRect(ball->getRect());
    Renderer::present();
}

//private methods

void Playing::handleInput()
{
    const unsigned char* ks = SDL_GetKeyboardState(NULL); //keystate
    //player1
    if(ks[SDL_SCANCODE_W] && ks[SDL_SCANCODE_S])
    {
        player1->stop();
    }
    else if(ks[SDL_SCANCODE_W])
    {
        player1->up();
    }
    else if(ks[SDL_SCANCODE_S])
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
    else if(ks[SDL_SCANCODE_UP])
    {
        player2->up();
    }
    else if(ks[SDL_SCANCODE_DOWN])
    {
        player2->down();
    }
    else
    {
        player2->stop();
    }
}

void Playing::handleCollision()
{
    //player1-ball
    if(Collision::isColliding(player1->getRect(),player1->getPos(), ball->getRect(), ball->getPos()))
    {
        Sound::playBoing();
        //separate the ball and the paddle to calculate which way the ball should bounce
        ball->back();
        //if left side of ball is left of right side of paddle, it must be a collision on top or bottom side of paddle
        if(ball->getPos()->x < player1->getPos()->x + player1->getRect()->w)
        {
            //top side
            if(ball->getPos()->y < player1->getPos()->y)
            {
                ball->up();
                ball->move();
                ball->setY(player1->getPos()->y - ball->getRect()->h);
            }
            //bot side
            else
            {
                ball->down();
                ball->move();
                ball->setY(player1->getPos()->y + player1->getRect()->h);
            }
        }
        //right side
        else
        {
            ball->right();
            //curve ball
            if(player1->getDir()->y == -1)
            {
                ball->up();
            }
            else if(player1->getDir()->y == 1)
            {
                ball->down();
            }
        }
    }
    else if(Collision::isColliding(player2->getRect(),player2->getPos(), ball->getRect(), ball->getPos()))
    {
        Sound::playBoing();
        //separate the ball and the paddle to calculate which way the ball should bounce
        ball->back();
        //if right side of ball is right of left side of paddle, it must be a collision on top or bottom side of paddle
        if(ball->getPos()->x + ball->getRect()->w > player2->getPos()->x)
        {
            //top side
            if(ball->getPos()->y < player2->getPos()->y)
            {
                ball->up();
                ball->move();
                ball->setY(player2->getPos()->y - ball->getRect()->h);
            }
            //bot side
            else
            {
                ball->down();
                ball->move();
                ball->setY(player2->getPos()->y + player2->getRect()->h);
            }
        }
        //left side
        else
        {
            ball->left();
            //curve ball
            if(player2->getDir()->y == -1)
            {
                ball->up();
            }
            else if(player2->getDir()->y == 1)
            {
                ball->down();
            }
        }
    }
}

void Playing::constraintPaddles()
{
    //player1
    if(player1->getPos()->y < 0)
    {
        player1->setY((float)(0.0f));
    }
    else if(player1->getPos()->y + player1->getRect()->h > Game::GET_SCREEN_HEIGHT())
    {
        player1->setY((float)(Game::GET_SCREEN_HEIGHT() - player1->getRect()->h));
    }
    //player2
    if(player2->getPos()->y < 0)
    {
        player2->setY((float)(0.0f));
    }
    else if(player2->getPos()->y + player2->getRect()->h > Game::GET_SCREEN_HEIGHT())
    {
        player2->setY((float)(Game::GET_SCREEN_HEIGHT() - player2->getRect()->h));
    }
}

void Playing::constraintBall()
{
    if(ball->getPos()->y < 0)
    {
        Sound::playBoing();
        ball->down();
    }
    else if(ball->getPos()->y + ball->getRect()->h > Game::GET_SCREEN_HEIGHT())
    {
        Sound::playBoing();
        ball->up();
    }
    else if(ball->getPos()->x + ball->getRect()->w < 0 )
    {
        ++player2score;
        delete ball;
        ball = new Ball(Game::GET_SCREEN_WIDTH() / 2 - Ball::WIDTH / 2, Game::GET_SCREEN_HEIGHT() - Ball::HEIGHT);
    }
    else if(ball->getPos()->x > Game::GET_SCREEN_WIDTH())
    {
        ++player1score;
        delete ball;
        ball = new Ball(Game::GET_SCREEN_WIDTH() / 2 - Ball::WIDTH / 2, Game::GET_SCREEN_HEIGHT() - Ball::HEIGHT);
    }
}
