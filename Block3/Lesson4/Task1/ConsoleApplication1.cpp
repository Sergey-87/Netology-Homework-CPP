#include <iostream>

class Figure
{
protected:
	std::string name;
	int sides_count = 0;
public:
	Figure(int sides_count)
	{
		name = "Фигура: ";
		this->sides_count = sides_count;
	}
	void get_name()
	{
		std::cout << name;
	}
	void get_sides_count()
	{
		std::cout << sides_count;
	}
};
class Triangle : public Figure
{
public:
	Triangle(int sides_count) : Figure(sides_count)
	{
		name = "Треугольник: ";
	}
};
class Quadrangle : public Figure
{
public:
	Quadrangle(int sides_count) : Figure(sides_count)
	{
		name = "Четырёхугольник: ";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Количество сторон: \n";
	Figure figure(0);
	figure.get_name();
	figure.get_sides_count();
	std::cout << std::endl;
	Triangle triangle(3);
	triangle.get_name();
	triangle.get_sides_count();
	std::cout << std::endl;
	Quadrangle quadrangle(4);
	quadrangle.get_name();
	quadrangle.get_sides_count();
	return 0;
}
