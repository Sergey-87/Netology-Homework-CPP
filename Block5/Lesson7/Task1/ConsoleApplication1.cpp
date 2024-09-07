#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void unique_vector(std::vector<T>& vec) {
	std::sort(vec.begin(), vec.end());
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
}

template<typename V>
std::ostream& operator<<(std::ostream& out, const std::vector<V>& vec)
{
	for (const auto& value : vec) out << value << " ";
	return out;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	std::cout << "[IN]: " << vec << std::endl;

	unique_vector(vec);

	std::cout << "[OUT]: " << vec << std::endl;
	return 0;
}