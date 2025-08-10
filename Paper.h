#ifndef PAPER_H
#define PAPER_H

#include "Move.h"

class Paper : public Move {
public:
    Paper() : Move("Paper", {"Rock"}) {}
};

#endif
