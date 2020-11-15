#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP
#include <iostream>

struct Vector2f
{
    Vector2f()
    :x(0.0f), y(0.0f)
    { }

    Vector2f(float _x, float _y)
    :x(_x), y(_y)
    { }

    inline void print()
    {
        std::cout << x << ", " << y << std::endl;
    }

    float x, y;
};
#endif
