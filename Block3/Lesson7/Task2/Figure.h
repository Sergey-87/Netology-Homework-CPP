#pragma once
#include <string>

class Figure
{
protected:
	std::string name;
	bool haveFourSides_ = false;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

public:
	std::string get_name();
	int get_HaveFourSides();

	int get_a();
	int get_b();
	int get_c();
	int get_d();

	int get_A();
	int get_B();
	int get_C();
	int get_D();
};