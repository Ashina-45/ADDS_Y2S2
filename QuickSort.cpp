#include "QuickSort.h"
#include <utility>

std::vector<int> QuickSort::sort(std::vector<int> list) {
    if (list.size() < 2) return list;
    quicksort(list, 0, static_cast<int>(list.size()) - 1);
    return list;
}

void QuickSort::quicksort(std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int p = partition_with_third_pivot(a, lo, hi);
    quicksort(a, lo, p - 1);
    quicksort(a, p + 1, hi);
}

// Partition using Lomuto scheme but selecting pivot as the 3rd element in the subarray when length >= 3
int QuickSort::partition_with_third_pivot(std::vector<int>& a, int lo, int hi) {
    int len = hi - lo + 1;
    int pivotIndex = (len >= 3) ? (lo + 2) : lo; // third element of the subarray if possible
    int pivotValue = a[pivotIndex];
    std::swap(a[pivotIndex], a[hi]); // move pivot to end

    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if (a[j] <= pivotValue) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[hi]);
    return i + 1;
}
