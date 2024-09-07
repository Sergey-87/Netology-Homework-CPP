#include "DynamicMathPower.h"
namespace DynamicMathPower
{
	void Leaver::leave(std::string s)
	{
		std::cout << "Введите имя: ";
		std::cin >> s;
		std::cout << "До свидания, " << s << "!\n";
	}
}