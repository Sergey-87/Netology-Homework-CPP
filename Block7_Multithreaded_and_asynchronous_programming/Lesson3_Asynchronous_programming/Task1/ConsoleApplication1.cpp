#include <iostream>
#include <vector>
#include <random>
#include <future>
#include <algorithm>

//Вывод вектора в консоль
void printVec(const std::vector<int>& vec)
{
	for (const auto& i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

//Поиск минимального элемента
void findMinProm(const std::vector<int> vec, int i, const int vecSize, std::promise<int> prom)
{
	int minIndex = i;
	for (int j = i + 1; j < vecSize; j++)
	{
		if (vec[j] < vec[minIndex])
		{
			minIndex = j;
		}
	}
	prom.set_value(minIndex);
};

int main()
{
	setlocale(LC_ALL, "Russian");
	std::random_device rd;
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> dis(0, 10);
	const std::size_t N = 20;
	std::vector<int> vec(N);
	generate(vec.begin(), vec.end(), [&dis, &gen]() -> int {return dis(gen); });
	int vecSize = vec.size();
	std::cout << "Вектор до сортировки: ";
	printVec(std::ref(vec));
	//Сортировка вектора выбором
	for (int i = 0; i < vecSize - 1; i++)
	{
		std::promise<int> prom;
		std::future<int> future_res = prom.get_future();
		auto asyncFindMin = std::async(std::launch::async, findMinProm, vec, i, vecSize, std::move(prom));
		int minIndex = future_res.get();
		if (vec[i] != vec[minIndex]);
		{
			std::swap(vec[i], vec[minIndex]);
		}
	}
	std::cout << "Вектор после сортировки: ";
	printVec(std::ref(vec));
	//Убираем дублирующие значения вектора
	auto it = unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
	std::cout << "Уникальные значения вектора после сортировки: ";
	printVec(std::ref(vec));
	return 0;
}