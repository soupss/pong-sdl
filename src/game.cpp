#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>
#include "game.hpp"
#include "collision.hpp"
#include "timer.hpp"

//public

Game::Game()
    :SCREEN_WIDTH(1100), SCREEN_HEIGHT(600),  paused(true), p1_score(0), p2_score(0)
{
    if(!init())
    {
        std::cout << "Init failed\n";
    }
    else
    {
        renderer.init(window);
        renderer.loadFont(50);
        SDL_ShowCursor(SDL_DISABLE);
        sound.init();
        //init sprites
        const int edge = 80;
        const int paddleY = SCREEN_HEIGHT/2-Paddle::HEIGHT/2;
        player1.init(edge, paddleY);
        player2.init(SCREEN_WIDTH-Paddle::WIDTH-edge, paddleY);
        ball.init(SCREEN_WIDTH/2-Ball::WIDTH/2, SCREEN_HEIGHT/2-Ball::HEIGHT/2);
        ball.randDir();
        running = true;
        Timer::start();
        update();
    }
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

void Game::events()
{
    while(SDL_PollEvent(&event) != 0)
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
        {
            togglePause();
        }
    }
    handleInput();
}

void Game::update()
{
    handleCollisions();
    //constraint ball
    if(ball.getPos().y < 0)
    {
        ball.down();
        sound.playBoing();
    }
    else if(ball.getPos().y + ball.getRect().h > SCREEN_HEIGHT)
    {
        ball.up();
        sound.playBoing();
    }
    //ball
    int ballX = SCREEN_WIDTH / 2 - ball.getRect().w / 2;
    int ballY = SCREEN_HEIGHT / 2 - ball.getRect().h / 2;
    if(ball.getPos().x + ball.getRect().w < 0)
    {
        ++p2_score;
        ball.randDir();
        ball.respawn(ballX, ballY);
    }
    else if(ball.getPos().x > SCREEN_WIDTH)
    {
        ++p1_score;
        ball.randDir();
        ball.respawn(ballX, ballY);
    }
    //update sprite pos
    player1.move();
    player2.move();
    ball.move();
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
    SDL_Color orange = {0xFF, 0xA5, 0x00, 0xFF};
    renderer.renderText(fps.str(), 60, 20, orange);
    //score
    std::stringstream score;
    score << p1_score << "   " << p2_score;
    renderer.renderText(score.str(), SCREEN_WIDTH / 2, 50);
    //paused
    if(paused)
    {
        renderer.renderText("paused", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 60);
        renderer.renderText("(space to unpause)", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 45);
    }
    renderer.present();
}

//private

bool Game::init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
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
            if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
            {
                std::cerr << "Mix_OpenAudio error: " << Mix_GetError() << std::endl;
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
    //player1
    if(keyState[SDL_SCANCODE_W] && keyState[SDL_SCANCODE_S])
    {
        player1.still();
    }
    else if(keyState[SDL_SCANCODE_W] && (player1.getPos().y > 0))
    {
        player1.up();
    }
    else if(keyState[SDL_SCANCODE_S] && (player1.getPos().y + player1.getRect().h < SCREEN_HEIGHT))
    {
        player1.down();
    }
    else
    {
        player1.still();
    }
    //player2
    if(keyState[SDL_SCANCODE_UP] && keyState[SDL_SCANCODE_DOWN])
    {
        player2.still();
    }
    else if(keyState[SDL_SCANCODE_UP] && (player2.getPos().y > 0))
    {
        player2.up();
    }
    else if(keyState[SDL_SCANCODE_DOWN] && (player2.getPos().y + player2.getRect().h < SCREEN_HEIGHT))
    {
        player2.down();
    }
    else
    {
        player2.still();
    }
}

void Game::handleCollisions()
{
    //player1-ball
    if(Collision::check(player1.getRect(),player1.getPos(), ball.getRect(), ball.getPos()))
    {
        sound.playBoing();
        //step back
        ball.back();
        //collide on bot or top of paddle
        if(ball.getPos().x < player1.getPos().x + player1.getRect().w)
        {
            //top side
            if(ball.getPos().y < player1.getPos().y)
            {
                ball.up();
                ball.move();
                ball.setY(player1.getPos().y - ball.getRect().h);
            }
            //bot side
            else
            {
                ball.down();
                ball.move();
                ball.setY(player1.getPos().y + player1.getRect().h);
            }
        }
        //right side
        else
        {
            ball.right();
            //curve ball
            if(player1.getVel() == -1)
            {
                ball.up();
            }
            else if(player1.getVel() == 1)
            {
                ball.down();
            }
        }
    }
    //player2-ball
    if(Collision::check(player2.getRect(),player2.getPos(), ball.getRect(), ball.getPos()))
    {
        sound.playBoing();
        //step back
        ball.back();
        //collide on bot or top of paddle
        if(ball.getPos().x + ball.getRect().w > player2.getPos().x)
        {
            //top side
            if(ball.getPos().y < player2.getPos().y)
            {
                ball.up();
                ball.move();
                ball.setY(player2.getPos().y - ball.getRect().h);
            }
            //bot side
            else
            {
                ball.down();
                ball.move();
                ball.setY(player2.getPos().y + player2.getRect().h);
            }
        }
        //left side
        else
        {
            ball.left();
            //curve ball
            if(player2.getVel() == -1)
            {
                ball.up();
            }
            else if(player2.getVel() == 1)
            {
                ball.down();
            }
        }
    }
}

void Game::togglePause()
{
    if(!paused)
    {
        //pause
        paused = true;
    }
    else
    {
        //unpause
        paused = false;
    }
}
