#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>
#include <memory>

int main() {
    Referee referee;
    Human human("Tracy");
    Computer computer;

    const Player* winner = referee.judgeRound(human, computer);

    if (winner == nullptr) {
        std::cout << "It's a Tie." << std::endl;
    } else {
        std::cout << winner->getName() << " Wins." << std::endl;
    }

    return 0;
}