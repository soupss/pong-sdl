#include <SDL2/SDL.h>
#include "Game.hpp"

int main(int argc, char* args[]){
    Game game;
    while(!game.hasQuit()){
        game.handle_events();
        game.display();
    }
    return 0;
}
