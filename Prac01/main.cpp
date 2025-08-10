#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Human human("Mei");
    Computer computer;
    Referee ref;

    Player* winner = ref.refGame(&human, &computer);

    if (winner == nullptr) {
        cout << "It's a Tie." << endl;
    } else {
        cout << winner->getName() << " Wins." << endl;
    }

    return 0;
}
