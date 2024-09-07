#include <iostream>
#include <windows.h>

struct score
{
    int number;
    std::string name;
    double money;
};
void money2(score& s)
{
    std::cout << "Введите новый баланс: ";
    std::cin >> s.money;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    score s;
    std::cout << "Введите номер счета: ";
    std::cin >> s.number;
    std::cout << "Введите имя владельца: ";
    std::cin >> s.name;
    std::cout << "Введите баланс: ";
    std::cin >> s.money;
    money2(s);
    std::cout << "Ваш счет: " << s.name << ", " << s.number << ", " << s.money;
    return 0;
}
