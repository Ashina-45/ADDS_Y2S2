#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort : public Sort {
public:
    std::vector<int> sort(std::vector<int> list) override;

private:
    void quicksort(std::vector<int>& a, int lo, int hi);
    int partition_with_third_pivot(std::vector<int>& a, int lo, int hi);
};

#endif // QUICKSORT_H
