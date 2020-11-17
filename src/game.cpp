#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>
#include "game.hpp"
#include "collision.hpp"
#include "timer.hpp"

Game::Game()
    :SCREEN_WIDTH(1100), SCREEN_HEIGHT(600)
{
    if(!init())
    {
        std::cout << "Init failed\n";
    }
    else
    {
        renderer.init(window);
        renderer.loadFont(30);
        SDL_ShowCursor(SDL_DISABLE);
        //init sprites
        const int edge = 80;
        const int paddleY = SCREEN_HEIGHT/2-Paddle::HEIGHT/2;
        player1.init(edge, paddleY);
        player2.init(SCREEN_WIDTH-Paddle::WIDTH-edge, paddleY);
        ball.init(SCREEN_WIDTH/2-Ball::WIDTH/2, SCREEN_HEIGHT/2-Ball::HEIGHT/2);
        ball.randDir();
        running = true;
        Timer::start();
    }
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
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
            if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
            {
                std::cerr << "IMG_Init error: " << IMG_GetError() << std::endl;
                success = false;
            }
            if(TTF_Init() == -1)
            {
                std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
                success = false;
            }
        }
    }
    return success;
}

void Game::handleInput()
{
    const unsigned char* keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_W] && keyState[SDL_SCANCODE_S])
    {
        player1.setVel(0);
    }
    else if(keyState[SDL_SCANCODE_W] && (player1.getPos().y > 0))
    {
        player1.setVel(-1);
    }
    else if(keyState[SDL_SCANCODE_S] && (player1.getPos().y + player1.getRect().h < SCREEN_HEIGHT))
    {
        player1.setVel(1);
    }
    else
    {
        player1.setVel(0);
    }
}

void Game::events()
{
    while(SDL_PollEvent(&event) != 0)
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
    }
    handleInput();
}

void Game::update()
{
    //collision
    if(Collision::check(player1.getRect(),player1.getPos(), ball.getRect(), ball.getPos()))
    {
        //step back
        ball.back();
        std::cout << "collision detected\n";
        int playerRight =  player1.getPos().x + player1.getRect().w;
        //collide on bot or top of paddle
        if(ball.getPos().x < playerRight)
        {
            //top side
            if(ball.getPos().y < player1.getPos().y)
            {
                ball.up();
                ball.setY(player1.getPos().y - ball.getRect().h);
            }
            //bot side
            else
            {
                ball.down();
                ball.setY(player1.getPos().y + player1.getRect().h);
            }
        }
        //right side
        else
        {
            ball.right();
        }
    }
    //constraint ball
    if(ball.getPos().y < 0)
    {
        ball.down();
    }
    else if(ball.getPos().y + ball.getRect().h > SCREEN_HEIGHT)
    {
        ball.up();
    }
    else if(ball.getPos().x + ball.getRect().w > SCREEN_WIDTH)
    {
        ball.left();
    }
    ball.move();
    //update sprite pos
    player1.move();
    //update rects with new positions
    player1.update();
    player2.update();
    ball.update();
}

void Game::draw()
{
    renderer.clear();
    //sprites
    renderer.renderRect(player1.getRect());
    renderer.renderRect(player2.getRect());
    renderer.renderRect(ball.getRect());
    //ui elements
    //fps
    std::stringstream fps;
    fps << Timer::getAvgFps();
    SDL_Color color = {0xFF, 0xFF, 0x00, 0xFF};
    renderer.renderText(fps.str(), 5, -10, color);
    //middle line
    int midLineW = 5;
    SDL_Rect midRect = { (SCREEN_WIDTH / 2) - (midLineW / 2),
                     0,
                     midLineW,
                     SCREEN_HEIGHT };
    renderer.renderRect(midRect);
    renderer.present();
}
