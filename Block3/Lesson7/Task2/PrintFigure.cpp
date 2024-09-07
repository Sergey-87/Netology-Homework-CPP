#include "PrintFigure.h"
#include <iostream>
#include "Figure.h"
#include "MyException.h"
#include <exception>



void printFigure(Figure* figure)
{
	std::cout << std::endl;
	std::cout << figure->get_name() << ":" << std::endl;

	std::cout << "Стороны:";
	std::cout << " a = " << figure->get_a() << ", b = " << figure->get_b() << ", с = " << figure->get_c();
	if (figure->get_HaveFourSides())
	{
		std::cout << ", d = " << figure->get_d() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы:";
	std::cout << " А = " << figure->get_A() << ", В = " << figure->get_B() << ", С = " << figure->get_C();
	if (figure->get_HaveFourSides()) { std::cout << ", D = " << figure->get_D() << std::endl; }
	else { std::cout << std::endl; }
}