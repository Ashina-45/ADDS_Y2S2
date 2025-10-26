#include <cassert>
#include <iostream>
#include "DocumentManager.hpp"

int main() {
    DocumentManager dm;
    dm.addDocument("C++ Primer", 10, 2);
    dm.addDocument("Design Patterns", 11, 1);
    dm.addPatron(101);
    dm.addPatron(102);

    // search
    assert(dm.search("C++ Primer") == 10);
    assert(dm.search("Missing") == 0);

    // borrow success paths
    assert(dm.borrowDocument(10, 101) == true);
    assert(dm.borrowDocument(10, 102) == true);
    assert(dm.borrowDocument(10, 102) == false); 
    assert(dm.borrowDocument(10, 101) == false); 

    // invalid ids
    assert(dm.borrowDocument(999, 101) == false);
    assert(dm.borrowDocument(10, 999) == false);

    // return + borrow again
    dm.returnDocument(10, 101);
    assert(dm.borrowDocument(10, 102) == true);

    // return non-held / invalid is no-op
    dm.returnDocument(11, 101); 
    dm.returnDocument(999, 101);
    dm.returnDocument(11, 999);

    std::cout << "All tests passed.\n";
    return 0;
}
