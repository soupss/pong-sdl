#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
    public:
        RenderWindow(const char* _title, int _w, int _h);
        ~RenderWindow();
        SDL_Texture* loadTexture(const char* _filePath);
        void clear();
        void render(SDL_Texture* _tex);
        void display();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
