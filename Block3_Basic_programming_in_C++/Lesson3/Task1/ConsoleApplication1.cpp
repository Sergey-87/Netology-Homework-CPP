#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

class Adress
{
    std::string City;
    std::string Street;
    int House = 0;
    int Apartment = 0;
    std::string fAdress;
public:
    Adress(std::string nCity, std::string nStreet, int nHouse, int nApartment)
    {
        City = nCity;
        Street = nStreet;
        House = nHouse;
        Apartment = nApartment;
    }
    std::string createAdress()
    {
        fAdress = City + ", " + Street + ", " + std::to_string(House) + ", " + std::to_string(Apartment);
        return fAdress;
    };
};
enum class codeCommit
{
    InError, OutError
};
    int printArray(std::string* array, const int Adresses)
    {
        std::ofstream fileOut("out.txt", std::ios_base::trunc);
        if (fileOut.is_open())
        {
            std::cout << "Файл успешно открыт." << std::endl;
        }
        else
        {
            std::cout << "Ошибка открытия файла" << std::endl;
            return static_cast<int>(codeCommit::OutError);
        }
        fileOut << "Количество адресов: " << Adresses << std::endl << std::endl;
        fileOut << "Адреса: " << std::endl;
        for (int i = Adresses - 1; i >= 0; i--)
        {
            fileOut << Adresses - i << ". " << array[i] << std::endl;
        }
        fileOut.close();
    };
    std::string* createTextArr(const int Adresses)
    {
        std::string* TextArr = new std::string[Adresses]{};
        return TextArr;
    }
    void deleteTextArr(std::string* TextArr, const int Adresses)
    {
        delete[] TextArr;
        TextArr = nullptr;
    }
    int main()
    {
        setlocale(LC_ALL, "Russian");
        system("chcp 1251");
        std::ifstream fileIn("in.txt");
        if (!fileIn)
        {
            std::cout << "Ошибка открытия файла in.txt." << std::endl;
            return static_cast<int>(codeCommit::InError);
        }
        else
        {
            std::cout << "Файл in.txt успешно открыт." << std::endl;
        }
        int Adresses = 0;
        std::string City = {};
        std::string Street = {};
        int House = 0;
        int Apartment = 0;
        fileIn >> Adresses;
        std::string* array = createTextArr(Adresses);
        for (int i = 0; i < Adresses; i++)
        {
            fileIn >> City >> Street >> House >> Apartment;
            Adress adress(City, Street, House, Apartment);
            array[i] = adress.createAdress();
        };
        fileIn.close();
        printArray(array, Adresses);
        deleteTextArr(array, Adresses);
        std::cout << "Запись произведена в out.txt" << std::endl;
        return 0;
    }
