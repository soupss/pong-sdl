#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <SDL2/SDL.h>

class GameState
{
    public:
        virtual ~GameState() = default;
        virtual void events() = 0; //input
        virtual void update() = 0; //logic
        virtual void render() = 0; //display
    protected:
        SDL_Event event;
};
#endif
