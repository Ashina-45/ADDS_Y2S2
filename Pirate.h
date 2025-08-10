#ifndef PIRATE_H
#define PIRATE_H

#include "Move.h"

class Pirate : public Move {
public:
    // Pirate defeats Monkey, Robot
    Pirate() : Move("Pirate", {"Monkey","Robot"}) {}
};

#endif
