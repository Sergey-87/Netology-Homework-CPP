#include "Quadrilateral.h"
#include "MyException.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
{
	name = "Четырехугольник";

	haveFourSides_ = true;

	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;

	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;

	if (A + B + C + D != 360)
	{
		throw MyException("Cумма углов не равна 360");
	}
};