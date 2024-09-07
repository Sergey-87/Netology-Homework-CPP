#pragma once
#include "Chutyrehangle.h"

class Rectangle : public Chutyrehangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, b, c, b, 90, 90, 90, 90)
    {
        name = "Прямоугольник: ";

    }
};
