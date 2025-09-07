#include "BubbleSort.h"
#include <utility>

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    if (list.size() < 2) return list;
    bool swapped = true;
    // Standard ascending, stable bubble sort
    for (std::size_t n = list.size(); swapped && n > 1; --n) {
        swapped = false;
        for (std::size_t i = 0; i + 1 < n; ++i) {
            if (list[i] > list[i + 1]) {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
    }
    return list;
}
