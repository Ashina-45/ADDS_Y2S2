#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"
#include <memory>

class Referee {
public:
    Referee();
    const Player* judgeRound(Player& player1, Player& player2);
};

#endif