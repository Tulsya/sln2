#include <iostream>
#include <vector>
#include <algorithm>


void removeDuplicates(std::vector<int>& vec) {
    
    std::sort(vec.begin(), vec.end());
    
    auto last = std::unique(vec.begin(), vec.end());
    
    vec.erase(last, vec.end());
}

int main() {
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "Before removing duplicates:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    removeDuplicates(vec);

    std::cout << "After removing duplicates:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}

