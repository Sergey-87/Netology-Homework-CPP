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
    void get_name() { std::cout << name << std::endl; }
    void get_sides() {
        std::cout << "Стороны: " <<
            " a=" << a << " b=" << b << " c=" << c << std::endl;
    }
    void get_angles() { std::cout << "Углы: " << " A=" << A << " B=" << B << " C=" << C << std::endl; }
};
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
    void get_name() { std::cout << name << std::endl; }
    void get_sides() { std::cout << "Стороны: " << " a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl; }
    void get_angles() { std::cout << "Углы: " << " A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl; }
};
class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, a, a, 60, 60, 60)
    {
        name = "Равносторонний треугольник: ";
        
    }
};
class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, a, A, B, A)
    {
        name = "Равнобедренный треугольник: ";
        
    }
};
class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник: ";
        
    }
};
class Parallelogram : public Chutyrehangle
{
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, b, a, b, A, B, A, B)
    {
        name = "Параллелограмм: ";
        
    }
};
class Rectangle : public Chutyrehangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, b, c, b, 90, 90, 90, 90)
    {
        name = "Прямоугольник: ";
        
    }
};
class Square : public Chutyrehangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, a, a, a, 90, 90, 90, 90)
    {
        name = "Квадрат: ";
     
    }
};
class Rhombus : public Chutyrehangle
{
public:
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Chutyrehangle(a, a, a, a, A, B, A, B)
    {
        name = "Ромб: ";
       
    }
};
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

