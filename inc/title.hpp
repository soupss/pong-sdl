#ifndef TITLE_HPP
#define TITLE_HPP
#include <SDL2/SDL_ttf.h>
#include "gamestate.hpp"

class Title : public GameState
{
    public:
        Title();
        ~Title() override;
        void events() override;
        void update() override;
        void render() override;
    private:
        TTF_Font* font;
};
#endif
