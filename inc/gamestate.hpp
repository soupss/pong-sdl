#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState
{
    public:
        virtual void events() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void ~GameState() = default;
};
#endif
