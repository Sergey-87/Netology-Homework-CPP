#include "Rectangle.h"
#include "MyException.h"

Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D)
	: Quadrilateral(a, b, c, d, A, B, C, D)
{
	Quadrilateral::name = "Прямоугольник";

	if ((a != c || b != d) && (A != 90 || B != 90 || C != 90 || D != 90))
	{
		throw MyException("Стороны a,c и b,d должны быть попарно равны, Все углы должны быть равны 90");
	}

	if (a != c || b != d)
	{
		throw MyException("Стороны a,c и b,d должны быть попарно равны");
	}

	if (A != 90 || B != 90 || C != 90 || D != 90)
	{
		throw MyException("Все углы должны быть равны 90");
	}





}