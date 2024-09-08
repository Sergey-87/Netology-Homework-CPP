#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, a, A, B, A)
    {
        name = "Равнобедренный треугольник: ";

    }
};
