#pragma once
#include "Quadrilateral.h"
#include "MyException.h"

class Square : public Quadrilateral
{
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D);
};