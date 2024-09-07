#include <iostream>

    enum months
    {
        Январь = 1,
        Февраль,
        Март,
        Апрель,
        Май,
        Июнь,
        Июль,
        Август,
        Сентябрь,
        Октябрь,
        Ноябрь,
        Декабрь
    };
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = -1;
    while (n != 0) {
        std::cout << "Введите номер месяца: ";
        std::cin >> n;
        switch (n)
        {
        case (Январь): std::cout << "Январь\n"; break;
        case (Февраль): std::cout << "Февраль\n"; break;
        case (Март): std::cout << "Март\n"; break;
        case (Апрель): std::cout << "Апрель\n"; break;
        case (Май): std::cout << "Май\n"; break;
        case (Июнь): std::cout << "Июнь\n"; break;
        case (Июль): std::cout << "Июль\n"; break;
        case (Август): std::cout << "Август\n"; break;
        case (Сентябрь): std::cout << "Сентябрь\n"; break;
        case (Октябрь): std::cout << "Октябрь\n"; break;
        case (Ноябрь): std::cout << "Ноябрь\n"; break;
        case (Декабрь): std::cout << "Декабрь\n"; break;
        case 0: std::cout << "До свидания\n"; break;
        default: std::cout << "Неправильный номер!\n"; break;
        }
    }
    return 0;
}
