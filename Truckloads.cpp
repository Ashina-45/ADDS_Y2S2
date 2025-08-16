#include "Truckloads.h"

// Recurrence per the TopCoder statement:
// If a pile fits (numCrates <= loadSize) => 1 truck.
// Otherwise split into two piles: floor/ceil halves, and sum the results.
int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1;
    }
    int left  = numCrates / 2;
    int right = numCrates - left; // handles odd split (+1 on one side)
    return numTrucks(left, loadSize) + numTrucks(right, loadSize);
}
