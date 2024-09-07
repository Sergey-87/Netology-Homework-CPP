#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>

template <class V>
void print_vector(std::vector<V> &vec) {
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
template <class V>
void unique_vector(std::vector<V> &vec) {
    auto it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
}


int main()
{
    std::vector<int> vec, x = { 1, 1, 2, 5, 6, 1, 2, 4 };
    vec = x;
    std::forward_list<int>list = { x.begin(), x.end() };
    std::cout << "[IN]: ";
    print_vector(vec);
    list.sort();
    x = { list.begin(), list.end() };
    unique_vector(x);
    std::cout << "[OUT]: ";
    print_vector(x);
    return 0;
}
