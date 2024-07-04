#pragma once
#include "Triangle.h"
#include "MyException.h"


class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C);
};