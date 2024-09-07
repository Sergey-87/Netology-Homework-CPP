#pragma once
#include <iostream>

class Triangle {
protected:
    std::string name;
    int a = 0;
    int b = 0;
    int c = 0;
    int A = 0;
    int B = 0;
    int C = 0;

public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        name = "Треугольник: ";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    void get_name();
    void get_sides();
    
    void get_angles();
};