#include <iostream>
#include <windows.h>

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string s;
	std::cout << "������� ���: ";
	std::cin >> s;
	std::cout << "������������, " << s << "!\n";
	return 0;
}