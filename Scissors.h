#ifndef SCISSORS_H
#define SCISSORS_H

#include "Move.h"

class Scissors : public Move {
public:
    Scissors() : Move("Scissors", {"Paper"}) {}
};

#endif
