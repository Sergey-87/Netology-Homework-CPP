#pragma once

#include <string>
#include <vector>

class HTTPclient {

public:

	void performGetRequest(const std::string& host, const std::string& port,
		const std::string& target, int version_in);
	std::string getData();
private:
	std::string lines; // получим HTML одной строкой
	void handleRedirect(const std::string& newLink, const std::string& port, int version);
};