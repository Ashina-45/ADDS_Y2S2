#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    if (!std::getline(std::cin, line)) {
        // No input: by convention print false and exit
        std::cout << "false";
        return 0;
    }

    std::istringstream iss(line);
    std::vector<int> nums;
    int x;
    while (iss >> x) nums.push_back(x);

    QuickSort qs;
    std::vector<int> sorted = qs.sort(nums);

    RecursiveBinarySearch rbs;
    bool hasOne = rbs.search(sorted, 1);

    std::cout << (hasOne ? "true" : "false");

    if (!sorted.empty()) {
        std::cout << ' ';
        for (std::size_t i = 0; i < sorted.size(); ++i) {
            std::cout << sorted[i];
            if (i + 1 < sorted.size()) std::cout << ' ';
        }
    }

    return 0;
}


