#include "Referee.h"
#include <memory>

Referee::Referee() {}

const Player* Referee::judgeRound(Player& player1, Player& player2) {
    std::unique_ptr<Move> move1 = player1.makeMove();
    std::unique_ptr<Move> move2 = player2.makeMove();

    if (move1->getName() == move2->getName()) {
        return nullptr;
    }

    if (move1->beats(move2.get())) {
        return &player1;
    }
    return &player2;
}