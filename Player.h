#ifndef PLAYER_H
#define PLAYER_H

#include "Move.h"
#include <string>
#include <memory>

class Player {
public:
    virtual ~Player() = default;
    virtual std::unique_ptr<Move> makeMove() = 0;
    virtual std::string getName() const = 0;
};

#endif