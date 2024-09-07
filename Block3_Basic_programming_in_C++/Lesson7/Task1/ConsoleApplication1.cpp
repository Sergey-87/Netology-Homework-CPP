#include <iostream>
#include <windows.h>

class bad_length : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Вы ввели слово запретной длины! До свидания";
    }
};
int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    {
        throw bad_length();
    }
    return str.length();
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string str;
    int a = 0;
    int forbidden_length = 0;
    char b = '"';
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    a = function(str, forbidden_length);
    try
    {
        do
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            a = function(str, forbidden_length);
            std::cout << "Длина слова " << b << str << b << " равна " << a << std::endl;
        } while (forbidden_length != a);
    }
    catch (bad_length& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
