#include <iostream>
#include "DocumentManager.h"

int main() {
    DocumentManager dm;
    dm.addDocument("C++ Primer", 1, 2);
    dm.addPatron(101);
    dm.addPatron(102);

    std::cout << dm.search("C++ Primer") << "\n";
    std::cout << dm.borrowDocument(1, 101) << "\n";
    std::cout << dm.borrowDocument(1, 102) << "\n";
    std::cout << dm.borrowDocument(1, 101) << "\n";
    dm.returnDocument(1, 101);
    std::cout << dm.borrowDocument(1, 101) << "\n";
}
