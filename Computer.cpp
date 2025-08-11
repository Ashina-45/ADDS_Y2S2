#include "Computer.h"

#include "Rock.h"

std::unique_ptr<Move> Computer::makeMove() { return std::make_unique<Rock>(); }

std::string Computer::getName() const { return "Computer"; }