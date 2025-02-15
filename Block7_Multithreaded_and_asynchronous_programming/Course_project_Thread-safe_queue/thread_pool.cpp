#include "thread_pool.h"
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>

thread_pool::thread_pool(int cores) {
	done = false;
	size_t const thread_count = std::thread::hardware_concurrency();
	for (size_t i = 0; i < cores; ++i) {
		threadsVector.push_back(
			std::thread(&thread_pool::work, std::move(this)));
	}
}

thread_pool::~thread_pool() {
	done = true;
	for (size_t i = 0; i < threadsVector.size(); ++i) {
		threadsVector[i].join();
	}
}

void thread_pool::work() {
	while (!done) {
		std::function<void()> task;
		if (workQueue.pop(task)) {
			task();
		}
		else {
			std::this_thread::yield();
		}
	}
}