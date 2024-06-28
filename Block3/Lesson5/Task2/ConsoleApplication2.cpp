#include <iostream>
#include <windows.h>
#include "counter.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string s;
    int n = 1;
    bool true_s = false;
    do
    {
        std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> s;
        std::cout << std::endl;

        if (s == "да" || s == "Да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> n;
            true_s = true;
        }
        else if (s == "нет" || s == "Нет")
        {
            true_s = true;
        }
        else
        {
            std::cout << "Вы ввели неверную команду.";
        }
    } while (!true_s);
    Counter Counter(n);
    std::cout << std::endl;
    std::string command;
    bool commandlog = false;
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == "x")
        {
            std::cout << "До свидания!";
            commandlog = true;
        }
        else if (command == "+")
        {
            Counter.counterPlus();
        }
        else if (command == "-")
        {
            Counter.counterMinus();
        }
        else if (command == "=")
        {
            std::cout << Counter.getCounter() << std::endl;
        }
        else
        {
            std::cout << "Вы ввели неверную команду." << std::endl;
        }
    } while (!commandlog);
    return 0;
}