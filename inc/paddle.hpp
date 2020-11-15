#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        Paddle();
        const static int WIDTH = 18, HEIGHT = 90;
        inline int GET_WIDTH() const override {return WIDTH;}
        inline int GET_HEIGHT() const override {return HEIGHT;}
        inline void setVel(int _vel) {vel = _vel;}
        void move() override;
    private:
        int vel;
        const int speed = 3;
};
#endif
