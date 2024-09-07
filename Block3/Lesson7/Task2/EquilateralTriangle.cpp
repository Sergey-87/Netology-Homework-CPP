#include "EquilateralTriangle.h"
#include "MyException.h"

EquilateralTriangle::EquilateralTriangle(int a, int b, int c, int A, int B, int C)
	: Triangle(a, b, c, A, B, C)
{
	Triangle::name = "–авносторонний треугольник";

	if ((a != b && b != c) && (A != B && B != C))
	{
		throw MyException("¬се стороны должны быть равны, все углы должны быть равны 60");
	}

	if (a != b && b != c)
	{
		throw MyException("¬се стороны должны быть равны");
	}

	if (A != B && B != C)
	{
		throw MyException("все углы должны быть равны 60");
	}

};