#pragma once
#include <iostream>
#include <fstream>
#include <vector>
class Observer {
public:
	virtual void onWarning(const std::string& message) {};
	virtual void onError(const std::string& message) {};
	virtual void onFatalError(const std::string& message) {};
	virtual ~Observer() = default;
};
class LogError {
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs) {
		auto it = remove(observers.begin(), observers.end(), obs);
		observers.erase(it, observers.end());
	}
	void warning() {
		for (auto obs : observers) {
			obs->onWarning("Внимание!");
		}
	}
	void error() {
		for (auto obs : observers) {
			obs->onError("Ошибка!");
		}
	}
	void fatalError() {
		for (auto obs : observers) {
			obs->onFatalError("Фатальная ошибка!");
		}
	}
};
class ConsoleObserver : public Observer {
public:
	void onWarning(const std::string& message) override {
		std::cout << "Внимание: " << message << std::endl;
	}
};
class FileObserver : public Observer {
private:
	std::ofstream write;
public:
	FileObserver(const std::string& filename) {
		write.open(filename, std::ofstream::app);
		if (!write.is_open()) {
			std::cout << "Ошибка открытия файла!\n";
		}
	}
	~FileObserver() {
		write.close();
	}
	void onError(const std::string& message) override {
		write << "Ошибка: " << message << std::endl;
	}
};
class FatalObserver : public Observer {
private:
	std::ofstream write;
public:
	FatalObserver(const std::string& filename) {
		write.open(filename, std::ofstream::app);
		if (!write.is_open()) {
			std::cout << "Ошибка открытия файла!\n";
		}
	}
	~FatalObserver() {
		write.close();
	}
	void onError(const std::string& message) override {
		std::cout << "Фатальная ошибка: " << message << std::endl;
		write << "Фатальная ошибка: " << message << std::endl;
	}
};
