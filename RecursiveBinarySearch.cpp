#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(const std::vector<int>& list, int item) {
    if (list.empty()) return false;
    return searchRange(list, item, 0, static_cast<int>(list.size()) - 1);
}

bool RecursiveBinarySearch::searchRange(const std::vector<int>& list, int item, int lo, int hi) {
    if (lo > hi) return false;
    int mid = lo + (hi - lo) / 2;
    if (list[mid] == item) return true;
    if (item < list[mid]) {
        return searchRange(list, item, lo, mid - 1);
    } else {
        return searchRange(list, item, mid + 1, hi);
    }
}
