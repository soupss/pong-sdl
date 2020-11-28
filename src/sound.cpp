#include "sound.hpp"

void Sound::load()
{
    boing1 = Mix_LoadWAV("res/sfx/boing1.wav");
    boing2 = Mix_LoadWAV("res/sfx/boing2.wav");
    boing3 = Mix_LoadWAV("res/sfx/boing3.wav");
}

void Sound::free()
{
    Mix_FreeChunk(boing1);
    Mix_FreeChunk(boing2);
    Mix_FreeChunk(boing3);
}

void Sound::playBoing()
{
    //play random boing sound
    int r = rand() % 3;
    switch(r)
    {
        case 0:
            Mix_PlayChannel(-1, boing1, 0);
            break;
        case 1:
            Mix_PlayChannel(-1, boing2, 0);
            break;
        case 2:
            Mix_PlayChannel(-1, boing3, 0);
            break;
    }
}
