#ifndef BALL_HPP
#define BALL_HPP
#include <SDL2/SDL.h>
#include "sprite.hpp"
#include "vector2f.hpp"

class Ball : public Sprite
{
    public:
        Ball();
        const static int WIDTH = 15, HEIGHT = 15;
        void randDir();
        inline void setY(int _y) {pos.y = _y;}
        inline void up() {dir.y = -1;}
        inline void down() {dir.y = 1;}
        inline void left() {dir.x = -1;}
        inline void right() {dir.x = 1;}
        void move() override;
        void back();
        void respawn(int _x, int _y);
        inline int GET_WIDTH() const override {return WIDTH;}
        inline int GET_HEIGHT() const override {return HEIGHT;}
    private:
        Vector2f dir;
        const int speed = 3;
};
#endif
