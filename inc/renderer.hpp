#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Renderer
{
    public:
        Renderer();
        ~Renderer();
        //cant be created in constructor since it needs a window, which is not created when constructor is called
        void init(SDL_Window* _window);
        void loadFont(int _size);
        void renderRect(SDL_Rect _rect);
        void renderTexture(SDL_Texture* _texture, SDL_Rect _rect);
        void renderText(const char* _text, int _x, int _y, SDL_Color _color);
        void clear();
        void present();
    private:
        SDL_Renderer* renderer;
        TTF_Font* font;
};
#endif
