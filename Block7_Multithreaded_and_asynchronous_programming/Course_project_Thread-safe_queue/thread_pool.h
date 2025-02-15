#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <mutex>
#include "safe_queue.h"

class thread_pool {

private:
	std::atomic_bool done;
	safe_queue<std::function<void()>> workQueue;
	std::vector<std::thread> threadsVector;

public:
	thread_pool(int cores);

	~thread_pool();

	void work();

	template<typename FunctionType>
	void submit(FunctionType f) {
		workQueue.push(std::function<void()>(f));
	}
};