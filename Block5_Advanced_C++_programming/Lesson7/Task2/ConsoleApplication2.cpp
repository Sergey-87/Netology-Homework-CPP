#include <iostream>
#include <vector>
#include <set>
#include <list>

template <class P>
void print_container(const P& container)
{
    bool if_one = true;
    for (auto elem = container.cbegin(); elem != container.cend(); ++elem)
    {
        if (if_one)
        {
            std::cout << *elem ;
            if_one = false;
        }
        else
        {
            std::cout << ", " << *elem;
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
    return 0;
}
