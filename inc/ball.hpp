#ifndef BALL_HPP
#define BALL_HPP
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        inline const static int WIDTH = 20;
        inline const static int HEIGHT = 20;
        Ball(float _x, float _y);
        ~Ball() override;
        void move() override;
    private:
        const int speed = 5;
};
#endif
