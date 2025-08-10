#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h"
#include <string>

class Player {
public:
    virtual ~Player() = default;
    virtual Move* makeMove() = 0;          // caller (Referee) owns and will delete
    virtual std::string getName() const = 0;
};

#endif
