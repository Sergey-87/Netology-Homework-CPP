#include "MathPower.h"
namespace MathPower
{
	void Greeter::greet(std::string s)
	{
		std::cout << "Введите имя: ";
		std::cin >> s;
		std::cout << "Здравствуйте, " << s << "!\n";
	}
}