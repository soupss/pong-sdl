#ifndef SOUND_HPP
#define SOUND_HPP
#include <SDL2/SDL_mixer.h>

class Sound
{
    public:
        ~Sound();
        void init();
        void playBoing();

    private:
        Mix_Chunk* boing1;
        Mix_Chunk* boing2;
        Mix_Chunk* boing3;
#endif
