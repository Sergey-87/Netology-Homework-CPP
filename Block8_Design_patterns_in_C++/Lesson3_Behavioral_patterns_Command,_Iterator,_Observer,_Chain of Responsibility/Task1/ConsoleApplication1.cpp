#include <iostream>
#include "Log.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    ConsoleLogCommand console;
    FileLogCommand file;
    print(console, "Консольное сообщение");
    print(file, "файловое сообщение");
    return 0;
}
