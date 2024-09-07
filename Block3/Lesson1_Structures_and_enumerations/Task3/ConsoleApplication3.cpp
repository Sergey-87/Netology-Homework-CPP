#include <iostream>
#include <windows.h>

struct address
{
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;
    int index;
};
void out_address(address& address_array);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    std::cout << "Введите колличество адресов: ";
    std::cin >> n;
    address* address_array = new address[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Адрес " << i + 1 << std::endl;
        std::cout << "Введите название города: ";
        std::cin >> address_array[i].city;
        std::cout << "Введите название улицы: ";
        std::cin >> address_array[i].street;
        std::cout << "Введите номер дома: ";
        std::cin >> address_array[i].house_number;
        std::cout << "Введите номер квартиры: ";
        std::cin >> address_array[i].apartment_number;
        std::cout << "Введите индекс: ";
        std::cin >> address_array[i].index;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "===================================================\n";
    std::cout << "Результат:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "Адрес " << i + 1 << std::endl;
        out_address(address_array[i]);
        std::cout << std::endl;
    }
    delete[] address_array;
}
    void out_address(address &address_array)
    {
        std::cout << "Город: " << address_array.city << std::endl;
        std::cout << "Улица: " << address_array.street << std::endl;
        std::cout << "Номер дома: " << address_array.house_number << std::endl;
        std::cout << "Номер квартиры: " << address_array.apartment_number << std::endl;
        std::cout << "Индекс: " << address_array.index << std::endl;
    }

