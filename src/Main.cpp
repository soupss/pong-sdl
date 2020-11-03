#include "Game.hpp"
#include "Sprite.hpp"

int main(int argc, char* args[]){
    Game game;
    while(!game.hasQuit())
    {
        game.handleEvents();
        game.draw();
    }
    return 0;
}
