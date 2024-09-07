#include <iostream>
#include <windows.h>

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string s;
	std::cout << "Введите имя: ";
	std::cin >> s;
	std::cout << "Здравствуйте, " << s << "!\n";
	return 0;
}