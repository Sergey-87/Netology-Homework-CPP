#pragma once
#include <iostream>

class Chutyrehangle
{
protected:
    std::string name;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
public:
    Chutyrehangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        name = "Четырехугольник: ";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    void get_name();
    void get_sides();
    void get_angles();
};
