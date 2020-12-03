#ifndef SOUND_HPP
#define SOUND_HPP
#include <SDL2/SDL_mixer.h>

class Sound
{
    public:
        static bool init();
        static void loadAll();
        static void freeAll();
        static void playBoing(); //play random boing sound
        static void playBlip1();
        static void playBlip2();
    private:
        inline static Mix_Chunk* boing1 = nullptr;
        inline static Mix_Chunk* boing2 = nullptr;
        inline static Mix_Chunk* boing3 = nullptr;
        inline static Mix_Chunk* blip1 = nullptr;
        inline static Mix_Chunk* blip2 = nullptr;
};
#endif
