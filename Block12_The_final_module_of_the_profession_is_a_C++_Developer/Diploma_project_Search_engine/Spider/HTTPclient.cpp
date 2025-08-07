#include "HTTPClient.h"
#include "root_certificates.hpp"
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/locale.hpp>
#include <regex>
#include <cstdlib>
#include <iostream>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

void HTTPclient::handleRedirect(const std::string& newLink, const std::string& port, int version) {
	std::string newHost;
	std::string newTarget;
	std::string newPort;
	//Определим тип сервера: http или https
	const std::string http_pref = "http://";
	const std::string https_pref = "https://";
	bool isHTTPS = false;
	bool isHTTP = false;
	if (newLink.compare(0, https_pref.length(), https_pref) == 0) {
		isHTTPS = true;
	}
	else if (newLink.compare(0, http_pref.length(), http_pref) == 0) {
		isHTTP = false;
	}
	else {
		newHost = newLink;
		// Если нет префикса, определяем протокол по текущему порту
		isHTTPS = (port == "443");
		isHTTP = (port == "80");
	}

	// Извлечем порт из URL, если он указан
	size_t portDelimiter = newHost.find(':');
	if (portDelimiter != std::string::npos) {
		newPort = newHost.substr(portDelimiter + 1);
		newHost = newHost.substr(0, portDelimiter);
	}
	else {
		// Если порт не указан, используйте стандартный порт
		if (isHTTPS) {
			newPort = "443";
		}
		else if (isHTTP) {
			newPort = "80";
		}
	}
	std::regex pattern_https(https_pref);
	std::regex pattern_http(http_pref);
	newHost = (isHTTPS) ? std::regex_replace(newLink, pattern_https, "") : std::regex_replace(newLink, pattern_http, "");

	// Разделим адрес на host и target
	//std::cout << "New host: " << newHost << std::endl;
	size_t slashPos = newHost.find("/");
	if (slashPos != std::string::npos) {
		std::string temp_str = newHost;
		newHost = newHost.substr(0, slashPos);

		// Найдем символ "?" в temp_str
		size_t questionMarkPos = temp_str.find("?");
		if (questionMarkPos != std::string::npos) {
			// Если "?" найден, обрежем строку до этого символа
			temp_str = temp_str.substr(0, questionMarkPos);
		}

		newTarget = temp_str.substr(slashPos);
	}
	else {
		newHost = newHost;
		newTarget = "/";
	}
	if (isHTTPS) { newPort = "443"; }
	else { newPort = "80"; }
	/*std::cout << "New host: " << newHost << std::endl;
	std::cout << "New Port: " << newPort << std::endl;
	std::cout << "New target: " << newTarget << std::endl;*/
	performGetRequest(newHost, newPort, newTarget, version);
}

void HTTPclient::performGetRequest(const std::string& host, const std::string& port,
	const std::string& target, int version_in) {

	// Вресия HTML
	int version = version_in;

	// Тип кодировки
	std::string charset;

	// Для хранени результатов ответа сервера перед обработкой
	std::stringstream response_stream;

	net::io_context ioc;
	if (port == "80")
	{
		tcp::resolver resolver(ioc);
		beast::tcp_stream stream(ioc);

		auto const results = resolver.resolve(host, port);

		stream.connect(results);

		http::request<http::string_body> req{ http::verb::get, target, version };
		req.set(http::field::host, host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(stream, req);

		beast::flat_buffer buffer;

		http::response<http::dynamic_body> res;

		http::read(stream, buffer, res);

		// Отработка редиректа
		if (res.result() == http::status::moved_permanently) {
			auto newLocation = res.find(http::field::location);
			if (newLocation != res.end()) {
				// Повторно выполнить запрос по новому адресу
				std::string newLink(newLocation->value());
				std::string newHost;
				std::string newTarget;
				std::string newPort;
				std::cout << "\nNew Location: " << newLink << std::endl;
				handleRedirect(newLink, port, version);
				return;
			}
		}
		// Получение значения заголовка Content-Type для определения типа кодировки
		auto contentTypeHeader = res.find("Content-Type");

		std::string TypeHeaderStr = std::string(contentTypeHeader->value());
		std::regex charsetPattern(R"(charset=([^\s;]+))", std::regex::icase);
		std::sregex_iterator it(TypeHeaderStr.begin(), TypeHeaderStr.end(), charsetPattern);
		std::sregex_iterator end;
		std::smatch match;

		// Определим charset из Content-Type

		if (std::regex_search(TypeHeaderStr, match, charsetPattern)) {
			if (match.size() > 1) {
				charset = match[1];
			}
		}

		response_stream << res;


		beast::error_code ec;
		stream.socket().shutdown(tcp::socket::shutdown_both, ec);

	
		if (ec && ec != beast::errc::not_connected)
		{
			throw beast::system_error{ ec };
		}
	}
	else if (port == "443") {
		net::io_context ioc;

		ssl::context ctx(ssl::context::tlsv12_client);

		load_root_certificates(ctx);

		ctx.set_verify_mode(ssl::verify_none);

		tcp::resolver resolver(ioc);

		beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

		if (!SSL_set_tlsext_host_name(stream.native_handle(), host.c_str()))
		{
			beast::error_code ec{ static_cast<int>(::ERR_get_error()), net::error::get_ssl_category() };
			throw beast::system_error{ ec };
		}

		auto const results = resolver.resolve(host.c_str(), port.c_str());

		beast::get_lowest_layer(stream).connect(results);//<------

		stream.handshake(ssl::stream_base::client);

		http::request<http::string_body> req{ http::verb::get, target, version };
		req.set(http::field::host, host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(stream, req);

		beast::flat_buffer buffer;

		http::response<http::dynamic_body> res;

		http::read(stream, buffer, res);

		// Отработка редиректа
		if (res.result() == http::status::moved_permanently) {
			auto newLocation = res.find(http::field::location);
			if (newLocation != res.end()) {
				// Повторно выполнить запрос по новому адресу
				std::string newLink(newLocation->value());
				std::string newHost;
				std::string newTarget;
				std::string newPort;
				std::cout << "\nNew Location: " << newLink << std::endl;
				handleRedirect(newLink, port, version);
				return;
			}
		}
		// Получение значения заголовка Content-Type для определения типа кодировки
		auto contentTypeHeader = res.find("Content-Type");

		std::string TypeHeaderStr = std::string(contentTypeHeader->value());
		std::regex charsetPattern(R"(charset=([^\s;]+))", std::regex::icase);
		std::sregex_iterator it(TypeHeaderStr.begin(), TypeHeaderStr.end(), charsetPattern);
		std::sregex_iterator end;
		std::smatch match;

		response_stream << res;

		// Определим charset из Content-Type

		if (std::regex_search(TypeHeaderStr, match, charsetPattern)) {
			if (match.size() > 1) {
				charset = match[1];
			}
		}

		beast::error_code ec;
		stream.shutdown(ec);

		if (ec == net::error::eof)
		{
			// Rationale:
			// http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
			ec = {};
		}
		if (ec)
			throw beast::system_error{ ec };
	}
	else {
		throw std::domain_error("\nThis is not HTTP or HTTPS port: " + port + "\n");
	}
	// Составим одну большую строку для всей страницы
	std::string line;
	while (std::getline(response_stream, line)) {
		lines.append(" ");
		lines.append(line);
	}

	// Определим charset из meta tag в случае отсутствия его в Content-Type
	if (charset.length() == 0)
	{
		std::regex charsetPattern_(R"(charset\s*['"]?([^'">\s]+)['"]?\s*[>,;\s*])", std::regex::icase);
		std::smatch match_;
		if (std::regex_search(lines, match_, charsetPattern_)) {
			charset = match_[1];
		}
		else {
			//lines.clear();
			//beast::error_code ec;
			//stream.socket().shutdown(tcp::socket::shutdown_both, ec);
			// Проверено с помощью логиривания, что такая страница плохая, из неё данные не нужно брать
			//throw std::domain_error("\nUndefined charset for page: " + host + target + /*"\n" + lines +*/ "\n" + "-> most likely has been moved\n");
		}
	}

	// Выполним перекодировку
	const std::string UTF8{ "UTF-8" };
	if ((charset.length() != 0) && charset != UTF8)
	{
		std::string utf8_line = boost::locale::conv::between(lines, UTF8, charset);
		lines = std::move(utf8_line);
	}
}
std::string HTTPclient::getData() {

	if (lines.length()) return lines;
}