#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    memo_.clear();
    return memoRecur(numCrates, loadSize);
}

int EfficientTruckloads::memoRecur(int numCrates, int loadSize) {
    auto key = std::make_pair(numCrates, loadSize);
    auto it = memo_.find(key);
    if (it != memo_.end()) return it->second;

    int ans;
    if (numCrates <= loadSize) {
        ans = 1;
    } else {
        int left  = numCrates / 2;
        int right = numCrates - left;
        ans = memoRecur(left, loadSize) + memoRecur(right, loadSize);
    }

    memo_[key] = ans;
    return ans;
}
