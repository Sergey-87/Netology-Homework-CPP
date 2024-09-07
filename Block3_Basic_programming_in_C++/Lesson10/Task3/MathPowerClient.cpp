#include <iostream>
#include <windows.h>
#include "DynamicMathPower.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DynamicMathPower::Leaver leaver;
    std::string s;
    leaver.leave(s);
    return 0;
}
