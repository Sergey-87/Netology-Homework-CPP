#include <iostream>
#include <vector>

template <class V> 
  void square(std::vector<V>& vec) {
    for (V& elem : vec) {
        elem *= elem;
    }
}
template <class V> 
  void print_vector(std::vector<V>& vec) {
    bool is_first = true;
    for (int elem : vec) {
        if (is_first) {
            std::cout << elem;
            is_first = false;
        }
        else
            std::cout << ", " << elem;
    }
    std::cout << std::endl;
}
template <class O> 
  int square(O num) { 
      return num *= num; 
  }

int main() {
    int num = 4;
    std::cout << "[IN]: " << num;
    std::cout << std::endl;
    std::cout << "[OUT]: " << square(num) << std::endl;
    std::vector<int> vec, x = { -1, 4, 8 };
    vec = x;
    std::cout << "[IN]: ";
    print_vector(vec);
    square(x);
    std::cout << "[OUT]: ";
    print_vector(x);
    return 0;
}
