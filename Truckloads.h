#ifndef TRUCKLOADS_H
#define TRUCKLOADS_H

class Truckloads {
public:
    // Returns number of trucks needed, using the recursive "split in half" plan.
    // Method signature matches the original interface.
    int numTrucks(int numCrates, int loadSize);
};

#endif // TRUCKLOADS_H
