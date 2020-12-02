#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP
#include <iostream>
#include <iomanip>

struct Vector2f
{
    Vector2f()
        :x(0.0f), y(0.0f)
    { }

    Vector2f(float _x, float _y)
        :x(_x), y(_y)
    { }

    void print()
    {
        std::cout << std::fixed; //show trailing 0's
        std::cout << std::setprecision(2);
        std::cout << x << " " << y << std::endl;
    }

    //TODO:operator overloading to add/sub/multiply two vectors

    float x,y;
};
#endif
