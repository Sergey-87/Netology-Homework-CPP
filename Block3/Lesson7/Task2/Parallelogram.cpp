#include "Parallelogram.h"
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D)
	: Quadrilateral(a, b, c, d, A, B, C, D)
{
	Quadrilateral::name = "��������������";

	if ((a != c || b != d)
		&& (A != C || B != D))
	{
		throw MyException("��� ������� ������ ���� �����, ��� ���� ������ ���� ����� 90");
	}

	if (a != c || b != d)
	{
		throw MyException("������� a,c � b,d ������ ���� ������� �����");
	}

	if (A != C || B != D)
	{
		throw MyException("���� A,C � B,D ������ ���� ������� �����");
	}
}