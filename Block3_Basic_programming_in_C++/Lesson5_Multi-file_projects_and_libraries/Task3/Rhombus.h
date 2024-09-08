#pragma once
#include "Chutyrehangle.h"

class Rhombus : public Chutyrehangle
{
public:
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, a, a, a, A, B, A, B)
    {
        name = "Ромб: ";

    }
};
