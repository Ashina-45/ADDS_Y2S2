#include <iostream>
#include "Truckloads.h"
#include "EfficientTruckloads.h"
#include "Reverser.h"

using namespace std;

void testTruckloads() {
    Truckloads t;
    cout << "Testing Truckloads:" << endl;
    cout << "numCrates=10, loadSize=2: " << t.numTrucks(10, 2) << endl;
    cout << "numCrates=15, loadSize=3: " << t.numTrucks(15, 3) << endl;
}

void testEfficientTruckloads() {
    EfficientTruckloads et;
    cout << "\nTesting EfficientTruckloads:" << endl;
    cout << "numCrates=10, loadSize=2: " << et.numTrucks(10, 2) << endl;
    cout << "numCrates=15, loadSize=3: " << et.numTrucks(15, 3) << endl;
}

void testReverser() {
    Reverser r;
    cout << "\nTesting Reverser:" << endl;
    cout << "reverseDigit(123): " << r.reverseDigit(123) << endl;
    cout << "reverseDigit(0): " << r.reverseDigit(0) << endl;
    cout << "reverseDigit(-123): " << r.reverseDigit(-123) << endl;
    
    cout << "reverseString(\"Hello\"): " << r.reverseString("Hello") << endl;
    cout << "reverseString(\"\"): " << r.reverseString("") << endl;
}

int main() {
    testTruckloads();
    testEfficientTruckloads();
    testReverser();
    return 0;
}
