#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include "safe_queue.h"
#include "thread_pool.h"

using namespace std::chrono_literals;

void f1() {
	std::this_thread::sleep_for(20ms);
	std::cout << "Работает функция: " << __FUNCTION__ << " \n";
}

void f2() {
	std::this_thread::sleep_for(3000ms);
	std::cout << "Работает функция: " << __FUNCTION__ << " \n";
}

int main(int args, char* argv)
{
	setlocale(LC_ALL, "Russian");
	int cores = std::thread::hardware_concurrency() - 1;
	thread_pool tp(cores);
	for (size_t i = 0; i < 5; i++) {
		tp.submit(f1);
		tp.submit(f2);
		std::this_thread::sleep_for(1s);
	}
	return 0;
}
