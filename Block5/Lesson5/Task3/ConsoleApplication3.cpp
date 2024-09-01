#include <iostream>
#include <vector>

class Functor
{
private:
	int _count = 0;
	int _sum = 0;

public:
	Functor();

	void operator()(std::vector<int>& v);
	int getSum();
	int getCount();
};
Functor::Functor() : _sum(0), _count(0) {}

void Functor::operator()(std::vector<int>& v)
{
		for (const int& elem : v)
		{
			if (elem%3 == 0)
			{
				_sum += elem;
				++_count;
			}
		}
	}

int Functor::getSum()
{
	return _sum;
};

int Functor::getCount()
{
	return _count;
};
template<class V>
void print_vector(std::vector<V> vec)
{
	for (int elem : vec)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v = { 4, 1, 3, 6, 25, 54 };
	Functor f;
	f(v);
	std::cout << "[IN]: ";
	print_vector(v);
	std::cout << "[OUT]: get_sum() = " << f.getSum() << std::endl;
	std::cout << "[OUT]: get_count() = " << f.getCount() << std::endl;
	return 0;
}
