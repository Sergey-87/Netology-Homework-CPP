#pragma once
#include "Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, a, a, 60, 60, 60)
	{
		name = "Равносторонний треугольник: ";

	}
};