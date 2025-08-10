#ifndef NINJA_H
#define NINJA_H

#include "Move.h"

class Ninja : public Move {
public:
    // Ninja defeats Pirate, Zombie
    Ninja() : Move("Ninja", {"Pirate","Zombie"}) {}
};

#endif
