#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    // Public interface required by the specification.
    bool search(const std::vector<int>& list, int item);

private:
    bool searchRange(const std::vector<int>& list, int item, int lo, int hi);
};

#endif // RECURSIVEBINARYSEARCH_H
