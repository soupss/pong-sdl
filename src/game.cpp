#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <string>
#include "game.hpp"
#include "collision.hpp"
#include "timer.hpp"

Game::Game()
    :running(true), SCREEN_WIDTH(1000), SCREEN_HEIGHT(600)
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
        const int edge = 150;
        const int paddleY = SCREEN_HEIGHT/2-Paddle::HEIGHT/2;
        player1.init(edge, paddleY);
        player2.init(SCREEN_WIDTH-Paddle::WIDTH-edge, paddleY);
        ball.init(SCREEN_WIDTH/2-Ball::WIDTH/2, SCREEN_HEIGHT/2-Ball::HEIGHT/2);
        ball.randDir();
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

void Game::events()
{
    while(SDL_PollEvent(&event) != 0)
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
        else if(event.type == SDL_MOUSEMOTION){
            int mouseY;
            SDL_GetMouseState(NULL, &mouseY);
            int playerY = mouseY-player1.GET_HEIGHT()/2;
            const int bottom = SCREEN_HEIGHT - player1.GET_HEIGHT();
            if(playerY < 0)
            {
                playerY = 0;
            }
            else if(playerY > bottom)
            {
                playerY = bottom;
            }
            player1.setY(playerY);
        }
    }
}

void Game::update()
{
    if(Collision::check(player1.getRect(), ball.getRect()))
    {
        //step back
        ball.back();
        std::cout << "collision detected\n";
        int playerRight =  player1.getPos().x + player1.getRect().w;
        //ball collided on top or bottom side of paddle
        if(ball.getPos().x < playerRight)
        {
            if(ball.getPos().y < player1.getPos().y) //top
            {
                std::cout << "top\n";
                ball.up();
            }
            else //bot
            {
                std::cout << "bot\n";
                ball.down();
            }
        }
        else //normal side collision
        {
            std::cout << "right\n";
            ball.right();
        }
    }

    ball.move();
    int ballBottom = ball.getPos().y + ball.getRect().h;
    if(ball.getPos().y < 0)
    {
        ball.down();
    }
    else if(ballBottom > SCREEN_HEIGHT)
    {
        ball.up();
    }
    else if(ball.getPos().x + ball.getRect().w > SCREEN_WIDTH)
    {
        ball.left();
    }
    //update rect with new positions
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
    std::stringstream fps;
    fps << Timer::getAvgFps();
    SDL_Color color = {0xFF, 0xFF, 0x00, 0xFF};
    renderer.renderText(fps.str(), 5, -10, color);
    renderer.present();
}
