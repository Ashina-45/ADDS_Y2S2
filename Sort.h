#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort {
public:
    virtual ~Sort() = default;
    virtual std::vector<int> sort(std::vector<int> list) = 0;
};

#endif // SORT_H