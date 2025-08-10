#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Referee ref;
    Human human("Mei");
    Computer cpu;

    if (auto* winner = ref.refGame(&human, &cpu)) {
        std::cout << winner->getName() << " Wins.\n";
    } else {
        std::cout << "It's a Tie.\n";
    }
    return 0;
}
