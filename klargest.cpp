#include <vector>
#include <queue>
#include <functional>

int kth_largest(std::vector<int> values, int k) {
    // min-heap of size k
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int v : values) {
        minHeap.push(v);
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop();
        }
    }

    // assumes k is valid (1 <= k <= values.size())
    return minHeap.top();
}