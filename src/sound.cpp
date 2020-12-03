#include "sound.hpp"
#include <iostream>
#include <string>

bool Sound::init()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
    {
        std::cerr << "Mix_OpenAudio error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

void Sound::loadAll()
{
    boing1 = Mix_LoadWAV("res/sfx/boing1.wav");
    boing2 = Mix_LoadWAV("res/sfx/boing2.wav");
    boing3 = Mix_LoadWAV("res/sfx/boing3.wav");
    blip1 = Mix_LoadWAV("res/sfx/blip1.wav");
    blip2 = Mix_LoadWAV("res/sfx/blip2.wav");
}

void Sound::freeAll()
{
    Mix_FreeChunk(boing1);
    Mix_FreeChunk(boing2);
    Mix_FreeChunk(boing3);
    Mix_FreeChunk(blip1);
    Mix_FreeChunk(blip2);
}

void Sound::playBoing()
{
    if(!Mix_Playing(-1))
    {
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
}

void Sound::playBlip1()
{
    Mix_PlayChannel(-1, blip1, 0);
}

void Sound::playBlip2()
{
    Mix_PlayChannel(-1, blip2, 0);
}
