#ifndef ROCK_H
#define ROCK_H

#include "Move.h"

class Rock : public Move {
public:
    Rock() : Move("Rock", {"Scissors"}) {}
};

#endif
