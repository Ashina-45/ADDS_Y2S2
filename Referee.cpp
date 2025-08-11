#include "Referee.h"

Referee::Referee() {}

const Player* Referee::judgeRound(Player& player1, Player& player2) {
    Move* move1 = player1.makeMove();
    Move* move2 = player2.makeMove();

    const Player* result = nullptr;
    if (move1->getName() == move2->getName()) {
        result = nullptr;
    } else if (move1->beats(move2)) {
        result = &player1;
    } else {
        result = &player2;
    }

    delete move1;
    delete move2;
    return result;
}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    Player* winner = nullptr;
    if (move1->getName() == move2->getName()) {
        winner = nullptr;
    } else if (move1->beats(move2)) {
        winner = player1;
    } else {
        winner = player2;
    }

    delete move1;
    delete move2;
    return winner;
}