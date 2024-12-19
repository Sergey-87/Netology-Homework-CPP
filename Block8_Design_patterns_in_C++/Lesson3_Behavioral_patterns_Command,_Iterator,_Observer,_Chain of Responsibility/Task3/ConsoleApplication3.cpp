#include <iostream>
#include "Log.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    LogMessage log1(Type::Error, "Ошибка!");
    LogMessage log2(Type::Warning, "Внимание!");
    LogMessage log3(Type::Unknown, "Неизвестное сообщение!");
    LogMessage log4(Type::FatalEror, "Фатальная ошибка, программа закрыта!");
    FatalError fatalErrorHandler;
    Error errorHandler("file.txt");
    Warning warningHandler;
    Unknown unknownHandler;
    fatalErrorHandler.setNext(&errorHandler);
    errorHandler.setNext(&warningHandler);
    warningHandler.setNext(&unknownHandler);
    fatalErrorHandler.handleMessage(log1);
    fatalErrorHandler.handleMessage(log2);
    try {
        fatalErrorHandler.handleMessage(log3);
        fatalErrorHandler.handleMessage(log4);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}