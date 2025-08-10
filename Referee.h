#ifndef REFEREE_H
#define REFEREE_H

#include "Player.h"

class Referee {
public:
    Referee();
    // Returns winner pointer or nullptr for a tie
    Player* refGame(Player* player1, Player* player2);
};

#endif
