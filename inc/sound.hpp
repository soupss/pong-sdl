#ifndef SOUND_HPP
#define SOUND_HPP
#include <SDL2/SDL_mixer.h>

class Sound
{
    public:
        ~Sound();
        void init();
        void playMusic();
        void playBoing();
        void playPause();
        void playUnpause();
        void playScore();

    private:
        Mix_Music* music;
        Mix_Chunk* boing1;
        Mix_Chunk* boing2;
        Mix_Chunk* boing3;
        Mix_Chunk* pause;
        Mix_Chunk* unpause;
        Mix_Chunk* score;
};
#endif
