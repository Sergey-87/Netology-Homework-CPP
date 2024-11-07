#include <iostream>
#include <thread>
#include <chrono>

int maxClients = 5;
int clientCounter = 0;

void clientThread() {
    while (clientCounter < maxClients)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clientCounter++;
        std::cout << "Новый клиент, текущее число клиентов: " << clientCounter << std::endl;
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (clientCounter > 0)
        {
            clientCounter--;
            std::cout << "Клиент обслужен, осталось клиентов: " << clientCounter << std::endl;
        }
        else
        {
            std::cout << "Оператор выполнил свою работу, осталось клиентов: " << clientCounter << std::endl;
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::thread client(clientThread);
    std::thread operator_(operatorThread);

    client.join();
    operator_.join();

    return 0;
}