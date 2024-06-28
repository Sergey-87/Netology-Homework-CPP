#pragma once
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник: ";

    }
};