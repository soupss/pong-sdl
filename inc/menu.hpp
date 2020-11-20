#ifndef MENU_HPP
#define MENU_HPP
#include "gamestate.hpp"

class Menu : public GameState
{
    public:
        void events() override;
        void update() override;
        void render() override;
};
#endif
