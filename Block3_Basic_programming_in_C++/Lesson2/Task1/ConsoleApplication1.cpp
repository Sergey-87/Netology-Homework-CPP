#include <iostream>

class Calculator
{
public:
    double num1;
    double num2;
    double add()
    {
        return num1 + num2;
    }
    double multiply()
    {
        return num1 * num2;
    }
    double subtract_1_2()
    {
        return num1 - num2;
    }
    double subtract_2_1()
    {
        return num2 - num1;
    }
    double divide_1_2()
    {
        return num1 / num2;
    }
    double divide_2_1()
    {
        return num2 / num1;
    }
    bool set_num1(double num1)
    {
        do
        {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            this->num1 = num1;
            if (num1 != 0)
            {
                num1 = num1;
                return true;
            }
            else
            {
                std::cout << "Неверный ввод!\n";
            }
        } while (!num1);
    }
    bool set_num2(double num2)
    {
        do {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            this->num2 = num2;
            if (num2 != 0)
            {
                num2 = num2;
                return true;
            }
            else
            {
                std::cout << "Неверный ввод!\n";
            }
        } while (!num2);

    }
};
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    Calculator calculator{};
    calculator.set_num1(calculator.num1);
    calculator.set_num2(calculator.num2);
    std::cout << "num1 + num2 = " << calculator.add() << std::endl;
    std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
    std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
    std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
    return 0;
}
