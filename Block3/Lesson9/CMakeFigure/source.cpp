#include <iostream>
#include "EquilateralTriangle.h"
#include "Triangle.h"
#include "Chutyrehangle.h"
#include "IsoscelesTriangle.h"
#include "RightTriangle.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Square.h"
#include "Rhombus.h"

void print_info(Triangle& triangle)
{
    triangle.get_name();
    triangle.get_sides();
    triangle.get_angles();
}
void print_info(Chutyrehangle& chutyrehangle)
{
    chutyrehangle.get_name();
    chutyrehangle.get_sides();
    chutyrehangle.get_angles();
}
int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info(triangle);
    std::cout << std::endl;
    Chutyrehangle chutyrehangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(chutyrehangle);
    std::cout << std::endl;
    EquilateralTriangle equilateral_triangle(30, 30, 30, 60, 60, 60);
    print_info(equilateral_triangle);
    std::cout << std::endl;
    IsoscelesTriangle isosceles_triangle(10, 20, 10, 50, 60, 50);
    print_info(isosceles_triangle);
    std::cout << std::endl;
    RightTriangle right_triangle(10, 20, 30, 50, 60, 90);
    print_info(right_triangle);
    std::cout << std::endl;
    Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    print_info(parallelogram);
    std::cout << std::endl;
    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    print_info(rectangle);
    std::cout << std::endl;
    Square square(20, 20, 20, 20, 90, 90, 90, 90);
    print_info(square);
    std::cout << std::endl;
    Rhombus rhombus(30, 30, 30, 30, 30, 40, 30, 40);
    print_info(rhombus);
    std::cout << std::endl;
    return 0;
}

