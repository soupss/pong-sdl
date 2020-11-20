#ifndef PADDLE_HPP
#define PADDLE_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        Paddle();
        const static int WIDTH = 15, HEIGHT = 80;
        inline int GET_WIDTH() const override {return WIDTH;}
        inline int GET_HEIGHT() const override {return HEIGHT;}
        inline void up() {vel = -1;}
        inline void down() {vel = 1;}
        inline void still() {vel = 0;}
        void move() override;
        inline int getVel() const {return vel;}
    private:
        int vel;
        const int speed = 5;
};
#endif
