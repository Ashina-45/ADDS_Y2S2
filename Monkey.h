#ifndef MONKEY_H
#define MONKEY_H

#include "Move.h"

class Monkey : public Move {
public:
    // From moropinzee rules: Monkey defeats Robot, Ninja
    Monkey() : Move("Monkey", {"Robot","Ninja"}) {}
};

#endif
