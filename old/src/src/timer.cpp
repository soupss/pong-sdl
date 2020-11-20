#include <SDL2/SDL.h>
#include "timer.hpp"

void Timer::start()
{
    startTicks = SDL_GetTicks();
}

void Timer::countFrame()
{
    ++countedFrames;
}

uint32_t Timer::getAvgFps()
{
    float secondsPassed = (SDL_GetTicks() - startTicks) / 1000.f;
    float avgFps = countedFrames / secondsPassed;
    return avgFps;
}
