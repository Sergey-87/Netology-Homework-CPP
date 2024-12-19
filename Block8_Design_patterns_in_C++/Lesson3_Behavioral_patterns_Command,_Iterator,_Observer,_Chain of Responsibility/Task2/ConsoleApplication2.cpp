#include <iostream>
#include "Error.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    LogError logger;
    ConsoleObserver warning;
    FileObserver error("error.txt");
    FatalObserver fatal("fatal.txt");
    logger.addObserver(&warning);
    logger.addObserver(&error);
    logger.addObserver(&fatal);
    logger.warning();
    logger.error();
    logger.fatalError();
    return 0;
}
