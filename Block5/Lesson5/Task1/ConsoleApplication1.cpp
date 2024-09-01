#include <iostream>
#include <vector>

template <class V>
		void square(std::vector<V> vec)
		{
			bool is_first = true;
			for (int elem : vec) {
				if (is_first)
				{
					std::cout << elem * elem;
					is_first = false;
				}
				else std::cout << ", " << elem * elem;
			}
			std::cout << std::endl;
		}
		template <class V>
		void print_vector(std::vector<V> vec)
		{
			bool is_first = true;
			for (int elem : vec) {
				if (is_first)
				{
					std::cout << elem;
					is_first = false;
				}
				else std::cout << ", " << elem;
			}
			std::cout << std::endl;
		}
		template <class O>
	void square(O num)
	{
		std::cout << "[OUT]: " << num * num;
		std::cout << std::endl;
	}

int main()
{
	int num = 4;
	std::cout << "[IN]: " << num;
	std::cout << std::endl;
	square(num);
	std::vector<int> vec = { -1, 4, 8};
	std::cout << "[IN]: ";
	print_vector(vec);
	std::cout << "[OUT]: ";
	square(vec);
	return 0;
}
