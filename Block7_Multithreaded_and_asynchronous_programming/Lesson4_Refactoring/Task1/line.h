#pragma once
#include "shape.h"

class Line : public Shape
{
public:
	Line() {};
	Line(Point p1, Point p2);

	std::vector<Point>& getPoints();

	double lengthOfSegment(Point p1, Point p2);
	void printInfo() override;

protected:
	std::vector<Point> points{};
};
