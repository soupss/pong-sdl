#ifndef TIMER_HPP
#define TIMER_HPP
#include <stdint.h>

class Timer
{
    public:
        static void start();
        static void countFrame();
        static uint32_t getAvgFps();
    private:
        inline static uint32_t startTicks = 0;
        inline static uint32_t countedFrames = 0;
};
#endif
