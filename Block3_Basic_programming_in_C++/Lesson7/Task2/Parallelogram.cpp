#include "Parallelogram.h"
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D)
	: Quadrilateral(a, b, c, d, A, B, C, D)
{
	Quadrilateral::name = "Параллелограмм";

	if ((a != c || b != d)
		&& (A != C || B != D))
	{
		throw MyException("Все стороны должны быть равны, Все углы должны быть равны 90");
	}

	if (a != c || b != d)
	{
		throw MyException("Стороны a,c и b,d должны быть попарно равны");
	}

	if (A != C || B != D)
	{
		throw MyException("Углы A,C и B,D должны быть попарно равны");
	}
}