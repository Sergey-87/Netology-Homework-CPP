#include "parallelepiped.h"

Parallelepiped::Parallelepiped(Point p1, Point p2, Point p3, Point h)
{
	type = "Параллелепипед";
	Point p4 = fourthVertex(p1, p2, p3);
	Point p1_{};
	Point p2_{};
	Point p3_{};
	Point p4_{};
	double edgeA = rectangleSides(p1, p2, p3)[0];
	double edgeB = rectangleSides(p1, p2, p3)[1];
	double a = lengthOfSegment(h, p1);
	double b = lengthOfSegment(h, p2);
	double c = lengthOfSegment(h, p3);
	double edgeC{};
	if (a < b && a < c)
	{
		edgeC = a;
		p1_ = h;
		p2_ = fourthVertex(p1, p2, p1_);
		p3_ = fourthVertex(p1, p3, p1_);
		p4_ = fourthVertex(p1_, p2_, p3_);
	}
	else if (b < a && b < c)
	{
		edgeC = b;
		p2_ = h;
		p1_ = fourthVertex(p1, p2, p2_);
		p4_ = fourthVertex(p2, p4, p2_);
		p3_ = fourthVertex(p1_, p2_, p4_);
	}
	else if (c < a && c < b)
	{
		edgeC = c;
		p3_ = h;
		p1_ = fourthVertex(p1, p3, p3_);
		p4_ = fourthVertex(p3, p4, p3_);
		p2_ = fourthVertex(p1_, p3_, p4_);
	}
	Point p = fourthVertex(p1, p2, p3);
	points = { p1, p2, p3, p4, p1_, p2_, p3_, p4_ };
	sides = { edgeA, edgeB, edgeC };
}
double Parallelepiped::getSquare()
{
	return 2 * (sides[0] * sides[1] + sides[0] * sides[2] + sides[1] * sides[2]);
}
double Parallelepiped::getVolume()
{
	return sides[0] * sides[1] * sides[2];
}
void Parallelepiped::printInfo()
{
	std::cout << getType() << "\nточки: ";
	for (auto& point : this->points)
	{
		std::cout << "{" << point.x << ", " << point.y << ", " << point.z << "} ";
	}
	std::cout << std::endl << "сторона a = " << sides[0] << " сторона b = " << sides[1] << " сторона c = " << sides[2];
	std::cout << std::endl << " площадь = " << this->getSquare() << " объем = " << this->getVolume() << std::endl;
}