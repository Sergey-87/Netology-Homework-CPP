#include <iostream>
#include <set>

int main(int argc, char** argv) {
	int count = 0;
	std::cout << "[IN]: \n";
	std::cin >> count;
	std::set<int, std::greater<int>> setOfValues;

	for (size_t i{ 0 }, v{ 0 }; i < count; ++i)
	{
		std::cin >> v;
		setOfValues.insert(v);
	}

	std::cout << "[OUT]:" << std::endl;
	for (const auto& v : setOfValues)
	{
		std::cout << v << std::endl;
	}
	return 0;
}