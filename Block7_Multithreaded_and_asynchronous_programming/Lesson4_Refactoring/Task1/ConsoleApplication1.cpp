#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "parallelepiped.h"
#include "circle.h"
#include "cylinder.h"
#include "transform.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Point point2{ 6, 2, 3 };
	Point point3{ 1, 6, 3 };
	Point point4{ 1, 2, 5 };
	Point point1{ 1, 2, 3 };

	Line line{ point1, point2 };
	Transform<Line> transformLine(line);
	line = transformLine.scaleX(2);
	line.printInfo();
	std::cout << std::endl;

	Rectangle rectangle{ point1, point2, point3 };
	Transform<Rectangle> transformRectangle(rectangle);
	rectangle = transformRectangle.shift(1, 1, 1);
	rectangle.printInfo();
	std::cout << std::endl;

	Parallelepiped parallelepiped{ point1, point2, point3, point4 };
	Transform<Parallelepiped> transformParallelepiped(parallelepiped);
	parallelepiped = transformParallelepiped.shift(1, 1, 1);
	parallelepiped.printInfo();
	std::cout << std::endl;

	Circle circle(point1, 3);
	Transform<Circle> transformCircle(circle);
	circle = transformCircle.shift(1, 1, 1);
	circle.printInfo();
	std::cout << std::endl;

	Cylinder cylinder(point1, 3, 5);
	Transform<Cylinder> transformCylinder(cylinder);
	cylinder = transformCylinder.scaleX(2);
	cylinder.printInfo();
	std::cout << std::endl;
}
