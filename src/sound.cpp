#include "sound.hpp"

Sound::~Sound()
{
    Mix_FreeChunk(boing1);
    Mix_FreeChunk(boing2);
    Mix_FreeChunk(boing3);
}

void Sound::init()
{
    boing1 = Mix_LoadWAV("assets/sfx/boing1.wav");
    boing2 = Mix_LoadWAV("assets/sfx/boing2.wav");
    boing3 = Mix_LoadWAV("assets/sfx/boing3.wav");
    pause = Mix_LoadWAV("assets/sfx/pause.wav");
    unpause = Mix_LoadWAV("assets/sfx/unpause.wav");
    score = Mix_LoadWAV("assets/sfx/score.wav");
}

void Sound::playBoing()
{
    //play random boing
    int choice = rand() % 3;
    switch(choice)
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
