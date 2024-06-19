#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

class Adress
{
private:
    std::string NameCity_;
    std::string NameStreet_;
    std::string FullAdress_;
    int NumberHouse_;
    int NumberApartment_;
public:
    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
    {
        NameCity_ = NameCity;
        NameStreet_ = NameStreet;
        NumberHouse_ = NumberHouse;
        NumberApartment_ = NumberApartment;
    }
    std::string get_output_adress()
    {
        FullAdress_ = NameCity_ + ", " + NameStreet_ + ", " + std::to_string (NumberHouse_) + ", " + std::to_string (NumberApartment_);
        return FullAdress_;
    }
};

void printtofile(std::string* arrayAdresses, int quantityAdresses)
{
    std::ofstream fout("out.txt");
    if (fout.is_open())
    {
        std::cout << "Файл out.txt успешно открыт!\n";
    }
    else
    {
        std::cout << "Ошибка открытия файла out.txt!\n";
    }
    fout << "Колличество адресов: " << quantityAdresses << std::endl;
    fout << "Адреса: " << std::endl;
    for (int i = 0; i < quantityAdresses; i++)
    {
        fout << i + 1 << ". " << arrayAdresses[i] << std::endl;

    }
    fout.close();
}
void adressesSort(std::string* arrayAdresses, const int quantityAdresses)
{
    bool swapped = false;
    do
    {
        swapped = false;
        std::string tmp;
        for (int i = quantityAdresses - 1; i>0; --i)
            if (arrayAdresses[i - 1] > arrayAdresses[i])
            {
                tmp = arrayAdresses[i - 1];
                arrayAdresses[i - 1] = arrayAdresses[i];
                arrayAdresses[i] = tmp;
                swapped = true;
            }
    } while (swapped);
}
std::string* createTextArray(const int quantityAdresses)
{
    std::string* TextArray = new std::string[quantityAdresses]{};
    return TextArray;
}
void deleteTextArray(std::string* TextArray, const int quantityAdresses)
{
    delete[] TextArray;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::ifstream fin("in.txt");
    if (fin.is_open())
    {
        std::cout << "Файл in.txt успешно открыт!\n";
    }
    else
    {
        std::cout << "Ошибка открытия файла in.txt!\n";
    }
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;
    int quantityAdresses = 0;
    fin >> quantityAdresses;
    std::string* arrayAdresses = createTextArray(quantityAdresses);
    for (int i = 0; i < quantityAdresses; i++)
    {
        fin >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayAdresses[i] = adress.get_output_adress();
    }
    fin.close();
    adressesSort(arrayAdresses, quantityAdresses);
    printtofile(arrayAdresses, quantityAdresses);
    deleteTextArray(arrayAdresses, quantityAdresses);
    std::cout << "Результат смотрите в файле out.txt!\n";
    return 0;
}