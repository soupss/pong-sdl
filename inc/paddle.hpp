#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        inline const static int WIDTH = 15;
        inline const static int HEIGHT = 80;
        Paddle(float _x, float _y);
        ~Paddle() override;
        void move() override;
    private:
        const int speed = 5;
};
#endif
