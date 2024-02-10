#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <iterator>

template<typename Container>
void print_container(const Container& cont) {
    for (const auto& element : cont) {
        std::cout << element;
        if constexpr (std::is_same_v<Container, std::set<typename Container::value_type>>) {
            if (element != *cont.rbegin()) {
                std::cout << " ";
            }
        }
        else {
            auto last = std::next(cont.end(), -1);
            if (&element != &(*last)) {
                std::cout << ", ";
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);

    return 0;
}

