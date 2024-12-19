#pragma once
#include <iostream>
#include <fstream>

enum class Type {
	Warning,
	Error,
	FatalEror,
	Unknown
};
class LogMessage {
private:
	Type type_;
	std::string text_;
public:
	LogMessage(Type type, const std::string text) : type_(type), text_(text) {}
	Type type()const {
		return type_;
	}
	const std::string& message() const {
		return text_;
	}
};
class LogHandler {
protected:
	LogHandler* nextHandler;
public:
	LogHandler(LogHandler* handler = nullptr) : nextHandler(handler) {};
	virtual ~LogHandler() = default;
	void setNext(LogHandler* handler) {
		nextHandler = handler;
	}
	virtual void handleMessage(const LogMessage& message) = 0;
};
class Warning : public LogHandler {
public:
	void handleMessage(const LogMessage& message) override {
		if (message.type() == Type::Warning) {
			std::cout << "���: " << message.message() << std::endl;
		}
		else {
			nextHandler->handleMessage(message);
		}
	}
};
class Error : public LogHandler {
private:
	std::ofstream write;
public:
	Error(const std::string& filename) {
		write.open(filename, std::ofstream::app);
		if (!(write.is_open())) {
			std::cout << "������ �������� �����!\n";
		}
	}
	~Error() {
		write.close();
	}
	void handleMessage(const LogMessage& message) override {
		if (message.type() == Type::Error) {
			write << "���: " << message.message() << std::endl;
		}
		else {
			nextHandler->handleMessage(message);
		}
	}
};
class FatalError : public LogHandler {
public:
	void handleMessage(const LogMessage& message) override {
		if (message.type() == Type::FatalEror) {
			throw std::runtime_error(message.message());
		}
		else {
			nextHandler->handleMessage(message);
		}
	}
};
class Unknown : public LogHandler {
public:
	void handleMessage(const LogMessage& message) override {
		if (message.type() == Type::Unknown) {
			std::cout << "���: " << message.message() << std::endl;
		}
		else {
			nextHandler->handleMessage(message);
		}
	}
};
