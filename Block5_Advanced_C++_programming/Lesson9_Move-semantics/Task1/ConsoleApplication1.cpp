#include <iostream>
#include <vector>

template <class V>
    void move_vectors(std::vector<V>& one, std::vector<V>& two)
    {
        std::vector<V> temp = std::move(one);
        one = std::move(two);
        two = std::move(temp);
    }
 template <class V>
    void print_vector(std::vector<V>& vec)
    {
        for (std::string elem : vec)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    
int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << "До перемещения:\n";
    std::cout << "one: ";
    print_vector(one);
    std::cout << "two: ";
    print_vector(two);
    std::cout << "_____________________________________\n";
    move_vectors(one, two);
    std::cout << "После перемещения:\n";
    std::cout << "one: ";
    print_vector(one);
    std::cout << "two: ";
    print_vector(two);
}