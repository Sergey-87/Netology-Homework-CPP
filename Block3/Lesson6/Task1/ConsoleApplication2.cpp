#include <iostream>
#define MODE 1
#if !defined MODE
#error Error MODE
#endif

int add(int a, int b) {
	return a + b;
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
#if MODE == 0
	std::cout << "Работаю в режиме тренировки\n";
#elif MODE == 1
	int a, b;
	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Введите число 1: ";
	std::cin >> a;
	std::cout << "Введите число 2: ";
	std::cin >> b;
	std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else
	std::cout << "Неизвестный режим.Завершение работы\n";
#endif
	return 0;
}