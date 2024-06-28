#pragma once
#include "Chutyrehangle.h"

class Square : public Chutyrehangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, a, a, a, 90, 90, 90, 90)
    {
        name = " вадрат: ";

    }
};
