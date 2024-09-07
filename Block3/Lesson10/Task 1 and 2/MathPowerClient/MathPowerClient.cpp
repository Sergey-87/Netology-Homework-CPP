#include <iostream>
#include <windows.h>
#include "MathPower.h"
#include "DynamicMathPower.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string s;
    MathPower::Greeter greeter;
    DynamicMathPower::Leaver leaver;
    greeter.greet(s);
    leaver.leave(s);
    return 0;
}
