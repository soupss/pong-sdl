#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <SDL2/SDL.h>

class GameState
{
    public:
        virtual ~GameState() = default;
        virtual void events() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
    protected:
        SDL_Event event;
};
#endif
