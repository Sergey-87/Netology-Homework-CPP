#include "Square.h"


Square::Square(int a, int b, int c, int d, int A, int B, int C, int D)
	: Quadrilateral(a, b, c, d, A, B, C, D)
{
	Quadrilateral::name = "Квадрат";

	if ((a != b || b != c || c != d) 
		&& (A != 90 || B != 90 || C != 90 || D != 90))
	{
		throw MyException("Все стороны должны быть равны, Все углы должны быть равны 90");
	}

	if (a != b || b != c || c != d)
	{
		throw MyException("Все стороны должны быть равны");
	}

	if (A != 90 || B != 90 || C != 90 || D != 90)
	{
		throw MyException("Все углы должны быть равны 90");
	}
}