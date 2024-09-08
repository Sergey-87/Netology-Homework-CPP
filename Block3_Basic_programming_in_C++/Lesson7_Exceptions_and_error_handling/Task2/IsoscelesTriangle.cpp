#include "IsoscelesTriangle.h"
#include "MyException.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
	: Triangle(a, b, c, A, B, C)
{
	Triangle::name = "Равнобедренный треугольник";

	if (a != c && A != C)
	{
		throw MyException("Стороны a и c не равны и Углы A и C не равны");
	}
	
	if (A != C)
	{
		throw MyException("Стороны a и c не равны");
	}
	
	if (a != c)
	{
		throw MyException("Углы A и C не равны");
	}
};