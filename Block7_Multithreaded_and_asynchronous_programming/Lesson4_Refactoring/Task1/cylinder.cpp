#define _USE_MATH_DEFINES
#include "cylinder.h"

Cylinder::Cylinder(Point centre, double height, double radius)
{
	type = "Цилиндр";
	Point centre1 = { centre.x, centre.y, centre.z + height };
	points = { centre, centre1 };
	radius_ = height;
	height_ = radius;
}

double Cylinder::getSquare()
{
	return (2 * M_PI * radius_ * height_ + 2 * Circle::getSquare());
}

double Cylinder::getVolume()
{
	return (Circle::getSquare() * height_);
}

void Cylinder::printInfo()
{
	std::cout << getType() << "\nцентр: " << "{" << points[0].x << ", " << points[0].y << ", " << points[0].z << "} " << "{" << points[1].x << ", " << points[1].y << ", " << points[1].z << "} " << std::endl;
	std::cout << "радиус = " << radius_ << " площадь = " << getSquare() << " высота = " << height_ << " объем = " << getVolume() << std::endl;
}