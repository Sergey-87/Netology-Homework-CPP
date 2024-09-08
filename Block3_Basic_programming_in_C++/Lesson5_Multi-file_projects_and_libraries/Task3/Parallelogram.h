#pragma once
#include "Chutyrehangle.h"

class Parallelogram : public Chutyrehangle
{
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, b, a, b, A, B, A, B)
    {
        name = "ֿאנאככוכמדנאלל: ";

    }
};
