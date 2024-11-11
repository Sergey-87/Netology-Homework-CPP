#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

int maxClients = 5;
std::atomic<int> clientCounter(0);

void clientThread() {
    while (clientCounter < maxClients)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clientCounter.fetch_add(1, std::memory_order_seq_cst);
        std::cout << "Новый клиент, текущее число клиентов: " << clientCounter << std::endl;
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (clientCounter > 0)
        {
            clientCounter.fetch_sub(1, std::memory_order_seq_cst);
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