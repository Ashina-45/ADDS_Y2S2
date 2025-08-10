#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
public:
    // Zombie defeats Pirate, Monkey
    Zombie() : Move("Zombie", {"Pirate","Monkey"}) {}
};

#endif
