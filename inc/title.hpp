#ifndef TITLE_HPP
#define TITLE_HPP
#include "gamestate.hpp"

class Title : public GameState
{
    public:
        void events() override;
        void update() override;
        void render() override;
};
#endif
