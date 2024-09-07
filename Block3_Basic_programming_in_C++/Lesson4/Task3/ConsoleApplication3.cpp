#include <iostream>
#include <string>

class Figure
{
protected:
	std::string name = "Фигура";
	bool checkFigure = false;
	int quantityOfSides = 0;
	int LengthA = 0;
	int LengthB = 0;
	int LengthC = 0;
	int LengthD = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	int angleD = 0;

	virtual bool check()
	{
		if (quantityOfSides == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	std::string NameOfFigure() { return name; }

	int SideLengthA() { return LengthA; }
	int SideLengthB() { return LengthB; }
	int SideLengthC() { return LengthC; }
	int SideLengthD() { return LengthD; }

	int AngleA() { return angleA; }
	int AngleB() { return angleB; }
	int AngleC() { return angleC; }
	int AngleD() { return angleD; }

	virtual void printFigure() 
	{
		std::cout << std::endl;
		std::cout << name << ":" << std::endl;
		if (check())
		{
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << quantityOfSides << std::endl;
	}
};

class Triangle : public Figure
{
protected:
	bool check() override 
	{
		if ((angleA + angleB + angleC) == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int A, int B, int C)
	{
		name = "Треугольник";
		LengthA = sideLengthA;
		LengthB = sideLengthB;
		LengthC = sideLengthC;
		angleA = A;
		angleB = B;
		angleC = C;
		quantityOfSides = 3;
		checkFigure = check();
	}

	void printFigure() override
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << SideLengthA() << ", b = " << SideLengthB() << ", с = " << SideLengthC();
		std::cout << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << AngleA() << ", В = " << AngleB() << ", С = " << AngleC();
		std::cout << std::endl;
	}

};

class rightTriangle : public Triangle
{
protected:
	bool check() override
	{
		if (Triangle::check() && (angleC == 90))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int A, int B, int C)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, A, B, C)
	{
		Triangle::name = "Прямоугольный треугольник";
	};
};

class isoscelesTriangle : public Triangle
{
protected:
	bool check() override
	{
		if (Triangle::check() && (LengthA == LengthC && angleA == angleC))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int A, int B, int C)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, A, B, C)
	{
		Triangle::name = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((LengthA == LengthB && LengthB == LengthC) && ((angleA == 60) && (angleA = 60) && (angleC = 60)))
		{
			return true;
		}
		else
		{
			return false;
		};
	}

public:
	equilateralTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int A, int B, int C)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, A, B, C)
	{
		Triangle::name = "Равносторонний треугольник";
	};
protected:
	bool check() override
	{
		if (Triangle::check() && (CheckEquilateralTriangle()))
		{
			return true;
		}
		else
		{
			return false;
		};
	};



};

class Quadrilateral : public Figure
{
protected:
	virtual bool check()
	{
		if ((angleA + angleB + angleC + angleD) == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	bool metodCheckSideLengthACiBD()
	{
		if (LengthA == LengthC && LengthB == LengthD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	bool metodCheckSideLengthACBD()
	{
		if (LengthA == LengthB && LengthB == LengthC && LengthC == LengthD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	bool metodCheckAngleabcd90()
	{
		if (angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	bool metodCheckAngleACiBD()
	{
		if (angleA == angleC && angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int A, int B, int C, int D)
	{
		name = "Четырехугольник";

		quantityOfSides = 4;
		LengthA = sideLengthA;
		LengthB = sideLengthB;
		LengthC = sideLengthC;
		LengthD = sideLengthD;

		angleA = A;
		angleB = B;
		angleC = C;
		angleD = D;
	}

	void printFigure() override
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << SideLengthA() << ", b = " << SideLengthB() << ", с = " << SideLengthC();
		std::cout << ", d = " << SideLengthD() << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << AngleA() << ", В = " << AngleB() << ", С = " << AngleC();
		std::cout << ", D = " << AngleD() << std::endl;
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Rectangle(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int A, int B, int C, int D)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, A, B, C, D)
	{
		Quadrilateral::name = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Square(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int A, int B, int C, int D)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, A, B, C, D)
	{
		Quadrilateral::name = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Parallelogram(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int A, int B, int C, int D)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, A, B, C, D)
	{
		Quadrilateral::name = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool check() override
	{
		if (Quadrilateral::check() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Rhomb(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int A, int B, int C, int D)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, A, B, C, D)
	{
		Quadrilateral::name = "Ромб";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Figure Figure1;
	Figure1.printFigure();
	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Triangle1.printFigure();
	rightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	rightTriangle1.printFigure();
	rightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	rightTriangle2.printFigure();
	isoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 50);
	isoscelesTriangle1.printFigure();
	equilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
	equilateralTriangle1.printFigure();
	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral1.printFigure();
	Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Rectangle1.printFigure();
	Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
	Square1.printFigure();
	Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Parallelogram1.printFigure();
	Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Rhomb1.printFigure();
	return 0;
}