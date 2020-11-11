#ifndef BALL_HPP
#define BALL_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        Ball();
        const static int WIDTH = 20, HEIGHT = 20;
        void randDir();
        inline void up() {dir.y = -1;}
        inline void down() {dir.y = 1;}
        inline void left() {dir.x = -1;}
        inline void right() {dir.x = 1;}
        void move();
        void back();
        inline int GET_WIDTH() const override {return WIDTH;}
        inline int GET_HEIGHT() const override {return HEIGHT;}
    private:
        Vector2f dir;
        const int speed = 5;
};
#endif
