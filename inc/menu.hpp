#ifndef MENU_HPP
#define MENU_HPP
#include "gamestate.hpp"
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>

class Menu : public GameState
{
    public:
        Menu();
        ~Menu() override;
        void events() override;
        void update() override;
        void render() override;
    private:
        void selectNext();
        void selectPrev();
        std::vector<std::string> MENU_OPTIONS = {"PLAY", "QUIT"};
        int selected;
        TTF_Font* font;
};
#endif
