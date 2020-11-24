#ifndef PLAYING_HPP
#define PLAYING_HPP
#include <SDL2/SDL_ttf.h>
#include "gamestate.hpp"
#include "sprite.hpp"

class Playing : public GameState
{
    public:
        Playing();
        ~Playing() override;
        void events() override;
        void update() override;
        void render() override;
    private:
        TTF_Font* font;
        //pointers to base class
        //defined in Playing::Playing()
        Sprite* player1;
        Sprite* player2;
};
#endif
