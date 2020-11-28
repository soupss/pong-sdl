#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        inline const static int WIDTH = 15;
        inline const static int HEIGHT = 80;
        Paddle() = default;
        Paddle(float _x, float _y);
        ~Paddle() override;
        void move() override;
        inline void up() {vel.y = -1;}
        inline void down() {vel.y = 1;}
        inline void stop() {vel.y = 0;}
    private:
        const float speed = 3;
};
#endif
