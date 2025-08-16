#ifndef EFFICIENT_TRUCKLOADS_H
#define EFFICIENT_TRUCKLOADS_H

#include <unordered_map>
#include <utility>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);

private:
    // Hash of (numCrates, loadSize) -> result
    struct PairHash {
        std::size_t operator()(const std::pair<int,int>& p) const noexcept {
            // Simple pair hash
            return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
        }
    };

    std::unordered_map<std::pair<int,int>, int, PairHash> memo_;
    int memoRecur(int numCrates, int loadSize);
};

#endif // EFFICIENT_TRUCKLOADS_H
