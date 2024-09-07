#include <iostream>
#include "math_power.h"

int main(int argc, char** argv)
{
    double a = 0;
    double b = 0;
    int c;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    do
    {
        std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень, 0 - выход: ";
        std::cin >> c;
        if (c == 1)
        {
            std::cout << "a + b = " << sum(a, b) << std::endl;
        }
        else if (c == 2)
        {
            std::cout << "a - b = " << subtraction(a, b) << std::endl;
        }
        else if (c == 3)
        {
            std::cout << "a * b = " << multiplication(a, b) << std::endl;
        }
        else if (c == 4)
        {
            std::cout << "a / b = " << division(a, b) << std::endl;
        }
        else if (c == 5)
        {
            std::cout << a << " в степени " << b << " = " << exponentiation(a, b) << std::endl;
        }
        else if (c == 0)
        {
            std::cout << "До свидания!\n";
        }
        else
        {
            std::cout << "Не верная операция, попробуйте еще раз!\n";
        }
    } while (c != 0);
    return 0;
}
