#ifndef STATEHANDLER_HPP
#define STATEHANDLER_HPP
#include "gamestate.hpp"

namespace States
{
    enum States
    {
        NULLSTATE,
        TITLE,
        MENU,
        PLAYING,
        PAUSED,
        QUIT
    };
}

class StateHandler
{
    public:
        static void setNextState(int _nextStateID);
        static void changeState();
        inline static GameState* getCurrentState() {return currentState;}
        inline static int getCurrentStateID() {return currentStateID;}
    private:
        inline static GameState* currentState = nullptr; //current state object
        inline static int currentStateID = States::NULLSTATE;
        inline static int nextStateID = States::NULLSTATE;
};
#endif
