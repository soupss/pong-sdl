#ifndef SOUND_HPP
#define SOUND_HPP
#include <SDL2/SDL_mixer.h>

class Sound
{
    public:
        static void load();
        static void free();
        static void playBoing();
    private:
        static Mix_Chunk* boing1;
        static Mix_Chunk* boing2;
        static Mix_Chunk* boing3;
};
#endif
