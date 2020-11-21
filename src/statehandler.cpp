#include "statehandler.hpp"
#include <iostream>
#include "title.hpp"
#include "menu.hpp"

void StateHandler::setNextState(int _nextStateID)
{
    if(nextStateID != States::QUIT)
    {
        nextStateID = _nextStateID;
    }
}

void StateHandler::changeState()
{
    if(nextStateID != States::NULLSTATE)
    {
        std::cout << "changing state! " << currentStateID << "->" << nextStateID << std::endl;
        if(nextStateID != States::QUIT)
        {
            delete currentState;
        }
        switch(nextStateID)
        {
            case States::TITLE:
                currentState = new Title();
                break;
            case States::MENU:
                currentState = new Menu();
                break;
        }
        currentStateID = nextStateID;
        nextStateID = States::NULLSTATE;
    }
}
