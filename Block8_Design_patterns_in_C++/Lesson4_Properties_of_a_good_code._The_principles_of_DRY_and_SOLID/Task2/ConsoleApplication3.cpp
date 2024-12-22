#include <iostream>
#include <fstream>

enum class Format {
	kText, kHTML, kJSON
};
class Printable {
public:
	virtual ~Printable() = default;
	virtual std::string print() const = 0;
};
class printAsHTML : public Printable {
public:
	virtual ~printAsHTML() = default;
	virtual std::string print() const = 0;
};
class printAsText : public Printable {
public:
	virtual ~printAsText() = default;
	virtual std::string print() const = 0;
};
class printAsJSON : public Printable {
public:
	virtual ~printAsJSON() = default;
	virtual std::string print() const = 0;
};
class DataAsHTML : public printAsHTML {
private:
	std::string data;
	Format format;
public:
	DataAsHTML(std::string data_, Format format_) : data(std::move(data_)), format(format_) {}
	std::string print() const {
		if (format != Format::kHTML) {
			throw std::runtime_error("Invalid format!");
		}
		std::string resultString = "<html>" + data + "<html/>";
		return resultString;
	}
};
class DataAsText : public printAsText {
private:
	std::string data;
	Format format;
public:
	DataAsText(std::string data_, Format format_) : data(std::move(data_)), format(format_) {}
	std::string print() const {
		if (format != Format::kText) {
			throw std::runtime_error("Invalid format!");
		}
		std::string resultString = data;
		return resultString;
	}
};
class DataAsJSON : public printAsJSON {
private:
	std::string data;
	Format format;
public:
	DataAsJSON(std::string data_, Format format_) : data(std::move(data_)), format(format_) {}
	std::string print() const {
		if (format != Format::kJSON) {
			throw std::runtime_error("Invalid format!");
		}
		std::string resultString = "{ \"data\": \"" + data + "\"}";
		return resultString;
	}
};
class SaveTo {
public:
	virtual void save(std::ofstream& file, const Printable* printable) const = 0;
};
class SaveToAsHTML : public SaveTo {
private:
	void saveToAsHTML(std::ofstream& file, const Printable* printable) const {
		file << printable->print();
	}
public:
	void save(std::ofstream& file, const Printable* printable) const override {
		saveToAsHTML(file, printable);
	}
};
class SaveToAsJSON : public SaveTo {
private:
	void saveToAsJSON(std::ofstream& file, const Printable* printable) const {
		file << printable->print();
	}
public:
	void save(std::ofstream& file, const Printable* printable) const override  {
		saveToAsJSON(file, printable);
	}
};
class SaveToAsText : public SaveTo {
private:
	void saveToAsText(std::ofstream& file, const Printable* printable) const {
		file << printable->print();
	}
public:
	void save(std::ofstream& file, const Printable* printable) const override {
		saveToAsText(file, printable);
	}
};
int main() {
	std::ofstream data("data.txt");
	if (data.is_open()) {
		try {
			Printable* dataAsHTML = new DataAsHTML("infoHTML", Format::kHTML);
			SaveToAsHTML SaveHTML;
			SaveHTML.save(data, dataAsHTML);
			data << '\n';
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Printable* dataAsJSON = new DataAsJSON("infoJSON", Format::kJSON);
			SaveToAsJSON SaveJSON;
			SaveJSON.save(data, dataAsJSON);
			data << '\n';
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Printable* dataAsText = new DataAsText("infoText", Format::kText);
			SaveToAsText SaveText;
			SaveText.save(data, dataAsText);
			data << '\n';
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Printable* dataAsHTML = new DataAsJSON("infoText", Format::kText);
			SaveToAsText SaveText;
			SaveText.save(data, dataAsHTML);
			data << '\n';
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	else {
		std::cout << "Can't open file to write!\n";
	}
	data.close();
	return 0;
}